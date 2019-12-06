# https://www.hackerrank.com/contests/smart-interviews/challenges/si-trailing-zeros
#
# Count the number of trailing 0s in factorial of a given number.
#
# Input Format
#
# First line of input contains T - number of test cases. Its followed by T lines, each containing an integer N.
#
# Constraints
#
# 1 <= T <= 10000
# 1 <= N <= 1015
#
# Output Format
#
# For each test case, print the number of trailing 0s in N!, separated by new line.
#
# Sample Input 0
#
# 3
# 2
# 5
# 20
#
# Sample Output 0
#
# 0
# 1
# 4
#
# Explanation 0
#
# Self Explanatory

# solution:

_author_ = "sheetansh"

t = int(input())
for _ in range(t):
    n = int(input())
    i = 5
    count = 0
    while(n/i >= 1):
        count+=int(n/i)
        i*=5
    print(count)