# https://www.interviewbit.com/problems/implement-power-function/

'''
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
'''

class Solution:
    def pow(self, x, n, d):
        def aPowerb(a, b):
            if (b==0):
                return 1
            store = aPowerb(a, b//2)
            if(b %2 == 0):
                return ((store%d)*(store%d))%d
            else:
                return (a*((store%d)*(store%d))%d)%d
        flag = 1
        if(x < 0 and n%2!=0):
            flag = -1
        return((flag*aPowerb(abs(x),n))%d)