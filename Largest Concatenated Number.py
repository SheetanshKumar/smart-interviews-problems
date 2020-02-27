# https://www.hackerrank.com/contests/smart-interviews/challenges/si-largest-concatenated-number/copy-from/1321284579

'''Given an array of integers, find the largest number that can be constructed by concatenating all the elements of the given array.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - size of the array and the second line contains N integers - elements of the array.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 1000

Output Format

For each test case, print the largest number that can be constructed by concatenating all the elements of the given array, separated by newline.

Sample Input 0

3
8
49 73 58 30 72 44 78 23
4
69 9 57 60
2
40 4

Sample Output 0

7873725849443023
9696057
440

'''


def findLargestNumber(arr):
    l = len(str(max(arr))) + 1
    ans = ""
    a = []
    for i in arr:
        a.append(((str(i) * l)[:l], i))

    a.sort(reverse=True)
    for i in a:
        ans += str(i[1])
    return ans


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(findLargestNumber(arr))
