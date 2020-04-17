'''
https://www.interviewbit.com/problems/edit-distance/
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:

Return an integer, representing the minimum number of steps required.

Constraints:

1 <= length(A), length(B) <= 450

Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.

'''


def minDistance(self, A, B):
    dp = [[0 for i in range(len(A) + 1)] for j in range(len(B) + 1)]

    for i in range(len(A) + 1):
        dp[0][i] = i
    for i in range(len(B) + 1):
        dp[i][0] = i

    for i in range(1, len(B) + 1):
        for j in range(1, len(A) + 1):
            if B[i - 1] == A[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
    # for i in dp:
    #     print(*i)
    return dp[len(B)][len(A)]