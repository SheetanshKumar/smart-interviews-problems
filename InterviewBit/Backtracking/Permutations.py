'''

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

    NOTE

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
    Example : next_permutations in C++ / itertools.permutations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points.

'''


def permute(self, A):
    n = len(A)
    for i in range(0, n):
        A[i] = str(A[i])
    result = []
    self.perm(A, 0, n - 1, result)
    return result


def perm(self, A, l, r, result):
    if (l == r):
        result.append("".join(A))
    for i in range(l, r + 1):
        A[l], A[i] = A[i], A[l]
        self.perm(A, l + 1, r, result)
        A[l], A[i] = A[i], A[l]