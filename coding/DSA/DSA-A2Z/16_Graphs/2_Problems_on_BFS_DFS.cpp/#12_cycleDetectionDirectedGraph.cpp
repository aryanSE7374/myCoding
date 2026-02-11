#include<bits/stdc++.h>
using namespace std;

// my dfs try - accepted
// temp hack used here

class Solution {
  public:
    
    bool dfs ( vector<vector<int>> &adj , vector<int> &temp, int i , int src) {
                
        temp[i] = 1;
        
        for ( int v : adj[i] ) {
            if ( !temp[v] ) {
                if ( dfs ( adj , temp , v , src) ) return true; 
            }
            if ( v == src ) return true;
        }
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj (V);
        
        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( !vis[i] ) {
                vis[i] = 1;
                vector<int> temp(V,0);
                if ( dfs ( adj , temp , i , i ) ) return true;
            }
        }
        
        return false;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// correct DFS approach : 
// a cycle exists only if: 
// During DFS, you reach a node that is already in the current recursion stack.
// GPT fixes to my solution : 

// small optimization on space hint : use a single visited array : mark 1 for vis and 2 for pathVis 

class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int i) {
                
        vis[i] = 1;      // mark visited
        pathVis[i] = 1;     // mark in recursion stack
        
        for (int v : adj[i]) {
            
            if (!vis[v]) {
                if (dfs(adj, vis, pathVis, v)) return true;
            }
            else if (pathVis[v]) {   // cycle condition
                return true;
            }
        }
        
        pathVis[i] = 0;   // backtrack
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);
        
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);   // create once (small optimization)
        
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, pathVis, i)) return true;
            }
        }
        
        return false;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// using BFS?? - Kahn's Algo


// try1 : failed idea (on disconnected components)

class Solution{
    public:
        bool isCyclic(int V, vector<vector<int>> &edges) {

            vector<vector<int>> adj(V);
            vector<int> inDegree(V,0);
            
            for ( auto e : edges ) {
                int u = e[0] , v = e[1];
                adj[u].push_back(v);
                inDegree[v]++;
            }
            
            vector<int> vis(V,0);
            queue<int> q;
            
            for ( int u=0 ; u<V ; u++ ) {
                if ( inDegree[u]==0 ) {
                    q.push(u);
                    vis[u] = 1;
                }
            }
            
            if ( q.empty() ) return true;
            
            while( !q.empty() ) {
                int u = q.front();
                q.pop();
                vis[u] = 1;
                for ( int v : adj[u] ) {
                    if ( vis[v] ) return true;
                    else {
                        inDegree[v]--;
                        if ( inDegree[v] == 0 ) q.push(v);
                    }
                }
            }
            
            return false;

        }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// correct solution : idea - check if a topo sort of length V can be produced or not

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
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
        
        return ( ans.size() == V ) ? false : true ;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// optimization : instead of ans array , use a count variable to save space

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
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
        
        int cnt = 0 ;
        
        while ( !q.empty()) {
            
            int u = q.front();
            q.pop();
            vis[u] = 1;
            cnt++;
            
            for ( int v : adj[u] ) {
                if ( !vis[v] ) {
                    inDegree[v]--;
                    if ( inDegree[v] == 0 ) {
                        q.push(v);
                    }
                }
            }
        }
        
        return ( cnt == V ) ? false : true ;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //