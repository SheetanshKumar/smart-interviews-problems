# https://www.hackerrank.com/contests/smart-interviews/challenges/si-triplet-with-sum-k

'''
You are given an integer array and a number K. You have to tell if there exists i,j,k in the given array such that ar[i]+ar[j]+ar[k]=K, i≠j≠k.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N and K - the size of the array and the number K. The second line contains the elements of the array.

Constraints

30 points
1 <= T <= 100
3 <= N <= 100

70 points
1 <= T <= 100
3 <= N <= 1000

General
-100000 <= A[i] <= 100000
0 <= K <= 100000

Output Format

For each test case, print "true" if the arrays contains such elements, false otherwise, separated by new line.

Sample Input 0

3
5 60
1 20 40 100 80
12 54
12 45 52 65 21 645 234 -100 14 575 -80 112
3 15
5 5 5

Sample Output 0

false
true
true


'''


_author_ = "sheetansh"

def isTripletSum(arr, k):
    arr.sort()

    for i in range(0, len(arr) - 2):
        l = i + 1
        r = len(arr) - 1
        while (l < r):
            if (arr[i] + arr[l] + arr[r] == k):
                return True
            elif arr[i] + arr[l] + arr[r] < k:
                l += 1
            else:
                r -= 1
    return False


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(str(isTripletSum(arr, k)).lower())