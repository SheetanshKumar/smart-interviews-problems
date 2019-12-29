# https://www.interviewbit.com/problems/square-root-of-integer/

'''Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.

Output Format

Return floor(sqrt(A))

Constraints

1 <= A <= 10^9

For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3

'''

class Solution:
    # @param A : integer
    # @return an integer
    def sqrt(self, A):
        low, high = 0, A
        mid = 0
        res = A
        while(low<=high):
            mid = (high+low)//2
            x = (mid%1000000007)*(mid%1000000007)
            if(x == A):
                return mid
            elif(x > A):
                high = mid - 1
                res = high
            else:
                res = low
                low = mid + 1
        return res