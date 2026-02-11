#include<bits/stdc++.h>
using namespace std;

// GFG : https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int >> vis( n , vector<int>(m,0));
        vector<vector<int >> dist( n , vector<int>(m,0));
        
        queue< tuple<int,int,int> > q;
        
        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<m ; j++ ) {
                if ( grid[i][j] == 1 ) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while ( !q.empty() ){
            
            int r = get<0>(q.front());
            int c = get<1>(q.front());
            int steps = get<2>(q.front());
            
            q.pop();
            
            dist[r][c] = steps;
            
            for ( int i=0 ; i<4 ; i++ ) {
                
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if (
                    0<=nr && nr<n && 0<=nc && nc<m && vis[nr][nc] == 0
                ){
                    vis[nr][nc] = 1;
                    q.push({nr,nc,steps+1});
                }
                
            }
            
        }
        
        return dist;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// leetcode version : 0-1 matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int >> vis( n , vector<int>(m,0));
        vector<vector<int >> dist( n , vector<int>(m,0));
        
        queue< tuple<int,int,int> > q;
        
        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<m ; j++ ) {
                if ( grid[i][j] == 0 ) {
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        
        while ( !q.empty() ){
            
            int r = get<0>(q.front());
            int c = get<1>(q.front());
            int steps = get<2>(q.front());
            
            q.pop();
            
            dist[r][c] = steps;
            
            for ( int i=0 ; i<4 ; i++ ) {
                
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if (
                    0<=nr && nr<n && 0<=nc && nc<m && vis[nr][nc] == 0
                ){
                    vis[nr][nc] = 1;
                    q.push({nr,nc,steps+1});
                }
                
            }
            
        }
        
        return dist;
    }
};

