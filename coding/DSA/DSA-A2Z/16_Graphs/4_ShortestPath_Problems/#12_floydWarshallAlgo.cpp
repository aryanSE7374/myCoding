#include<bits/stdc++.h>
using namespace std;

// TC : O(n^3)
// SC : O(n^2)

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        
        const int INF = 1e8;
        int n = dist.size();
        
        for ( int k=0 ; k<n ; k++ ) {
            for ( int i=0 ; i<n ; i++ ) {
                for ( int j=0 ; j<n ; j++ ) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }

        /*
        // to check negative cycle
        for ( int i=0 ; i<n ; i++ ) {
            if ( dist[i][i] < 0 ) {
                // there is a negative cycle
            }
        }
        */
        
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //

// when to disjkstra for all n nodes
// TC : O( n*E*logV )

/*
1. when the graph is spase : E << V^2

2. no engative edge weights
    If negative edges exist → cannot use plain Dijkstra.

*/

// only when there's no negative weight in the graph
