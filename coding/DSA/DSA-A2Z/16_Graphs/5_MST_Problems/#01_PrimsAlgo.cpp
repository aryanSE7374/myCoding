#include<bits/stdc++.h>
using namespace std;

// Assumption : graph is connected into a single component

// NOTE : If the graph is disconnected, You will only get MST of the connected component containing node 0.
// in multuple components => MST -> minimal spanning forest

// Time: O(E log E) ~~ O(E log V) { as log E ~ log V}
// Space: O(V + E)

// Prim's Algo implementation (wihtout MST edges)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);
        
        for ( auto& e : edges ) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int sum = 0;
        
        vector<int> vis(V,0);
        priority_queue< pair<int, int> , 
            vector<pair<int, int>> , 
            greater<pair<int, int>> > pq; // {wt, node}
            
        pq.push({0,0});
        
        while ( !pq.empty() ) {
            
            auto [wt, node] = pq.top();
            pq.pop();
            
            if ( vis[node] ) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for ( auto& [v,w] : adj[node] ) {
                if ( !vis[v] ) {
                    pq.push({w,v});
                }
            }
            
        }
        
        return sum;
            
    }
};

// --------------------------------------------------------------------------------------------------------- //

// Prim's Algo implementation (MST edges)

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(V);
        
        for ( auto& e : edges ) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int sum = 0;
        
        vector<int> vis(V,0);
        vector<pair<int,int>> MST;

        priority_queue< pair < int, pair< int , int> > ,
        vector< pair < int, pair< int , int> > > , 
        greater< pair < int, pair< int , int> > > > pq; // {wt, node , parent}
            
        pq.push({0,{0,-1}});
        
        while ( !pq.empty() ) {
            
            auto [wt, it ] = pq.top();
            int node = it.first;
            int parent = it.second;
            pq.pop();
            
            if ( vis[node] ) continue;
            
            vis[node] = 1;
            sum += wt;
            if ( parent != -1 ) MST.push_back({parent,node});
            
            for ( auto& [v,w] : adj[node] ) {
                if ( !vis[v] ) {
                    pq.push( { w, { v, node } } );
                }
            }
            
        }
        
        return sum;
            
    }
};

// --------------------------------------------------------------------------------------------------------- //