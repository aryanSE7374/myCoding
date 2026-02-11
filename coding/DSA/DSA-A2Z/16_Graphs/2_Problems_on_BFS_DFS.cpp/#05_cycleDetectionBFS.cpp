#include<bits/stdc++.h>
using namespace std;

// GFG : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Time: O(V + 2E)
// Space: O(V)

class Solution {
  public:
  
    
    bool bfs ( vector<vector<int>>& adj, vector<int>& vis , int src ) { // passing array as reference : int* vis
        
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
        
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for ( auto it : adj[node] ) {
                if ( !vis[it] ) {
                    q.push({it,node});
                    vis[it] = 1;
                }
                else if ( it != parent ) {
                    return true;
                }
            }
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
                if ( bfs ( adj , vis , i ) ) return true;
            }
        }
        
        return false;
        
    }
};

