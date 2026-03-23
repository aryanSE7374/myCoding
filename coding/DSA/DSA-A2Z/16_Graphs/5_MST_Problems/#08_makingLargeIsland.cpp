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

// Time:  O(N²)
// Space: O(N²)

class Solution {
public:
    bool isValid ( int n, int r, int c) {
        return ( 0<=r && r<n && 0<=c && c<n );
    } 
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DSU djs(n*n);

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        // step 1 - connect components based on neighbour
        for ( int row = 0; row < n; row++ ) {
            for ( int col = 0; col < n; col++ ) {
                if ( grid[row][col] == 0 ) continue;
                int nodeNo = n*row + col;
                for ( int ind=0; ind<4; ind++ ) {
                    int newr = row+drow[ind];
                    int newc = col+dcol[ind];
                    if ( isValid(n,newr,newc) && grid[newr][newc]==1 ) {
                        int adjNodeNo = n*newr + newc;
                        djs.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }


        // step 2 - check for each 0 converted to 1
        int maxi = 0;
        for ( int row = 0; row < n; row++ ) {
            for ( int col = 0; col < n; col++ ) {
                if ( grid[row][col] == 1 ) continue;
                set<int> components;
                for ( int ind=0; ind<4; ind++ ) {
                    int newr = row+drow[ind];
                    int newc = col+dcol[ind];
                    if ( isValid(n,newr,newc) && grid[newr][newc]==1 ) {
                        int adjNodeNo = n*newr + newc;
                        components.insert(djs.findUltimateParent(adjNodeNo));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += djs.size[it];
                }
                maxi = max(maxi, sizeTotal+1);
            }
        }

        // edge case for all ones
        for ( int cellNo=0; cellNo < n*n; cellNo++) {
            maxi = max (maxi, djs.size[djs.findUltimateParent(cellNo)]);
        }

        return maxi;


    }
};