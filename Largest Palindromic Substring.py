# https://www.hackerrank.com/contests/smart-interviews/challenges/si-largest-palindromic-substring/copy-from/1319224216
'''Given a string, find the length of the largest palindromic substring.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. The first line contains N - the size of the string and the second line contains a string of size N, containing only lowercase english alphabets.

Constraints

30 points
1 <= T <= 200
1 <= len(S) <= 102
'a' <= S[i] <= 'z'

70 points
1 <= T <= 200
1 <= len(S) <= 103
'a' <= S[i] <= 'z'

Output Format

For each test case, print the length of the largest palindromic substring, separated by newline.

Sample Input 0

5
8
pfyafafd
9
sllwffoqq
6
yoogvb
4
hcch
23
mzmqnnrkurfmmfrukrnnqsm

Sample Output 0

3
2
2
4
18

'''

__author__ = "sheetansh"


def checkPL(arr, n):
    ans = 0
    for i in range(n):
        c1 = i
        k = 1
        while ((c1 - k) >= 0 and (c1 + k) < n and arr[c1 - k] == arr[c1 + k]):
            k += 1
        ans = max(ans, 2 * k - 1)

        c2 = i + 1
        c1 = i
        if (i + 1 < n and arr[c1] == arr[c2]):
            k = 1
        else:
            continue
        while (c1 - k >= 0 and c2 + k < n and arr[c1 - k] == arr[c2 + k]):
            k += 1

        ans = max(ans, 2 * k)
        # print(arr[c1+1:c2+1])
    return ans


for _ in range(int(input())):
    n = int(input())
    arr = input()
    print(checkPL(arr, n))