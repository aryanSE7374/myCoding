#include<bits/stdc++.h>
using namespace std;

// try 1 : failed

class Solution {
  public:
    
    
    // terminal nodes - u : adj[u].size() == 0
    
    bool dfs ( vector<vector<int>>& adj , vector<int>& vis ,
            int i , vector<int>& temp ) {
                
        vis[i] = 1;
        temp.push_back(i);
        
        if ( adj[i].size() == 0 ) {
            return true;
        }
        
        for ( int v : adj[i] ) {
            if ( !vis[v] ) {
                if ( dfs ( adj , vis , v , temp ) ) return true;
            }
        }
        
        return false;
        
    }
  
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        vector<int> ans;
        set<int> st;
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] ;
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        
        for ( int i=0 ; i<V ; i++ ) {
            vector<int> temp;
            vector<int> tempVis(V,0);
            if (!vis[i]) {
                vis[i] = 1;
                if ( dfs ( adj , tempVis , i , temp ) ) {
                    st.insert(temp.begin(),temp.end());
                }
            }
        }
        
        for ( auto it : st ) {
            ans.push_back(it);
        }
        
        return ans;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// solution : dfs based

class Solution {
  public:

    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int node , vector<int>& check ) {
                    
        vis[node] = 1;      // mark visited
        pathVis[node] = 1;     // mark in recursion stack
        
        for (int v : adj[node]) {
            
            if (!vis[v]) {
                if (dfs(adj, vis, pathVis, v , check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[v]) {   // cycle condition
                check[node] = 0;
                return true;
            }

        }
        
        pathVis[node] = 0;   // backtrack
        check[node] = 1;
        return false;

    }
    
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);   // create once (small optimization)
        vector<int> check(V);
        
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                dfs(adj,vis,pathVis,i,check);
            }
        }
        
        vector<int> ans;
        for ( int i=0 ; i<V ; i++ ) {
            if ( check[i] ) ans.push_back(i);
        }
        return ans;
        
    }
};



// ------------------------------------------------------------------------------------------------------------------------------------ //

// solution - using bfs