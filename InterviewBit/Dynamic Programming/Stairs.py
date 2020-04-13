'''
https://www.interviewbit.com/problems/stairs/

You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Input Format:

The first and the only argument contains an integer A, the number of steps.

Output Format:

Return an integer, representing the number of ways to reach the top.

Constrains:

1 <= A <= 36

Example :

Input 1:

A = 2 Output 1:

2 Explanation 1:

[1, 1], [2] Input 2:

A = 3 Output 2:

3 Explanation 2:

[1 1 1], [1 2], [2 1]


'''

class Solution:
    # @param A : integer
    # @return an integer
    def climbStairs(self, n):
        dp = [0 for i in range(n+1)]
        dp[0] = 1
        dp[1] = 1
        if n == 1:
            return 1
        if n == 0:
            return 0
        dp[2] = 2
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]