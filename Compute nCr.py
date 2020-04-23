'''
https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-ncr/copy-from/1321002922

Given n and r, compute nCr.
Do not use BigInteger class, it defeats the purpose of the problem statement.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 integers - N and R.

Constraints

20 points
1 <= T <= 100
0 <= N, R <= 30

80 points
1 <= T <= 500000
0 <= N, R <= 2000

Output Format

For each test case, print the value of nCr, separated by newline. Since the number can be very large, print result % 1000000007.

Sample Input 0

5
4 2
3 1
25 12
30 14
6 4

Sample Output 0

6
3
5200300
145422675
15

'''

from sys import stdin, stdout
def nCr(n, r):
    dp = [[0 for x in range(r + 1)] for x in range(n + 1)]
    for i in range(n+1):
        for j in range(min(i, r) + 1):
            if j == 0 or j == i:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]% 1000000007
    # print(dp)
    return dp

sol = nCr(2000, 2000)
for _ in range(int(input())):
    n, r = list(map(int, stdin.readline().split()))
    stdout.write(str(sol[n][r]% 1000000007)+'\n')