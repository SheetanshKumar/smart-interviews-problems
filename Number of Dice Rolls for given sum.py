# https://www.hackerrank.com/contests/smart-interviews/challenges/si-number-of-dice-rolls-for-given-sum/copy-from/1320859090


'''Given a standard 6-sided dice, find the number of ways to get a sum of N.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains N - the desired sum.

Constraints

1 <= T <= 100000
1 <= N <= 100000

Output Format

For each test case, print the number of ways to get a sum of N, separated by newline. Since the answer can be very large, print answer % 1e9+7.

Sample Input 0

5
3
11
7
5
500

Sample Output 0

4
976
63
16
765996555

Explanation 0

Test Case 1
You can get a sum of 3 in the ways:
(1,1,1), (1,2), (2,1), (3)'''

__author__ = "sheetansh"

from sys import stdin, stdout


def precompute(n):
    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        res = 0
        for j in range(1, 7):
            if (i - j) >= 0:
                res += dp[i - j]
        dp[i] = res % int(1e9 + 7)
    return dp


dp = precompute(100000)
for _ in range(int(input())):
    n = int(stdin.readline())
    stdout.write(str(dp[n]) + '\n')