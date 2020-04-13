'''
https://www.interviewbit.com/problems/min-jumps-array/
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

Input Format:

The first and the only argument contains an integer array, A.

Output Format:

Return an integer, representing the answer as described in the problem statement.

Constraints:

1 <= N <= 1e6
0 <= A[i] <= 50000

Examples:

Input 1:
    A = [2, 1, 1]

Output 1:
    1

Explanation 1:
    The shortest way to reach index 2 is
        Index 0 -> Index 2
    that requires only 1 jump.

Input 2:
    A = [2,3,1,1,4]

Output 2:
    2

Explanation 2:
    The shortest way to reach index 4 is
        Index 0 -> Index 1 -> Index 4
    that requires 2 jumps.

'''


def jump(self, arr):
    n = len(arr)
    dp = [0] * (n + 1)
    if (n == 1 and arr[0] == 0):
        return 0
    idx = 0
    i = 1
    while i < n and idx < i:
        if idx + arr[idx] >= i:
            dp[i] = dp[idx] + 1
            i += 1
        else:
            idx += 1
    if dp[n - 1] == 0:
        return -1
    return dp[n - 1]