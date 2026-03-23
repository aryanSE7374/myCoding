#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------------------ //

/*

Assumes:
    Once node is finalized, its distance is optimal

This fails even with one negative edge


// NOTE : 

With Negative Edge Only : 
    You still get a valid shortest path tree.

With Negative Cycle : 
    There is no answer.

    
|------------------------------|---------------|----------------|
| Feature                      | Negative Edge | Negative Cycle |
|------------------------------|---------------|----------------|
| Is shortest path defined?    | Yes           | No             |
| Dijkstra works?              | No            | No             |
| Bellman-Ford works?          | Yes           | Detects cycle  |
| Floyd-Warshall works?        | Yes           | Detects cycle  |
|------------------------------|---------------|----------------|

*/

// ------------------------------------------------------------------------------------------ //

// my try : failed
// TC : ElogE

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        const int INF = 1e9;
        vector<vector<pair<int,int>>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V,INF);
        dist[src] = 0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,src}); // dist , node
        
        while ( !pq.empty() ) {
            auto [w,u] = pq.top();
            pq.pop();
            
            for ( auto [v,w] : adj[u] ) {
                if ( ( w + dist[u] ) < dist[v] ) {
                    dist[v] = w + dist[u];
                    pq.push( {dist[v] , v} );
                }
            }
        }
        
        return dist;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// fixed code
// TC : (E+V)*logV

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        const int INF = 1e9;
        vector<vector<pair<int,int>>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int> dist(V,INF);
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
                    pq.push( {dist[v] , v} );
                }
            }
        }
        
        return dist;
        
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// striver's code

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        const int INF = 1e9;
        vector<vector<pair<int,int>>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1] , w = e[2] ;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int> dist(V,INF);
        dist[src] = 0;
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,src}); // dist , node
        
        while ( !pq.empty() ) {
            auto [dis, node] = pq.top();
            pq.pop();
            
            if ( dis > dist[node] ) continue; // NOTE : w/o this line => TLE
            
            for ( auto [adjNode,weight] : adj[node] ) {
                if ( ( dis + weight ) < dist[adjNode] ) {
                    dist[adjNode] = dis + weight;
                    pq.push( {dist[adjNode] , adjNode} );
                }
            }
        }
        
        return dist;
        
    }
};