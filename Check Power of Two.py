# https://www.hackerrank.com/contests/smart-interviews/challenges/si-check-power-of-two/
'''Given a number, check if it is a power of 2.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing a single positive integer.

Constraints

1 <= T <= 10000
1 <= N <= 1018

Output Format

For each test case, print "True" or "False", separated by new line.

Sample Input 0

5
1
8
10
25
512

Sample Output 0

True
True
False
False
True

'''

_author_ = "sheetansh"

for _ in range(int(input())):
    n = int(input())
    print(n and (n & (n-1)) == 0)