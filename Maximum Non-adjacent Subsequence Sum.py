'''Given an array of integers, find the maximum subsequence sum, such that no 2 elements of the subsequence are adjacent to each other. Note that you cannot select an empty subsequence.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - size of the array and the second line contains N integers - elements of the array.

Constraints

1 <= T <= 1000
1 <= N <= 10000
-1000 <= ar[i] <= 1000

Output Format

For each test case, print the maximum subsequence sum, separated by newline.

Sample Input 0

4
8
-24 28 28 55 -31 -27 -45 -24
11
40 5 39 45 31 -99 -44 73 -16 -31 27
7
57 18 -14 17 31 16 -16
2
26 61

Sample Output 0

83
210
90
61

'''

def maxSubsetSum(arr):
    dp = [(-1<<31) for i in range(len(arr)+1)]
    dp[0] = arr[0]
    if(len(arr) ==1):
        return dp[0]
    for i in range(1, len(arr)):
        dp[i] = max(max(arr[i]+ dp[i-2], dp[i-1]), arr[i])
    # print(dp)
    return max(dp[len(arr)-1], dp[len(arr)-2])

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(maxSubsetSum(arr))