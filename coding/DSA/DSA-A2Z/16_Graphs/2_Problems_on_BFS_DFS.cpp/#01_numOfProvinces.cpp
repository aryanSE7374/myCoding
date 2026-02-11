#include<bits/stdc++.h>
using namespace std;


// --------------------------------------------------------------------------- //

// TC : O(V+2E)
// SC : O(2N)

// using dfs
class Solution {
public:

    void dfs(int v, vector<vector<int>>& adj, vector<int>& visited ) {
        
        visited[v] = 1;

        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=0 ; j<n ; j++ ) {
                if ( isConnected[i][j] ) adj[i].push_back(j);
            }
        }

        vector<int> vis(n,0);
        int cnt = 0;

        for ( int i=0 ; i<n ; i++ ) {
            if ( !vis[i] ) {
                vis[i] = 1;
                cnt++;
                dfs(i,adj,vis);
            }
        }

        return cnt;

    }
};



// --------------------------------------------------------------------------- //

// TC : O(V+2E)
// SC : O(2N)

// using bfs
class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // method 1
        // for ( int i=0 ; i<n ; i++ ) {
        //     for ( int j=0 ; j<n ; j++ ) {
        //         if ( isConnected[i][j] ) adj[i].push_back(j);
        //     }
        // }

        // method 2
        // for ( int i=0 ; i<n ; i++ ) {
        //     for ( int j=0 ; j<n ; j++ ) {
        //         if ( isConnected[i][j] && i!=j ) {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         } 
                    
        //     }
        // }

        // method 3 : best practice
        for ( int i=0 ; i<n ; i++ ) {
            for ( int j=i+1 ; j<n ; j++ ) {
                if ( isConnected[i][j] ) { // avoids self loops naturally
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt = 0;

        for ( int i=0 ; i<n ; i++ ) {
            if ( !vis[i] ) {

                vis[i] = 1;
                cnt++;

                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }

            }
        }

        return cnt;

    }
};

// --------------------------------------------------------------------------- //