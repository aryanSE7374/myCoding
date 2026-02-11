#include <bits/stdc++.h>
using namespace std;

// number of islands : GFG
// --------------------------------------------------------------------------- //

class Solution {
  public:

    void bfs ( int row , int col , vector<vector<int>>& vis , vector<vector<char>>& grid ) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue< pair<int,int> > q;

        q.push({row,col});

        while ( !q.empty() ) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for ( int dr = -1 ; dr <= 1 ; dr++ ) {
                for ( int dc = -1 ; dc <= 1 ; dc++ ) {
                    int nr = r+dr , nc = c+dc ;
                    if ( 0<=nr && nr < n && 0<=nc && nc<m && grid[nr][nc] == 'L' && !vis[nr][nc] ) {
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }

                }
            } 

        }

        

    }

    int countIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis( n , vector<int>(m,0) );
        int cnt = 0;

        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<m ; j++ ) {

                if ( !vis[i][j] && grid[i][j] == 'L' ) {
                    cnt++;
                    bfs( i, j , vis , grid );
                } 

            }
        }

        return cnt;
        
    }
};