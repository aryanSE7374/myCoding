#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 

// GFG version : have only connected components

// using BFS

class Solution {
  public:

    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        int E = edges.size();
        
        vector<vector<int>> adj(V);

        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V,0);

        queue<int> q;
        q.push(0);

        while ( !q.empty() ) {

            int u = q.front();
            q.pop();

            for ( int v : adj[u] ) {
                if ( color[v] == 0 ) {
                    color[v] = (color[u]==1) ? 2 : 1 ;
                    q.push(v);
                }
                else if ( color[v] == color[u] ) {
                    return false;
                }
            }

        }

        return true;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// using DFS

class Solution {
  public:

    bool dfs ( vector<vector<int>> &adj , int u , vector<int>& color ) {

        for ( int v : adj[u] ) {
            if ( color[v] == 0 ) {
                color[v] = (color[u]==1) ? 2 : 1 ;
                if ( dfs ( adj , v , color ) == false ) return false;
            }
            else if ( color[v] == color[u] ) {
                return false;
            }
        }

        return true;

    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        int E = edges.size();
        
        vector<vector<int>> adj(V);

        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V,0);
        color[0] = 1;

        return dfs ( adj , 0 , color );

    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 

// LC version : graph may have disconnected components


// using BFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {

        int V = adj.size();
        vector<int> color(V,0);

        
        for ( int i=0 ; i<V ; i++ ) {
            
            if ( color[i] == 0 ) {
                
                queue<int> q;
                q.push(i);

                while ( !q.empty() ) {

                    int u = q.front();
                    q.pop();

                    for ( int v : adj[u] ) {
                        if ( color[v] == 0 ) {
                            color[v] = (color[u]==1) ? 2 : 1 ;
                            q.push(v);
                        }
                        else if ( color[v] == color[u] ) {
                            return false;
                        }
                    }

                }
            }

        }

        return true;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// using DFS

class Solution {
public:

    bool dfs ( vector<vector<int>> &adj , int u , vector<int>& color ) {

        for ( int v : adj[u] ) {
            if ( color[v] == 0 ) {
                color[v] = (color[u]==1) ? 2 : 1 ;
                if ( dfs ( adj , v , color ) == false ) return false;  
            }
            else if ( color[v] == color[u] ) {
                return false;
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& adj) {

        int V = adj.size();
        vector<int> color(V,0);

        
        for ( int i=0 ; i<V ; i++ ) {
            
            if ( color[i] == 0 ) {
                if ( dfs ( adj , i , color ) == false ) return false;
            }

        }

        return true;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 