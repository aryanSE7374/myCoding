#include<bits/stdc++.h>
using namespace std;

class DSU {

private: 
    vector<int> rank, parent, size;

public:

    DSU(int n){

        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for ( int i=0 ; i<=n ; i++ ) {
            parent[i] = i;
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

// --------------------------------------------------------------------------------------------------------- //

// my try - passed

class Solution {
public:
    int countDisconnectedComponnets( int V , vector<vector<int>>& edges ) {

        DSU djs(V);

        for ( auto e : edges ) {
            int u = e[0] , v=e[1];
            djs.unionBySize(u, v);
        }

        int cnt = 0;
        for ( int u=0 ; u<V ; u++ ) {
            if ( djs.findUltimateParent(u) == u ) cnt++;
        }

        return cnt;

    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        int e = connections.size();

        if ( e < n-1 ) return -1;

        int numOfDisconnectedComponents = countDisconnectedComponnets(n, connections);
        return numOfDisconnectedComponents - 1;

    }
};

// --------------------------------------------------------------------------------------------------------- //

// striver's solution

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int e = connections.size();

        if ( e < n-1 ) return -1;

        int cntC = 0; // num of disconnected components
        int cntExtras = 0; // extra edges

        DSU djs(n);

        for ( auto e : connections ) {
            int u = e[0] , v=e[1];
            if ( djs.findUltimateParent(u) == djs.findUltimateParent(v) ) {
                cntExtras++;
            }
            else {
                djs.unionBySize(u, v);
            }
            
        }

        for ( int u=0 ; u<n; u++ ) {
            if ( djs.findUltimateParent(u) == u ) cntC++;
        }


        int ans = cntC - 1;
        return (cntExtras >= ans) ? ans : -1; 

    }
};
