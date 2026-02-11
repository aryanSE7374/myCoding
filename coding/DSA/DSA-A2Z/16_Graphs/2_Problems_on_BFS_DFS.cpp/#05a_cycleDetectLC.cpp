#include<bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/detect-cycles-in-2d-grid/

// Time: O(n*m)
// Space: O(n*m)

class Solution {
public:
    bool bfs ( vector<vector<char>>& grid , vector<vector<int>>& vis , int r , int c ) {

        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        char src = grid[r][c];

        queue<tuple<int,int,int,int>> q;
        q.push({r,c,-1,-1});

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        while(!q.empty()){
        
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int parenti = get<2>(q.front());
            int parentj = get<3>(q.front());

            q.pop();

            for ( int k=0 ; k<4 ; k++ ) {

                int ni = i+di[k];
                int nj = j+dj[k];

                if ( 0<=ni && ni<n && 0<=nj && nj < m ) {

                    if ( grid[ni][nj] == src ) {

                        if ( !vis[ni][nj] ) {
                            q.push({ni,nj,i,j});
                            vis[ni][nj] = 1;
                        }
                        else if ( ni != parenti || nj != parentj ){
                            return true;
                        }
                    }
                }

            }
        }
        return false;   
    }
    
    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis( m , vector<int>(n));

        for ( int i=0 ; i<m ; i++ ) {
            for (int j=0 ; j<n ; j++ ){

                if ( !vis[i][j] ) {
                    if ( bfs ( grid , vis , i , j ) ) {
                        return true;
                    }
                }
            } 
        }
        
        return false;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// chat GPT struct based polished code : 

class Solution {
public:

    struct Node{
        int i, j, parenti, parentj;
    };

    bool bfs ( vector<vector<char>>& grid , vector<vector<bool>>& vis , int r , int c ) {

        vis[r][c] = true;

        int n = grid.size();
        int m = grid[0].size();

        char src = grid[r][c];

        queue<Node> q;
        q.push({r,c,-1,-1});

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        while(!q.empty()){
        
            Node cur = q.front();
            q.pop();

            int i = cur.i;
            int j = cur.j;
            int parenti = cur.parenti;
            int parentj = cur.parentj;

            for ( int k=0 ; k<4 ; k++ ) {

                int ni = i+di[k];
                int nj = j+dj[k];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;

                if (grid[ni][nj] != src)
                    continue;

                if (!vis[ni][nj]) {

                    vis[ni][nj] = true;
                    q.push({ni,nj,i,j});
                }
                else if (ni != parenti || nj != parentj) {

                    return true;
                }
            }
        }
        return false;   
    }
    
    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis( m , vector<bool>(n,false));

        for ( int i=0 ; i<m ; i++ ) {
            for (int j=0 ; j<n ; j++ ){

                if ( !vis[i][j] ) {
                    if ( bfs ( grid , vis , i , j ) ) {
                        return true;
                    }
                }
            } 
        }
        
        return false;
    }
};