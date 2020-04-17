'''
https://www.interviewbit.com/problems/min-sum-path-in-matrix/
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

Example :

Input :

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1

'''


def minPathSum(self, arr):
    dp = [[0 for i in range(len(arr[0]))] for j in range(len(arr))]
    dp[0][0] = arr[0][0]
    for i in range(1, len(arr)):
        dp[i][0] = dp[i - 1][0] + arr[i][0]
    for i in range(1, len(arr[0])):
        dp[0][i] = dp[0][i - 1] + arr[0][i]

    for i in range(1, len(arr)):
        for j in range(1, len(arr[0])):
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j]

    return dp[len(arr) - 1][len(arr[0]) - 1]