# Given a positive integer, print its binary representation.
#
# Input Format
#
# First line of input contains T - number of test cases. Its followed by T lines, each line containing a single integer.
#
# Constraints
#
# 1 <= T <= 10000
# 0 <= N <= 109
#
# Output Format
#
# For each test case, print binary representation, separated by new line.
#
# Sample Input 0
#
# 5
# 10
# 15
# 7
# 1
# 120
#
# Sample Output 0
#
# 1010
# 1111
# 111
# 1
# 1111000



t = int(input())
for _ in range(t):
    print(bin(int(input()))[2:])