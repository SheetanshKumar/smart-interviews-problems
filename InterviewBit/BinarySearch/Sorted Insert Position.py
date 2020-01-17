# https://www.interviewbit.com/problems/sorted-insert-position/

'''

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

'''


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def searchInsert(self, A, B):
        low = 0
        high = len(A) - 1
        mid = 0
        while (low <= high):
            mid = (low + high) // 2

            if (A[mid] == B):
                return mid
            elif (A[mid] > B):
                high = mid - 1
            else:
                low = mid + 1
        return low