// Tarjan's Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int timer = 0;
    
    void dfs ( int u, int parent, vector<vector<int>>& adj, vector<int>& inTime, 
            vector<int>& lowTime, vector<int>& vis, vector<int>& mark ) {
        
        vis[u] = 1;
        inTime[u] = timer;
        lowTime[u] = timer;
        timer++;
        int child = 0;
        
        for ( auto& v : adj[u] ) {
            if ( v==parent ) continue;
            if ( !vis[v] ) {
                dfs ( v, u, adj, inTime, lowTime, vis, mark );
                lowTime[u] = min(lowTime[u], lowTime[v]);
                if ( lowTime[v] >= inTime[u] && parent != -1 ) {
                    mark[u] = 1;
                }
                child++;
            }
            else{
                lowTime[u] = min(lowTime[u], inTime[v]);
            }
        }
        if ( parent == -1 && child > 1 ) {
            mark[u] = 1;
        }
        
    }
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V); // adjacency List
        
        for ( auto& e : edges ) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        vector<int> inTime(V);
        vector<int> lowTime(V);
        vector<int> mark(V, 0);
        vector<int> articulationPts;
        
        for ( int u=0; u<V; u++ ) {
            if ( !vis[u] ) {
                dfs (u, -1, adj, inTime, lowTime, vis, mark);
                
            }
        }
        
        for ( int u=0; u<V; u++ ) {
            if ( mark[u] ) articulationPts.push_back(u);
        }
        
        if ( articulationPts.size() == 0 ) {
            return {-1};
        }
        
        return articulationPts;
        
    }
};