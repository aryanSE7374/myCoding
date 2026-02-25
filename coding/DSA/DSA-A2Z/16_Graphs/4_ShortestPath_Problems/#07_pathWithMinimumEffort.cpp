#include <bits/stdc++.h>
using namespace std;


// striver's code

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int N = heights.size() , M = heights[0].size() ;

        // { diff, {row, col} }
        priority_queue< pair < int, pair<int,int> > , 
            vector< pair < int, pair<int,int> > >  , 
            greater< pair < int, pair<int,int> > > 
            > pq;

        vector<vector<int>> dist(N, vector<int>(M, 1e9));

        dist[0][0] = 0;
        pq.push({ 0, {0,0 } });

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int r = it.second.first , c = it.second.second ;

            // check for stale entries
            if ( diff > dist[r][c] ) continue;

            if ( (r == N-1) && (c == M-1) ) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < N && nc >= 0 && nc < M ) {

                    int effort = abs ( heights[nr][nc] - heights[r][c] ) ;
                    int newEffort = max ( effort, diff ) ;

                    if ( newEffort < dist[nr][nc] ) {
                        dist[nr][nc] = newEffort;
                        pq.push( { newEffort, {nr, nc} } ) ;
                    }
                }
            }
        }

        return 0;
    }
};