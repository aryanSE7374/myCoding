#include<bits/stdc++.h>
using namespace std;

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

// striver's solution

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = 0;
        int maxc = 0;
        for ( auto stone : stones ) {
            maxr = max (maxr, stone[0]) ;
            maxc = max (maxc, stone[1]) ;
        }
        DSU djs( maxr + maxc + 1);

        unordered_map<int, int> stoneNodes;
        for ( auto stone : stones ) {
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxr + 1;
            djs.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;

        for ( auto it : stoneNodes ) {
            if (djs.findUltimateParent(it.first) == it.first ) {
                cnt++;
            } 
        }

        return n-cnt;
        
    }
};