'''
https://www.interviewbit.com/problems/jump-game-array/
Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Input Format:

The first and the only argument of input will be an integer array A.

Output Format:

Return an integer, representing the answer as described in the problem statement.
    => 0 : If you cannot reach the last index.
    => 1 : If you can reach the last index.

Constraints:
1 <= len(A) <= 1e6
0 <= A[i] <= 30

Examples:

Input 1:
    A = [2,3,1,1,4]

Output 1:
    1

Explanation 1:
    Index 0 -> Index 2 -> Index 3 -> Index 4 -> Index 5

Input 2:
    A = [3,2,1,0,4]

Output 2:
    0

Explanation 2:
    There is no possible path to reach the last index.

'''


class Solution:
    # @param A : list of integers
    # @return an integer
    def canJump(self, arr):
        dp = [0] * (len(arr) + 1)

        dp[0] = 1

        for i in range(len(arr)):
            if dp[i] != 0:
                jump = arr[i]
                for j in range(jump + 1):
                    if (i + j < len(arr)):
                        dp[i + j] = 1
                    else:
                        break
                if dp[len(arr) - 1]:
                    return dp[len(arr) - 1]
        return dp[len(arr) - 1]