#include<bits/stdc++.h>
using namespace std;

class DSU {

private: 
    vector<int> rank, parent, size;

public:

    DSU(int n){

        rank.resize(n+1, 0);
        parent.resize(n+1);
        // size.resize(n+1,1);

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
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        int E = edges.size();
        vector<vector<int>> modifiedEdges(E);
        
        for ( int i = 0 ; i<E ; i++ ) {
            int u = edges[i][0] , v = edges[i][1] , w = edges[i][2];
            modifiedEdges[i] = {w,u,v};
        }
        
        sort ( modifiedEdges.begin(), modifiedEdges.end() );
        
        int cost = 0;
        DSU djs = DSU(V);
        
        for ( auto e : modifiedEdges ) {
            
            int w = e[0] , u = e[1] , v = e[2];
            
            int Pu = djs.findUltimateParent(u);
            int Pv = djs.findUltimateParent(v);
            
            if ( Pu != Pv ) {
                djs.unionByRank(u, v);
                cost += w;
            }
            
        }
        
        return cost;
        
    }
};