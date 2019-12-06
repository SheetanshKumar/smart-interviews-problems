# https://www.hackerrank.com/contests/smart-interviews/challenges/si-print-hollow-diamond-pattern
# Print hollow diamond pattern using '*'. See examples for more details.
#
# Input Format
#
# First line of input contains T - number of test cases. Its followed by T lines, each line contains a single odd integer N - the size of the diamond.
#
# Constraints
#
# 1 <= T <= 100
# 3 <= N <= 201
#
# Output Format
#
# For each test case, print the test case number as shown, followed by the diamond pattern, separated by newline.
#
# Sample Input 0
#
# 4
# 3
# 7
# 5
# 15
#
# Sample Output 0
#
# Case #1:
#  *
# * *
#  *
# Case #2:
#    *
#   * *
#  *   *
# *     *
#  *   *
#   * *
#    *
# Case #3:
#   *
#  * *
# *   *
#  * *
#   *
# Case #4:
#        *
#       * *
#      *   *
#     *     *
#    *       *
#   *         *
#  *           *
# *             *
#  *           *
#   *         *
#    *       *
#     *     *
#      *   *
#       * *
#        *
#

# Solution
_author_ = "sheetansh"

for p in range(int(input())):
    n = int(input())
    y = n//2 + 1
    x = n//2 - 1
    i = 0
    print("Case #{}:".format(p+1))
    while(y <= n and x >= 0):
        if(i == 0):
            print(' '* (n//2)+'*')
        else:
            # print(y-x, y, x)
            print(' '*(x)+'*' + ' '*(y-x-1) + '*')
            y+=1
            x-=1
        i+=1

    x+=1
    y-=1
    i+=1
    while(x <= (n//2)-1 and y >= (n//2)+1) and i<=n:
        if(i == n):
            print(' '* (n//2)+'*')
        else:
            y-=1
            x+=1
            print(' '*(x)+'*' + ' '*(y-x-1) + '*')
        i+=1