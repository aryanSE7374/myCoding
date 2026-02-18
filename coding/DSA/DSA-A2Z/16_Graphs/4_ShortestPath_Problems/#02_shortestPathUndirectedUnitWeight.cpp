#include<bits/stdc++.h>
using namespace std;


// try 1 - passed 
// visited array not needed , can simply check visited or not by checking the dist is -1 or not

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        vector<vector<int>> adj(V);
        
        for ( auto& e : edges ) {
            int u = e[0] , v = e[1] ;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        vector<int> dist(V,-1);
        
        
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        vis[src] = 1;
        
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            for ( int v : adj[u] ) {
                if ( !vis[v] ) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        
        return dist;

    }
};


// ----------------------------------------------------------------------------------------------------- //

// without visited array ( best code )

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        vector<vector<int>> adj(V);
        
        for ( auto& e : edges ) {
            int u = e[0] , v = e[1] ;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(V,-1);
        
        
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            for ( int v : adj[u] ) {
                if ( dist[v] == -1 ) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        return dist;

    }
};


// ----------------------------------------------------------------------------------------------------- //

// striver's solution

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        vector<vector<int>> adj(V);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};