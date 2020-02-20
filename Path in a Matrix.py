# https://www.hackerrank.com/contests/smart-interviews/challenges/si-path-in-a-matrix/copy-from/1321037246

'''Given a matrix, find the number of ways to reach from the top-left cell to the right-bottom cell. At any step, from the current cell (i,j) you can either move to (i+1,j) or (i,j+1) or (i+1, j+1). Please note that certain cells are forbidden and cannot be used.

Input Format

First line of input contains T - number of test cases. First line of each test case contains N, M - size of the matrix and B - number of forbidden cells. Its followed by B lines each containing a pair (i,j) - index of the forbidden cell.

Constraints

20 points
1 <= N, M <= 10

80 points
1 <= N, M <= 100

General Constraints
1 <= T <= 500
0 <= i < N
0 <= j < M

Output Format

For each test case, print the number of ways, separated by newline. Since the output can be very large, print output % 1000000007

Sample Input 0

5
5 2 1
2 0
7 3 1
1 0
6 3 1
5 2
2 9 1
0 1
5 6 2
0 1
1 0

Sample Output 0

4
24
0
2
129

'''


__author__ = "sheetansh"

def getWays(arr):
    if(arr[0][0] == 0):
        return 0
    c = 1
    dp = [[0 for x in range(len(arr[0]))] for x in range(len(arr))]
    dp[0][0] = 1
    for i in range(1, len(arr[0])):
        if (arr[0][i] == 0):
            break
        dp[0][i] = 1
    for i in range(1, len(arr)):
        if (arr[i][0] == 0):
            break
        dp[i][0] = 1
    for r in range(1, len(arr)):
        for c in range(1, len(arr[0])):
            if(arr[r][c] != 0):
                dp[r][c] = (dp[r-1][c-1]+dp[r-1][c]+dp[r][c-1])%1000000007
    return dp[len(arr)-1][len(arr[0])-1]
for _ in range(int(input())):
    r,c,b = list(map(int, input().split()))
    arr = [[1 for x in range(c)] for x in range(r)]
    for _ in range(b):
        i, j = list(map(int, input().split()))
        arr[i][j] = 0
    print(getWays(arr))