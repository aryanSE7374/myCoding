#include<bits/stdc++.h>
using namespace std;

// for undirected graphs

vector<vector<int>> matToList ( vector<vector<int>>& matrix ) {

    int n = matrix.size();
    vector<vector<int>> adj(n);

    for ( int i=0 ; i<n ; i++ ) {
        for ( int j=i+1 ; j<n ; j++ ) {
            if ( matrix[i][j] ) { // avoids self loops naturally
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

}

// for directed without self loops

vector<vector<int>> matToList ( vector<vector<int>>& matrix ) {

    int n = matrix.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

}

// for directed with self loops

vector<vector<int>> matToList ( vector<vector<int>>& matrix ) {

    int n = matrix.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

}