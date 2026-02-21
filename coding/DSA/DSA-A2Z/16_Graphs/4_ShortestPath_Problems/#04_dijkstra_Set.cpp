#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        const int INF = 1e9;
        vector<vector<pair<int,int>>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V,INF);
        dist[src] = 0;
        
        set< pair<int,int> > st;
        st.insert({0,src}); // dist , node
        
        while ( !st.empty() ) {
            auto it = *(st.begin());
            int dis = it.first , node = it.second;
            st.erase(it);
            
            for ( auto [adjNode,weight] : adj[node] ) {
                if ( dis + weight < dist[adjNode] ) {
                    if ( dist[adjNode] != INF ) { // node had already been visited
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + weight;
                    st.insert( {dist[adjNode] , adjNode} );
                }
            }
        }
        
        return dist;
        
    }
};