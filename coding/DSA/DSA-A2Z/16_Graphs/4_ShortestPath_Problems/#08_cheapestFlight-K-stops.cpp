#include<bits/stdc++.h>
using namespace std;

// my PQ try (fixed) - passed
// TC : O( E*log(E) )
// SC : O ( V+E )

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        const int INF = 1e9;
        
        vector< vector< pair< int, int > > > adj(n);
        vector<int> dist(n,INF);

        for ( auto f : flights ) {
            int u = f[0] , v = f[1] , cost = f[2];
            adj[u].push_back( {v,cost} ) ;
        }

        // { stops, {node, cost} } 
        priority_queue< pair < int, pair <int, int> >, 
        vector< pair < int, pair <int, int> > >, 
        greater< pair < int, pair <int, int> > > > pq;

        pq.push( { 0, { src, 0 }} );
        dist[src] = 0;

        while ( !pq.empty() ) {

            auto it = pq.top();
            pq.pop();

            int currStops = it.first;
            int currNode = it.second.first;
            int currCost = it.second.second;

            if ( currStops > k ) continue;

            for ( auto[ adjNode, adjCost ] : adj[currNode] ) {
                if ( currCost + adjCost < dist[adjNode] ) {
                    dist[adjNode] = currCost + adjCost;
                    pq.push( { currStops+1, { adjNode, dist[adjNode] } } );
                }
            }

        }

        if ( dist[dst] != INF ) return dist[dst];
        return -1;

    }
};


// -------------------------------------------------------------------------------------------------------------------------- //

// striver's solution : 
// TC : O( K*E ) // Each edge can be relaxed up to K times.
// SC : 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
                          int src, int dst, int K) {

        // Adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            // If stops exceed K, skip
            if (stops > K) continue;

            for (auto &iter : adj[node]) {

                int adjNode = iter.first;
                int edgeW   = iter.second;

                if (cost + edgeW < dist[adjNode]) {

                    dist[adjNode] = cost + edgeW;
                    q.push({stops + 1, {adjNode, cost + edgeW}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};


// -------------------------------------------------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------------------------------------------------- //


// TODO : 

// This Problem can be solved using more ways : 

// ** Dijkstra on Expanded State Space (2D Distance) 
// ** DP (Top-Down Memoization)
// * Bellman ford idea


// -------------------------------------------------------------------------------------------------------------------------- //