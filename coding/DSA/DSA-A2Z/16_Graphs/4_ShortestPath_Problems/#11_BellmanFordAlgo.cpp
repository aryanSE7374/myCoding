#include<bits/stdc++.h>
using namespace std;

/*
// NOTE : 

(dist[u] != INF) : this check is IMPORTANT for negative edge weights, 
otherwise it will relax even unreachable nodes as well

eg : 
if w = -10 (negative)
1e8 + (-10) = 99999990 < 1e8 

The condition becomes true
You just relaxed from an unreachable node

incorrect behavior

*/


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        const int INF = 1e8;
        vector<int> dist(V, INF);
        dist[src] = 0;
        
        for ( int i=0 ; i<V-1 ; i++ ) {
            for ( auto& e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if ( (dist[u] != INF) && dist[u] + w < dist[v] ) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // check for negative cycle
        for ( auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if ( (dist[u] != INF) && dist[u] + w < dist[v] ) {
                return {-1};
            }
        }
        
        return dist;
        
    }
};
