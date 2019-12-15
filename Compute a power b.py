# https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-a-power-b

'''Given 2 numbers - a and b, evaluate ab.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing 2 numbers - a and b, separated by space.

Constraints

30 points
1 <= T <= 1000
0 <= a <= 106
0 <= b <= 103

70 points
1 <= T <= 1000
0 <= a <= 106
0 <= b <= 109

Output Format

For each test case, print ab, separated by new line. Since the result can be very large, print result % 1000000007

Sample Input 0

4
5 2
1 10
2 30
10 10

Sample Output 0

25
1
73741817
999999937

'''

_author_ = "sheetansh"

def aPowerb(a, b):
    if (b==0):
        return 1
    store = aPowerb(a, b//2)
    if(b %2 == 0):
        return ((store%1000000007)*(store%1000000007))%1000000007
    else:
        return (a*((store%1000000007)*(store%1000000007))%1000000007)%1000000007

t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    print(aPowerb(l[0], l[1])%1000000007)