# https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-factorial/copy-from/1321004056

'''Given a number N, print N!.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each containing a single number N.

Constraints

1 <= T <= 1000000
0 <= N <= 1000000

Output Format

For each test case, print N!. Since the result can be very large, print N! % 1e9+7.

Sample Input 0

3
5
20
50

Sample Output 0

120
146326063
318608048

'''


from sys import stdin, stdout

dp = [0] * (1000000 + 1)
def fact(n):
    if (n >= 0):
        dp[0] = 1;
        for i in range(1, n + 1):
            dp[i] = (i * dp[i - 1]) % 1000000007;
fact(1000000)
# print(dp)
for _ in range(int(input())):
    n = int(stdin.readline())
    stdout.write(str(dp[n]) + '\n')
