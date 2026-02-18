#include<bits/stdc++.h>
using namespace std;

// greeedy try 1 : using dfs based relaxation ( failed )

class Solution {
  public:
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        const int INF = 1e9;
        vector<int> dist(V,INF);
        vector<vector<pair<int,int>>> adj (V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].push_back({v,w});
        }
        
        vector<int> vis(V,0);
        dist[0] = 0;

        queue<int> q;
        q.push (0);
        vis[0] = 1;
        
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            for ( auto [v,w] : adj[u] ) {
                dist[v] = min ( dist[v] , w + dist[u] ) ;
                if ( !vis[v] ) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        
        
        for ( int i=1 ; i<V ; i++ ) {
            if ( dist[i] == INF ) dist[i] = -1;
        }
        
        return dist;
        
    }
};



/*

TC1 :

0 2 6
0 3 7
0 4 9
0 6 8
0 7 6
1 2 6
1 3 7
1 5 10
1 6 1
1 7 4
2 3 3
2 6 10
2 8 8
2 9 10
3 5 3
3 6 10
3 7 5
5 6 9
5 7 7
6 7 7
6 8 8
6 9 8
7 9 1
8 9 6


TC2 : 

4
5
0 1 10
0 2 5
1 3 1
2 1 3
2 3 7

*/

// ------------------------------------------------------------------------------------ //

// solution : using topo - DFS

/*
intuition : 

Because the graph is acyclic, topological order ensures every node is processed only after all its shortest contributing paths have been finalized.

That is why a single relaxation pass works.

*/

class Solution {
  public:
    void dfs ( vector<vector<pair<int,int>>>& adj , vector<int>& vis , int u , stack<int>& st ) {
        
        vis[u] = 1;
        
        for ( auto& [v,w] : adj[u] ) {
            if ( !vis[v] ) {
                dfs( adj , vis , v , st );
            }
        }
        
        st.push(u);
        
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        const int INF = 1e9;
        vector<int> dist(V,INF);
        vector<vector<pair<int,int>>> adj (V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].push_back({v,w});
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( !vis[i] ) {
                dfs( adj , vis , i , st );
            }
        }
        
        dist[0] = 0;
        while ( !st.empty() ) {
            int u = st.top();
            st.pop();
            // if (dist[u] != INF) // add this check before adj exploration
            for ( auto& [v,w] : adj[u] ) {
                dist[v] = min ( dist[v] , dist[u] + w ) ;
            }
        }
        
        
        for ( int i=1 ; i<V ; i++ ) {
            if ( dist[i] == INF ) dist[i] = -1;
        }
        
        // while updating using range based for loop , make sure to iterate by reference
        // for ( int& d : dist ) {
        //     if ( d==INF ) d = -1;
        // }
        
        return dist;
        
    }
};


// ------------------------------------------------------------------------------------ //

// method 2 using BFS

class Solution {
  public:
  
    vector<int> topoSort(int V, vector<vector<pair<int,int>>>& adj , vector<int>& inDegree) {
        
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
            
            for ( auto& [v,w] : adj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        
        return ans;
        
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        const int INF = 1e9;
        vector<int> dist(V,INF);
        vector<vector<pair<int,int>>> adj (V);
        vector<int> inDegree(V,0);
        
        for ( auto& e : edges ) {
            int u = e[0] , v = e[1] , w = e[2];
            adj[u].push_back({v,w});
            inDegree[v]++;
        }
        
        vector<int> vis(V,0);
        vector<int> topo = topoSort( V , adj , inDegree );
        
        dist[0] = 0;
        
        for ( int& u : topo ) {
            for ( auto& [v,w] : adj[u] ) {
                dist[v] = min ( dist[v] , dist[u] + w ) ;
            }
        }
        
        for ( int i=1 ; i<V ; i++ ) {
            if ( dist[i] == INF ) dist[i] = -1;
        }

        return dist;
        
    }
};

// ------------------------------------------------------------------------------------ //

