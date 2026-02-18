#include<bits/stdc++.h>
using namespace std;

// using BFS : Kahn's Algo

// NOTE : U dont need a visited array in the Kahn's Algo as
// The algorithm implicitly "visits" nodes when their in-degree becomes zero. 

class Solution {
  public:
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> inDegree(V,0);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        vector<int> vis(V,0);
        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( inDegree[i] == 0 ) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while ( !q.empty()) {
            
            int u = q.front();
            q.pop();
            vis[u] = 1;
            ans.push_back(u);
            
            for ( int v : adj[u] ) {
                if ( !vis[v] ) {
                    inDegree[v]--;
                    if ( inDegree[v] == 0 ) {
                        q.push(v);
                    }
                }
            }
        }
        
        return ans;
        
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ //

// code without visited array 

class Solution {
  public:
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<int> inDegree(V,0);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( inDegree[i] == 0 ) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while ( !q.empty()) {
            
            int u = q.front();
            q.pop();
            ans.push_back(u);
            
            for ( int v : adj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        
        return ans;
        
    }
};