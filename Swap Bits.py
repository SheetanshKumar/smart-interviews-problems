# https://www.hackerrank.com/contests/smart-interviews/challenges/si-swap-bits/submissions/code/1318353894

'''Given a number, swap the adjacent bits in the binary representation of the number, and print the new number formed after swapping.

Input Format

First line of input contains T - number of test cases. Each of the next T lines contains a number N.

Constraints

1 <= T <= 100000
0 <= N <= 109

Output Format

For each test case, print the new integer formed after swapping adjacent bits, separated by new line.

Sample Input

4
10
7
43
100

Sample Output

5
11
23
152

Explanation

Test Case 1

Binary Representation of 10: 000...1010
After swapping adjacent bits: 000...0101 (5)

Test Case 2

Binary Representation of 7: 000...0111
After swapping adjacent bits: 000...1011 (11)'''

# solution

_author_ = "sheetansh"
'''
0xAAAAAAAAA represents a 32-bit number whose every even bit is set.
0x55555555 represents a 32-bit number whose every odd bit is set.
doing & operation give even and odd bit respectively then swap the bits by doing right shift and left shift respectively
'''



for _ in range(int(input())):
    n = int(input())
    print((n & 0xAAAAAAAAA) >> 1 | (n & 0x55555555) << 1)