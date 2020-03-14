'''
https://www.hackerrank.com/contests/smart-interviews/challenges/si-number-of-islands/copy-from/1321630055
You are given a 2D matrix consisting of the following:
1: land
0: water
Considering N-8 neighbourhood, your task is to find the number of islands in the given landscape.
Assume that the the 2D matrix is surrounded by water beyond the boundaries.

Definitions:
N-8 neighbourhood: 2 cells are considered neighbours, if they share an edge or a corner.
Island: A piece of connected land surrounded by water.

Input Format

First line of input contains T - number of test cases. The first line of each test case contains R, C - the size of the matrix. Its followed by a matrix of size RxC, consisting only of 0s and 1s.

Constraints

1 <= T <= 100
1 <= R,C <= 500

Output Format

For each test case, print the total number of islands, separated by new line.

Sample Input 0

3
4 8
01001101
10001010
00100100
01101101
6 1
0
1
0
0
1
1
9 5
00000
10001
00110
01100
10000
00000
00101
00011
00110

Sample Output 0

4
2
3

'''

from collections import deque
from sys import stdin, stdout


def issafe(grid, vis, i, j):
    return (i >= 0 and j >= 0 and i < len(grid) and j < len(grid[0]) and grid[i][j] == '1' and vis[i][j] == 0)


def bfs(grid, vis, si, sj):
    r = [-1, -1, -1, 0, 0, 1, 1, 1]
    c = [-1, 0, 1, -1, 1, -1, 0, 1]
    q = deque()
    q.append((si, sj))
    vis[si][sj] = 1

    while (len(q) != 0):
        x = q.pop()
        i = x[0]
        j = x[1]

        for k in range(8):
            if issafe(grid, vis, i + r[k], j + c[k]):
                vis[i + r[k]][j + c[k]] = 1
                q.append((i + r[k], j + c[k]))


def findislands2(grid, r, c):
    ans = 0
    vis = [[0 for i in range(c)] for i in range(r)]
    for i in range(r):
        for j in range(c):
            if (grid[i][j] == '1' and vis[i][j] == 0):
                bfs(grid, vis, i, j)
                ans += 1
    return ans


# for _ in range(int(stdin.readline())):
#     r, c = list(map(int, stdin.readline().split()))
#     grid = []
#     for _ in range(r):
#         grid.append(list(stdin.readline()))
#     stdout.write(str(findislands2(grid, r, c)) + '\n')

def dfs(grid, i, j):
    if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == '0':
        return 0
    grid[i][j] = '0'
    dfs(grid, i + 1, j)
    dfs(grid, i - 1, j)
    dfs(grid, i + 1, j + 1)
    dfs(grid, i - 1, j - 1)
    dfs(grid, i + 1, j - 1)
    dfs(grid, i - 1, j + 1)
    dfs(grid, i, j - 1)
    dfs(grid, i, j + 1)
    return 1


def findislands(grid, r, c):
    ans = 0
    for i in range(r):
        for j in range(c):
            if (grid[i][j] == '1'):
                ans += dfs(grid, i, j)
    return ans


for _ in range(int(input())):
    r, c = list(map(int, input().split()))
    grid = []
    for _ in range(r):
        grid.append(list(input()))
    print(findislands(grid, r, c))

'''3
4 8
01001101
10001010
00100100
01101101
6 1
0
1
0
0
1
1
9 5
00000
10001
00110
01100
10000
00000
00101
00011
00110


4
2
3'''