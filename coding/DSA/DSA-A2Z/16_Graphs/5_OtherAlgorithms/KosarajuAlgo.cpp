#include<bits/stdc++.h>
using namespace std;

// Algorithm to count strongly connected components

class Solution {
  public:
    
    void dfs ( int u, vector<int>& vis, vector<vector<int>>& adj, 
        stack<int>& st) {
        vis[u] = 1;
        for ( int& v : adj[u] ) {
            if ( !vis[v] ) {
                vis[v] = 1;
                dfs ( v, vis, adj, st );
            }
        }
        st.push(u);
    }
    
    void dfs2 ( int u, vector<int>& vis, vector<vector<int>>& adjT ) {
        vis[u] = 1;
        for ( auto v : adjT[u] ) {
            if ( !vis[v] ) {
                vis[v] = 1;
                dfs2 ( v, vis, adjT );
            }
        }
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        // adjacency
        vector< vector<int> > adj (V, vector<int>() );
        for ( auto& e : edges ) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0); // visited
        stack<int> st; // stack to store components acc to finish time
        
        // dfs1 to initialize stack
        for ( int i=0; i<V; i++ ) {
            if ( !vis[i] ) {
                dfs ( i, vis, adj, st);
            }
        }
        
        // adjacency transpose for reversed edges
        vector< vector<int> > adjT (V, vector<int>() );
        for ( int u=0; u<V; u++ ) {
            vis[u] = 0;
            for ( auto v : adj[u] ) {
                adjT[v].push_back(u);
            }
        }
        
        int scc = 0; // count
        
        // dfs2 to count components
        while ( !st.empty() ) {
            int node = st.top();
            st.pop();
            if ( !vis[node] ) {
                scc++;
                dfs2 ( node, vis, adjT );
            }
        }
        
        return scc;
        
    }
};