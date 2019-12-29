# https://www.hackerrank.com/contests/smart-interviews/challenges/si-lcm-and-hcf/submissions/code/1318729785

'''Given 2 numbers, find their LCM and HCF.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each contains 2 numbers A and B.

Constraints

1 <= T <= 105
1 <= A,B <= 109

Output Format

For each test case, print their LCM and HCF separated by space, separated by newline.

Sample Input 0

4
4 710
13 1
6 4
605904 996510762

Sample Output 0

1420 2
13 1
12 2
7740895599216 78

'''

def hcf(a, b):
    if(a == 0):
        return b
    return hcf(b%a, a)

def lcm(a, b):
    return int(a*b)//hcf(a,b)

for _ in range(int(input())):
    a, b = list(map(int, input().split()))
    print("{} {}".format(lcm(a,b),hcf(a,b)))

