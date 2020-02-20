# https://www.hackerrank.com/contests/smart-interviews/challenges/si-collect-apples/copy-from/1321034967

'''You are given a maze containing cells. Each cell has certain number of apples. You have to start from the top-left position and traverse all the way to the bottom-right position, collecting apples on your way. You can move only in right and downward direction,ie, from any cell (i,j) you can only move right: (i,j+1) or down: (i+1,j). Find the maximum number of apples you can collect.

Input Format

First line of input contains T - number of test cases. First line of each test case contains N and M - the size of the maze. Its followed by N lines, each containing M integers indicating the number of apples in the cell.

Constraints

1 <= T <= 100
1 <= N,M <= 300
0 <= Aij <= 100

Output Format

For each test case, print the maximum number of apples you can collect, separated by newline.

Sample Input 0

2
3 4
1 5 1 4
10 11 0 13
4 15 1 12
4 2
4 5
1 3
10 5
1 0

Sample Output 0

50
20

Explanation 0

Test Case 1
The path using which you can collect maximum apples is:
Total Apples = 1 + 10 + 11 + 15 + 1 + 12 = 50

Test Case 2
The path using which you can collect maximum apples is:
Total Apples = 4 + 1 + 10 + 5 + 0 = 20 '''

__author__ = "sheetansh"

def findPathsMax(arr):
    dp = [[0 for x in range(len(arr[0])+1)] for x in range(len(arr)+1)]
    dp[0][0] = arr[0][0]
    for i in range(1, len(arr[0])):
        dp[0][i] = dp[0][i-1]+arr[0][i]
    for i in range(1, len(arr)):
        dp[i][0] = dp[i-1][0]+arr[i][0]
    for r in range(len(arr)):
        for c in range(len(arr[0])):
            dp[r][c] = max(dp[r-1][c], dp[r][c-1]) + arr[r][c]
    return dp[len(arr)-1][len(arr[0])-1]


for _ in range(int(input())):
    r, c = list(map(int, input().split()))
    arr = []
    for _ in range(r):
        arr.append(list(map(int, input().split())))
    print(findPathsMax(arr))