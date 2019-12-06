# https://www.hackerrank.com/contests/smart-interviews/challenges/si-rectangular-area-under-histogram

'''Given height of adjacent buildings, find the largest rectangular area possible, where the largest rectangle can be made of a number of contiguous buildings. For simplicity, assume that all buildings have same width and the width is 1 unit.
Note: The sides of rectangle has to be parallel to the axes.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines - the first line contains N - the number of buildings. The second line contains the height of the buildings.

Constraints

50 points
1 <= T <= 100
1 <= N <= 103
1 <= A[i] <= 1000

150 points
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 104

Output Format

For each test case, print the area of the largest possible rectangle, separated by new line.

Sample Input 0

2
7
6 2 5 4 5 1 6
4
5 10 12 4

Sample Output 0

12
20

Explanation 0

Test Case 1

You can form the following rectangles:
6x1 = 6, 2x5 = 10, 5x1 = 5, 4x3 = 12, 5x1 = 5, 1x7 = 7, 6x1 = 6 : max = 12 [axb means rectangle with height a and width b]

Test Case 2

You can form the following rectangles:
5x3 = 15, 10x2 = 20, 12x1 = 12, 4x4 = 16 : max = 20 [axb means rectangle with height a and width b]'''

_author_ = "sheetansh"

t = int(input())

for _ in range(t):
    n = int(input())
    lis = list(map(int, input().split()))
    stack = []
    stack.append(0)
    if (len(lis) == 1):
        print(lis[0])
        continue
    i = 1
    j = 0
    maxArea = lis[0]
    while i < len(lis):
        if not stack or lis[i] >= lis[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            top = stack.pop()
            area = lis[top] * ((i - stack[-1] - 1) if stack else i)
            maxArea = max(area, maxArea)

    while stack:
        top = stack.pop()
        area = lis[top] * ((i - stack[-1] - 1) if stack else i)
        maxArea = max(area, maxArea)
    print(maxArea)