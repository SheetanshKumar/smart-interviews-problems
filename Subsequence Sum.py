# https://www.hackerrank.com/contests/smart-interviews/challenges/si-subsequence-sum/copy-from/1319461759
'''Given a sequence of N numbers: S1, ..., SN, determine how many subsequences of S have a sum between A and B inclusive.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, first line contains - N, A, B separated by space. The next line contains the sequence of N numbers.

Constraints

50 points
1 <= T <= 100
1 <= N <= 15

150 points
1 <= T <= 100
1 <= N <= 30

General Constraints
-107 <= A <= B <= 107
-107 <= S[i] <= 107

Output Format

For each test case, print the result, separated by newline.

Sample Input 0

2
3 -1 2
1 -2 3
5 5 15
1 4 -3 6 4

Sample Output 0

5
20

'''

__author__ = "sheetansh"
__complexity__ = "O(2^(n/2))"
def checkBits(n, k):
    return (n & (1 << (k)))


def generateSubsequence(arr):
    res = []
    for i in range(1 << len(arr)):
        temp = 0
        for j in range(len(arr)):
            if checkBits(i, j):
                temp += arr[j]
        res.append(temp)
    return res


def searchlowerbound(arr, lb):
    low = 0
    high = len(arr)
    while (low < high):
        mid = (high + low) // 2
        if (lb <= arr[mid]):
            high = mid
        else:
            low = mid + 1
    return low


def searchupperbound(arr, ub):
    low = 0
    high = len(subs2)
    while (low < high):
        mid = (high + low) // 2
        if (ub >= arr[mid]):
            low = mid + 1
        else:
            high = mid
    return low


for _ in range(int(input())):
    n, a, b = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    subs1 = generateSubsequence(arr[:(n // 2) + 1])
    subs2 = sorted(generateSubsequence(arr[(n // 2) + 1:]))
    c = 0
    for i in subs1:
        lowerbound = searchlowerbound(subs2, a - i)
        upperbound = searchupperbound(subs2, b - i)
        c += (upperbound - lowerbound)

    print(c)


