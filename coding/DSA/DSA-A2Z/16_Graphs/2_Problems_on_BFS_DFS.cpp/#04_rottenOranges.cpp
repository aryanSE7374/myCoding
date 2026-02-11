#include <bits/stdc++.h>
using namespace std;

// brute force- try (failed)

class Solution {
public:
    int bfs(vector<vector<int>> grid, int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,int>> q;
        q.push({row, col});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int cnt = 0;
        vis[row][col] = 1;

        while (!q.empty()) {

            cnt++;

            // auto [r, c] = q.front();
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            grid[r][c] = 2;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (
                    0 <= nr && nr < n && 0 <= nc && nc < m &&
                    grid[nr][nc] == 1 && !vis[nr][nc]
                ) {
                    // grid[nr][nc] = 2;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return cnt;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> rottens;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rottens.push_back({i, j});
                }
            }
        }

        int ans = 1e9;

        for (int i = 0; i < rottens.size(); i++) {
            // vector<vector<int>> cpy;
            // cpy=grid;
            ans = min(ans, bfs(grid, rottens[i].first, rottens[i].second));
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// correct solution

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j , 0});
                    vis[i][j] = 1;
                }
            }
        }

        int ans = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [ r, c, cnt ] = q.front();
            ans = max ( ans , cnt );

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (
                    0 <= nr && nr < n && 0 <= nc && nc < m &&
                    grid[nr][nc] == 1 && !vis[nr][nc]
                ) {
                    grid[nr][nc] = 2;
                    vis[nr][nc] = 1;
                    q.push({nr, nc, cnt+1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return ans;

    }
};