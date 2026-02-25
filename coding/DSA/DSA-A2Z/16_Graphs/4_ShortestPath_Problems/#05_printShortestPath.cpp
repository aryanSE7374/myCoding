#include <bits/stdc++.h>
using namespace std;


// GFG : https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// my code - passed on GFG

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        const int INF = 1e9;
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        int src = 1 , destination = n ;
        
        vector<int> dist(n+1,INF);
        vector<int> parent(n+1,-1);
        
        dist[src] = 0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,src}); // dist , node
        
        while ( !pq.empty() ) {
            auto [dis,u] = pq.top();
            pq.pop();
            
            if ( dis > dist[u] ) continue; // NOTE : w/o this line => TLE
            
            for ( auto [v,w] : adj[u] ) {
                if ( ( dis + w ) < dist[v] ) {
                    dist[v] = dis + w;
                    parent[v] = u;
                    pq.push( {dist[v] , v} );
                }
            }
        }
        
        if ( dist[n] == INF ) return {-1};
        
        vector<int> path;
        
        while ( destination != -1 ) {
            path.push_back(destination);
            destination = parent[destination];
        }
        
        path.push_back(dist[n]);
        
        reverse( path.begin(), path.end() );
        return path;
        
        
        
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //

// striver's code

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        const int INF = 1e9;
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(n+1,INF);
        vector<int> parent(n+1);

        for ( int i=1 ; i<=n ; i++ ) parent[i]=i;
        
        dist[1] = 0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,1}); // dist , node
        
        while ( !pq.empty() ) {
            auto [dis,u] = pq.top();
            pq.pop();
            
            for ( auto [v,w] : adj[u] ) {
                if ( ( dis + w ) < dist[v] ) {
                    dist[v] = dis + w;
                    pq.push( {dist[v] , v} );
                    parent[v] = u;
                }
            }
        }
        
        if ( dist[n] == INF ) return {-1};
        
        vector<int> path;

        int node = n;
        while ( parent[node] != node ) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);
        path.push_back(dist[n]); // distance at start
        
        reverse( path.begin(), path.end() );
        return path;
        
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //