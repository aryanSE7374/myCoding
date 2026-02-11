#include<bits/stdc++.h>
using namespace std;


// leetcode
// try1 using wrong bfs : failed

class Solution {
public:

    void bfs( vector<vector<char>>& board , int m, int n , vector<vector<bool>>& vis, int i, int j) {

        queue<pair<int,int>> q;
        q.push({i,j});

        vector<pair<int,int>> X = { {i,j} };

        bool flag = true;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty() && flag){

            auto[r,c] = q.front();
            q.pop();
            for ( int k=0 ; k<4; k++ ) {
                int nr = r+dr[k];
                int nc = c+dc[k];
                if ( nr<0 || nr>=m || nc<0 || nc>=n ) {
                    flag = false;
                    // break;
                }
                else {
                    if ( !vis[nr][nc] && board[nr][nc] == 'O' ) {
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                        X.push_back({nr,nc});
                    }
                }
            }

        }

        if ( flag ) {
            for ( auto [r,c] : X ) {
                board[r][c] = 'X';
            }
        }

    }

    void dfs( vector<vector<char>>& board , int m, int n , vector<vector<char>>& vis, int i, int j) {
        
        
        vis[i][j] = 'O';
        
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        for ( int k=0 ; k<4; k++ ) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if ( ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj] == 'X' && board[ni][nj] == 'O') {
                dfs ( board , m, n, vis, ni, nj );
            }
        }

    }


    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<char>> vis(m,vector<char>(n,'X'));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if ( !vis[i][j] && board[i][j] == 'O' ) {
                    vis[i][j] = 1;
                    dfs(board,m,n,vis,i,j);
                }
            }
        }

    }
};


// ------------------------------------------------------------------------------------------------------ //
// solution : uing dfs (my solution)

class Solution{
public:
    void dfs( vector<vector<char>>& board , int m, int n , vector<vector<char>>& vis, int i, int j) {
        
        vis[i][j] = 'O';
        
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        for ( int k=0 ; k<4; k++ ) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if ( ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj] == 'X' && board[ni][nj] == 'O') {
                dfs ( board , m, n, vis, ni, nj );
            }
        }

    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<char>> vis(m,vector<char>(n,'X'));

        // i=0
        for ( int j=0 ; j<n ; j++ ) {
            if ( vis[0][j] == 'X' && board[0][j] == 'O' ) dfs ( board , m, n, vis, 0, j );
        }
        
        // i=1 to m-2 { j=0 nad n-1}
        for ( int i=1 ; i<m-1; i++ ) {
            if ( vis[i][0] == 'X' && board[i][0] == 'O' ) dfs ( board , m, n, vis, i, 0 );
            if ( vis[i][n-1] == 'X' && board[i][n-1] == 'O' ) dfs ( board , m, n, vis, i, n-1 );
        }
        
        // i=m-1
        for ( int j=0 ; j<n ; j++ ) {
            if ( vis[m-1][j] == 'X' && board[m-1][j] == 'O' ) dfs ( board , m, n, vis, m-1, j );
        }

        for ( int i=0; i<m; i++ ) {
            for ( int j=0; j<n; j++ ) {
                board[i][j] = vis[i][j];
            }
        }

    }
};


// ------------------------------------------------------------------------------------------------------ //


// striver's solution - GFG

class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>> &vis,
             vector<vector<char>> &mat,
             int delrow[], int delcol[]) {

        vis[row][col] = 1;

        int n = mat.size();
        int m = mat[0].size();

        // check for top, right, bottom, left
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                mat[nrow][ncol] == 'O') {

                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    void fill( vector<vector<char>>& mat ) {
        
        int n = mat.size() , m = mat[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first row and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, vis, mat, delrow, delcol);

            if (!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1, j, vis, mat, delrow, delcol);
        }

        // traverse first column and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, vis, mat, delrow, delcol);

            if (!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, vis, mat, delrow, delcol);
        }

        // convert unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

    }
};