#include<bits/stdc++.h>
using namespace std;


// my try - dfs based : accpeted
class Solution {
public:
    int cnt = 0;

    void dfs(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& vis, int i, int j) {

        vis[i][j] = 1;
        cnt++;

        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {

            int ni = i + di[k];
            int nj = j + dj[k]; 

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && vis[ni][nj] == 0 && grid[ni][nj] == 1) {
                dfs(grid, m, n, vis, ni, nj);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        // i=0
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                cnt = 0;
                dfs(grid, m, n, vis, 0, j);
                count += cnt;
            }
        }

        // i=1 to m-2 { j=0 nad n-1}
        for (int i = 1; i < m - 1; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                cnt = 0;
                dfs(grid, m, n, vis, i, 0);
                count += cnt;
            }
            if (!vis[i][n - 1] && grid[i][n - 1] == 1) {
                cnt = 0;
                dfs(grid, m, n, vis, i, n - 1);
                count += cnt;
            }
        }

        // i=m-1
        for (int j = 0; j < n; j++) {
            if (!vis[m - 1][j] && grid[m - 1][j] == 1) {
                cnt = 0;
                dfs(grid, m, n, vis, m - 1, j);
                count += cnt;
            }
        }

        int total=0;

        for ( int i=0 ; i<m ; i++ ) {
            for ( int j=0 ; j<n ; j++ ) {
                if ( grid[i][j] ) total++;
            }
        }

        return total-count;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's bfs based solution : 

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // first row, first col, last row, last col
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverses all 4 directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};