class Solution:
    def solve(A):
        A.sort()
        for i in range(len(A) - 1):
            if A[i] == A[i + 1]:
                continue
            if A[i] == len(A) - i - 1:
                return 1
        if (A[-1] == 0):
            return 1
        return -1

