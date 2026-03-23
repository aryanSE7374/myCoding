#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const ll INF = 1e18;
        const int MOD = 1e9 + 7;
        int src = 0 , destn = n-1;

        vector<vector<pair<int, int>>> adj(n);
        for ( auto e : roads ) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // pq -> {dist, node}
        priority_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>  > pq; // minHeap

        vector<ll> dist(n, INF);
        vector<int> ways(n, 0);

        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});

        while ( !pq.empty() ) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue;  // stale entries check (optimization)

            for ( auto& [v, w] : adj[u] ) {
                if ( w + currDist < dist[v] ) {
                    dist[v] = 1LL*w + 1LL*currDist;
                    pq.push({dist[v], v});
                    ways[v] = ways[u]; // Found a strictly shorter path to v.
                                       // Previous ways[v] corresponded to longer distances,
                                       // so discard them and reset to ways[u].
                }
                else if ( w + currDist == dist[v] ) {
                    ways[v] = (ways[v] +  ways[u])%MOD;
                }
            }

        }

        return (ways[destn])%MOD;

    }
};