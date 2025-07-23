#include<bits/stdc++.h>
using namespace std;


// backtracking sol 1

// TC : O(4^(N×N))
// SC : O(N²)



class Solution {
    public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis) {

        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        // right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        // upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }


    vector<string> ratInMaze(vector<vector<int>> &maze) {
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
            solve(0, 0, maze, n, ans, "", vis);

        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// backtracking sol 2 (using direction arrays) : more efficient
// TC : O(4^(N×N))
// SC : O(N²)


class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis, int di[], int dj[], string &dir) {

        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && a[nexti][nextj] == 1) {

                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj, dir);
                vis[i][j] = 0;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) {
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int di[] = {+1, 0, 0, -1}; // D, L, R, U
        int dj[] = {0, -1, 1, 0};
        string dir = "DLRU";

        if (maze[0][0] == 1)
            solve(0, 0, maze, n, ans, "", vis, di, dj, dir);

        return ans;
    }
};

