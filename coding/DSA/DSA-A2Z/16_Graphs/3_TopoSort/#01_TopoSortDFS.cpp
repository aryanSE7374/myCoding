#include<bits/stdc++.h>
using namespace std;

// Topological Sort only works for DAGs (Directed Acyclic Graphs)

// using DFS

class Solution {
  public:
  
    void dfs ( vector<vector<int>>& adj , vector<int>& vis , int u , stack<int>& st ) {
        
        vis[u] = 1;
        
        for ( int v : adj[u] ) {
            if ( !vis[v] ) {
                dfs( adj , vis , v , st );
            }
        }
        
        st.push(u);
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( !vis[i] ) {
                dfs( adj , vis , i , st );
            }
        }
        
        vector<int> ans(V,0);
        int i=0;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i++;
        }
        
        return ans;
        
    }
};