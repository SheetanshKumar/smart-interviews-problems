/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-number-of-islands

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

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool issafe(vector<string>& arr, vector<vector<bool>>& vis, int i, int j) {
    return (i >= 0 && j >= 0 && i < arr.size() && j < arr[0].size() && arr[i][j] == '1' && vis[i][j] == false);
}


void bfs(vector<string>& arr, vector<vector<bool>>& vis, int x, int y) {

    int r[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int c[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++) {
            if (issafe(arr, vis, i + r[k], j + c[k])) {
                vis[i + r[k]][j + c[k]] = true;
                q.push(make_pair(i + r[k], j + c[k]));
            }
        }
    }
}

int findislands(vector<string> &arr, int r, int c) {
    int ans = 0;
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == '1' && vis[i][j] == false)
            {
                bfs(arr, vis, i, j);
                ans += 1;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        vector<string> arr;
        for (int j = 0; j < r; j++)
        {
            string s;
            cin >> s;
            arr.push_back(s);
        }
        cout << findislands(arr, r, c) << endl;
    }
}