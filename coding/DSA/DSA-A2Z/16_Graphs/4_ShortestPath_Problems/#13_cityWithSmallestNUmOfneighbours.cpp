#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n,INF) );

        for ( auto e : edges ) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for ( int i=0 ; i<n ; i++ ) {
            dist[i][i] = 0;
        }

        for ( int k=0 ; k<n ; k++ ) {
            for ( int i=0 ; i<n ; i++ ) {
                for ( int j=0 ; j<n ; j++ ) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                    }
                }
            }
        }

        vector<int> cntThreshold(n,0);

        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<n ; j++ ) {
                if ( i==j ) continue;
                if ( dist[i][j] <= distanceThreshold ) {
                    cntThreshold[i]++;
                }
            }
        }

        int ans = -1;
        int mini = INF;
        for ( int i=n-1 ; i>=0 ; i-- ) {
            if ( cntThreshold[i] < mini ) {
                mini = cntThreshold[i];
                ans = i;
            }
        }

        return ans;

    }
};


// -------------------------------------------------------------------------------- //

// striver's code (same - lil bit optimized)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n,INF) );

        for ( auto e : edges ) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for ( int i=0 ; i<n ; i++ ) {
            dist[i][i] = 0;
        }

        for ( int k=0 ; k<n ; k++ ) {
            for ( int i=0 ; i<n ; i++ ) {
                for ( int j=0 ; j<n ; j++ ) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
                    }
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;

        for ( int city = 0; city < n; city++ ) {
            int cnt = 0;
            for ( int adjCity=0; adjCity<n; adjCity++ ) {
                if ( dist[city][adjCity] <= distanceThreshold ) cnt++;
            }
            if ( cnt <= cntCity ) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;

    }
};

// -------------------------------------------------------------------------------- //

// using Dijkstra's Algo

class Solution {
public:
    void dijkstra ( vector<vector<pair<int, int>>>& adj, int src , vector<int>& dist ) {

        priority_queue< pair<int, int>, vector< pair<int, int> > , greater< pair<int, int> > > pq; // {dis , src}
        pq.push({0, src});
        dist[src] = 0;

        while ( !pq.empty() ) {

            auto [dis, u] = pq.top();
            pq.pop();

            if ( dis > dist[u] ) continue;

            for ( auto& [v, w] : adj[u] ) {
                if ( (dis + w) < dist[v] ) {
                    dist[v] = dis+w;
                    pq.push({dist[v], v});
                }
            }

        }

    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n,INF) );
        vector<vector<pair<int, int>>> adj(n);

        for ( auto e : edges ) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for ( int src = 0 ; src<n ; src++ ) {
            dijkstra( adj , src , dist[src] );
        }

        int cntCity = n;
        int cityNo = -1;

        for ( int city = 0; city < n; city++ ) {
            int cnt = 0;
            for ( int adjCity=0; adjCity<n; adjCity++ ) {
                if ( dist[city][adjCity] <= distanceThreshold ) cnt++;
            }
            if ( cnt <= cntCity ) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;

    }
};

// -------------------------------------------------------------------------------- //