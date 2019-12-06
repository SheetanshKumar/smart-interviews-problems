# https://www.hackerrank.com/contests/smart-interviews/challenges/si-frequency-sort

'''
You are given an array of integers. Sort them by frequency. See examples for more clarifications.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.

Constraints

1 <= T <= 100
1 <= N <= 10000
-1000 <= A[i] <= 1000

Output Format

For each test case, print the elements of the array sorted by frequency. In case 2 elements have the same frequency, print the smaller element first.

Sample Input 0

2
6
4 -2 10 12 -8 4
8
176 -272 -272 -45 269 -327 -945 176

Sample Output 0

-8 -2 10 12 4 4
-945 -327 -45 269 -272 -272 176 176


'''

_author_ = "sheetansh"

from collections import Counter
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    dic = Counter(arr)
    def count(val1):
        return dic[val1]
    arr.sort(key=count)
    print(*arr)
