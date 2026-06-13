#include<bits/stdc++.h>
using namespace std;

// BFS

// grid -> [color, step]

class Solution {
public:
    
    bool check ( int r, int c, int n, int m) {
        return (
            r>=0 && r<n && c>=0 && c<m
        );
    }
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> ans(n , vector<int>(m));
        vector<vector<pair<int, int>>> grid(n , vector<pair<int, int>>(m, {-1, -1})); // temp grid : [color, step]
        
        queue<pair<int, pair<int, pair<int, int> > > > q; // {steps, {color, {x,y}}}

        // step 0 initiially
        for ( auto& src : sources ) {
            int r = src[0], c = src[1], clr = src[2];
            q.push({0, {clr, {r, c}} });
            grid[r][c] = {clr, 0};
        }

        int dx[4] = {-1, 0, 1, 0}; // U, R, D, L
        int dy[4] = {0, 1, 0, -1};

        while ( !q.empty() ) {
            auto it = q.front();
            int steps = it.first;
            int color = it.second.first;
            int x = it.second.second.first;
            int y = it.second.second.second;
            q.pop();

            for ( int i=0; i<4; i++ ) {
                int r = x + dx[i];
                int c = y + dy[i];
                if ( check(r, c, n, m) ) {
                    auto [clr, stp] = grid[r][c];
                    if ( (clr == -1) || (stp == steps) ) {
                        grid[r][c] = {steps, max(clr, color)};
                        q.push( {steps+1, {color, {r, c} } } );
                    }
                }
            }
            
        }

        for ( int i=0; i<n; i++ ) {
            for ( int j=0; j<m; j++ ) {
                ans[i][j] = grid[i][j].second;
            }
        }

        return ans;
        
    }
};