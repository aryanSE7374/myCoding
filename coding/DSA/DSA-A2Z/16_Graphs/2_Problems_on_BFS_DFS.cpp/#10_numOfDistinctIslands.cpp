#include<bits/stdc++.h>
using namespace std;

// FOLLOW UP : what is orientation rotation is accepted i.e. 
/*

X X         is considered the same as :     X       and       X        and      X X
X                                           X X             X X                   X

*/


// my solution : accepted

class Solution {
  public:
  
    void bfs( vector<vector<int>>& grid , vector<vector<int>>& vis , 
            set<vector<pair<int,int>>>& st, int i , int j ){
                
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        vector<pair<int,int>> temp;
        temp.push_back({0,0}); // base
        
        while( !q.empty() ) {
            
            auto [r,c] = q.front();
            q.pop();
            
            for ( int k=0 ; k<4 ; k++ ) {
                
                int nr =r+dr[k];
                int nc =c+dc[k];
                
                if ( 0<=nr && nr<n && 0<=nc && nc<m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                    temp.push_back({nr-i,nc-j});
                } 
                
                
            }
            
        }
        
        st.insert(temp);
        
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> st; // hash set
        
        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<m ; j++ ) {
                if ( !vis[i][j] && grid[i][j] == 1 ) {
                    vis[i][j] = 1;
                    bfs( grid,vis,st,i,j );
                }
            }
        }
        
        return st.size();
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's solution - dfs based

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid, vector<pair<int,int>> &vec,
             int row0, int col0, int n, int m) {
        
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
               && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, vec, row0, col0, n, m);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> vec;
                    dfs(i, j, vis, grid, vec, i, j, n, m);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};