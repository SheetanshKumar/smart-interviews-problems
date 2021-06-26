// https://leetcode.com/problems/number-of-closed-islands/

/* 
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

class Solution {
public:
    
    bool isSafe(vector<vector<int>>& grid, int m, int n, int x, int y, vector<vector<bool>>& vis) {
        return x < m && x >=0 && y < n && y >= 0 && grid[x][y] == 0 && vis[x][y] == false;
    }
    
    int bfs(vector<vector<int>>& grid, int r, int c) {
        
        int m = grid.size(), n = grid[0].size();
        int ans = 1;
        if (r == m-1 || r == 0 || c == 0 || c == n-1)
            ans = 0;
        
        queue<pair<int, int>> q;
        q.push({r, c});
        
        
        vector<vector<bool>> vis(m+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                vis[i].push_back(false);
        }
        while(!q.empty()) {
            
            pair<int, int> cloc = q.front();
            q.pop();

            int arrx[] = {0, 0, 1, -1};
            int arry[] = {1, -1, 0, 0};


            for(int j = 0; j < 4; j++) {
                int a = cloc.first + arrx[j];
                int b = cloc.second +arry[j];

                if (isSafe(grid, m, n, a, b, vis)) {
                    grid[a][b] = 1;
                    vis[a][b] = true;
                    if (a == m-1 || a == 0 || b == 0 || b == n-1)
                        ans = 0;
                    q.push({a, b});
                    // printMatrix(grid);
                }
            }
            
        }
        return ans;
    }
    
    void printMatrix(vector<vector<int>>& grid ) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                cout<< grid[i][j] << " ";
            }
            cout <<  endl;
        }
        cout << endl;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (grid[i][j] == 0)
                {
                    ans+= bfs(grid, i, j);
                    
                }
            }
        }
        return ans;
    }
};