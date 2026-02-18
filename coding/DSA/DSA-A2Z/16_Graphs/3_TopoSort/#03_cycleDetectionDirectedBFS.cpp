#include<bits/stdc++.h>
using namespace std;

// try1 : failed idea (on disconnected components) - try fixing this idea

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