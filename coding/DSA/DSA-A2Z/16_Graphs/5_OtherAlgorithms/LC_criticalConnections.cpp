#include<bits/stdc++.h>
using namespace std;

// Find Bridges in Graph

// LC-1192 : https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    int timer = 1;
    void dfs (int u, int parent, vector<vector<int>>& adj, 
            vector<int>& vis, vector<int>& inTime, vector<int>& lowTime, 
            vector<vector<int>>& ans) {

        vis[u] = 1;
        inTime[u] = timer;
        lowTime[u] = timer;
        timer++;

        for ( auto v : adj[u] ) {
            if ( v == parent )  continue;
            if ( !vis[v] ) {
                dfs(v, u, adj, vis, inTime, lowTime, ans);
                lowTime[u] = min(lowTime[u], lowTime[v]);
                if ( (inTime[u] < lowTime[v]) ) {
                    ans.push_back({u,v});
                }
            }        
            else{
                lowTime[u] = min(lowTime[u], lowTime[v]);
            }
        }


    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int>() );
        vector<vector<int>> ans;

        for ( auto& ed : connections ) {
            int u = ed[0], v = ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> inTime(n);
        vector<int> lowTime(n);

        dfs ( 0, -1, adj, vis, inTime, lowTime, ans );
        return ans;
    }
};