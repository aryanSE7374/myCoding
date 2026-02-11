#include<bits/stdc++.h>
using namespace std;


// GFG : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Time: O(V + 2E)
// Space: O(V)

class Solution {
  public:
  
    
    bool dfs ( vector<vector<int>>& adj, vector<int>& vis , int src , int parent ) { // passing array as reference : int* vis
        
        vis[src] = 1;
        for ( auto it : adj[src] ) {
            if ( !vis[it] ) {
                if ( dfs ( adj , vis , it , src ) ) return true; 
                // NOTE : 
                // return dfs ( adj , vis , it , src ); // if u write this
                // The moment DFS explores the first unvisited neighbor,
                // you immediately return whatever that recursive call returns.
                // You never check the remaining neighbors.
            }
            else if ( it != parent ) return true;
        }
        return false;

    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> vis(V,0);
        // int vis[V] = {0}; // this syntax is allowed in C99 but not in standard C++

        int E = edges.size();
        vector<vector<int>> adj(V,vector<int>());

        for ( int i=0 ; i<E ; i++ ) {
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( !vis[i] ) {
                if ( dfs ( adj , vis , i , -1 ) ) return true;
            }
        }
        
        return false;
        
    }
};

