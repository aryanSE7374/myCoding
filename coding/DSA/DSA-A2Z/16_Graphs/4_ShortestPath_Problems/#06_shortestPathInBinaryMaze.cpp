#include <bits/stdc++.h>
using namespace std;


// GFG version : https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

// my code

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if ( A[0][0] == 0 || A[X][Y] == 0 ) return -1;
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        queue< pair < pair<int,int>, int > > q;
        
        q.push({{0,0},0});
        vis[0][0] = 1;
        
        vector<int> di = {-1,0,1,0};
        vector<int> dj = {0,1,0,-1};
        
        while ( !q.empty() ) {
            auto it = q.front();
            q.pop();
            
            int i = it.first.first , j = it.first.second ;
            int dist = it.second;
            
            if ( i==X && j==Y ) return dist;
            
            for ( int k=0 ; k<4 ; k++ ) {
                int r = i + di[k] ;
                int c = j + dj[k] ;
                if ( 0<=r && r<N && 0<=c && c<M && A[r][c] == 1 && !vis[r][c] ) {
                    q.push( { {r,c}, dist+1} ) ;
                    vis[r][c] = 1;
                }
            }
            
        }
        
        return -1;
        
        
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //


// striver's code : Dijkstra-style BFS

class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {

        if (A[0][0] == 0)
            return -1;

        if (A[X][Y] == 0)
            return -1;

        if (X == 0 && Y == 0)
            return 0;

        vector<vector<int>> dist(N, vector<int>(M, 1e9));
        queue<pair<int,int>> q;

        dist[0][0] = 0;
        q.push({0,0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < N &&
                    nc >= 0 && nc < M &&
                    A[nr][nc] == 1 &&
                    dist[r][c] + 1 < dist[nr][nc]) {

                    dist[nr][nc] = dist[r][c] + 1;

                    // Early stopping
                    if (nr == X && nc == Y)
                        return dist[nr][nc];

                    q.push({nr, nc});
                }
            }
        }

        return -1; // unreachable
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------------------------------------- //



// Leetcode version (8 directions movement) : https://leetcode.com/problems/shortest-path-in-binary-matrix/

// my code 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int N = grid.size();
        int X = N-1 , Y = N-1 ;

        if ( grid[0][0] == 1 || grid[X][Y] == 1 ) return -1;

        vector<vector<int>> vis(N,vector<int>(N,0));
        queue< pair < pair<int,int>, int > > q;
        
        q.push({{0,0},1});
        vis[0][0] = 1;
        
        vector<int> di = {-1,0,1};
        vector<int> dj = {-1,0,1};
        
        while ( !q.empty() ) {
            auto it = q.front();
            q.pop();
            
            int i = it.first.first , j = it.first.second ;
            int dist = it.second;
            
            if ( i==X && j==Y ) return dist;
            
            for ( int ki=0 ; ki<3 ; ki++ ) {
                for ( int kj=0 ; kj<3 ; kj++ ) {
                    int r = i + di[ki] ;
                    int c = j + dj[kj] ;
                    if ( 0<=r && r<N && 0<=c && c<N && grid[r][c] == 0 && !vis[r][c] ) {
                        q.push( { {r,c}, dist+1} ) ;
                        vis[r][c] = 1;
                    }
                }
            }
            
        }
        
        return -1;
    }
};