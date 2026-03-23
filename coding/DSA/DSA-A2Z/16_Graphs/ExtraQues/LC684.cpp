#include<bits/stdc++.h>
using namespace std;

// claims
/*
adding one extra edg will led to only 1 cycle
*/


// try 1 : failed

class Solution {
public:
    vector<int> dfs ( int u, vector<int>& vis, vector<vector<int>>& adj, vector<int>& path, int& start, int& end ) {
        vis[u] = 1;
        for ( auto& v : adj[u] ) {
            if ( !vis[v] ) {
                path.push_back(v);
                dfs( v, vis, adj, path, start, end );
                // path.pop_back();
            }
            else {
                start = v;
                end = u;
                return path;
            }
        }
        
        path.pop_back();
        return path;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int maxi = 0;
        for ( auto& e : edges ) {
            maxi = max(maxi, e[0]);
            maxi = max(maxi, e[1]);
        }

        vector<vector<int>> adj(maxi+1, vector<int>());
        vector<int> vis(maxi+1, 0);

        for ( auto& e : edges ) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> path = {1};
        int start = 1;
        int end = 1;
        dfs(1, vis, adj, path, start, end);
        cout << start << " " << end << "\n";

        vector<int> vis2(maxi+1, 0);

        cout << "path : ";
        bool flag = false;
        for ( int i=0; i<path.size(); i++ ) {
            if ( path[i] == start ) flag = true;
            if ( flag ) {
                vis2[path[i]] = 1;
                cout << path[i] << " ";
            }
            if ( path[i] == end ) flag = false;
        }

        int edgeCount = edges.size();
        for ( int i=edgeCount-1; i>=0; i-- ) {
            int u = edges[i][0], v = edges[i][1];
            if ( vis2[u] == 1 && vis2[v] == 1 ) return {u, v};
        }

        return edges[0];

    }
};

// ------------------------------------------------------------------------------------------------------ //

// try 2 using DSU : passed - intended approach


class DSU {
public:
    vector<int> rank, parent, size;

    DSU(int n){

        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for ( int i=0 ; i<=n ; i++ ) {
            parent[i] = i;
            // size[i] = 1;
        }

    }

    int findUltimateParent (int node) {
        if ( node == parent[node] ) return node;
        return parent[node] = findUltimateParent( parent[node] );
    }

    void unionByRank( int u, int v ) {
        int ult_Pu = findUltimateParent(u);
        int ult_Pv = findUltimateParent(v);

        if ( ult_Pu == ult_Pv ) return;
        
        if ( rank[ult_Pu] < rank[ult_Pv] ) {
            parent[ult_Pu] = ult_Pv;
        }

        else if ( rank[ult_Pv] < rank[ult_Pu] ) {
            parent[ult_Pv] = ult_Pu;
        }

        else{
            parent[ult_Pv] = ult_Pu;
            rank[ult_Pu]++;
        }
    }

    void unionBySize( int u, int v ){ 
        int ult_Pu = findUltimateParent(u);
        int ult_Pv = findUltimateParent(v);

        if ( ult_Pu == ult_Pv ) return;
        
        if ( size[ult_Pu] < size[ult_Pv] ) {
            parent[ult_Pu] = ult_Pv;
            size[ult_Pv] += size[ult_Pu];
        }

        else{
            parent[ult_Pv] = ult_Pu;
            size[ult_Pu] += size[ult_Pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU djs(n+1);
        vector<int> ans = {0, 0};
        for ( auto& e : edges ) {
            int u = e[0], v = e[1];
            int Pu = djs.findUltimateParent(u);
            int Pv = djs.findUltimateParent(v);
            // cout << "u: " << u << " , v: " << v << "\n";
            cout << "parent-u: " << Pu << " , parent-v: " << Pv << "\n";
            if ( Pu == Pv ) {
                return {u, v};
                // ans[0] = u, ans[1] = v;
                // cout << "ans: { " << u << " , " << v << " }\n";
            }
            else {
                // cout << "performing union operation on u and v... \n";
                djs.unionBySize(u, v);
            }
        }
        return ans; // dummy return
    }
};

// ---------------------------------------------------------------------------------------------------------------- // 

// try 3 - very complex implementation

class Solution {
public:

    void dfs (int u, int parent, int& start, bool& flag, vector<int>& path, vector<int>& vis, vector<vector<int>>& adj) {
        vis[u] = 1;
        for ( auto& v : adj[u] ) {
            if ( v == parent ) continue;
            if ( !vis[v] && (start == -1) ) {
                dfs( v, u, start, flag, path, vis, adj );
            }
            else if (start == -1) {
                start = v;
            }
        }
        if ( start != -1 && flag ) {
            path.push_back(u);
        }
        if ( u == start ) flag = false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> vis(n+1, 0);
        vector<vector<int>> adj(n+1);

        for ( auto& e : edges ) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> path;
        int start = -1;
        bool flag = true;

        dfs (1, 0, start, flag, path, vis, adj );
        vector<int> vis2(n+1, 0);
        for ( auto node : path ) {
            vis2[node] = 1;
        }

        for ( int i=n-1; i>=0 ; i-- ) {
            int u = edges[i][0], v = edges[i][1];
            if ( (vis2[u] == 1) && (vis2[v] == 1) ) {
                return {u, v};
            }
        }

        return {0, 0};

    }
};