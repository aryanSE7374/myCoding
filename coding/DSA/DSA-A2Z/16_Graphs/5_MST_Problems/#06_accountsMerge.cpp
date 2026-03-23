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

// --------------------------------------------------------------------------------------------------------- //

// my try - passed
// Time:  O(N * M log M * 4a) {a is inverse ackernman function}
// Space: O(N * M)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DSU djs(n);

        vector< set<string> > mergedEmails(n);

        unordered_map<string, int> mpp;

        for ( int u=0 ; u<n ; u++ ) {
            for ( int v=1 ; v<accounts[u].size() ; v++ ) {
                if ( mpp.find(accounts[u][v]) == mpp.end() ) {
                    mpp[accounts[u][v]] = u;
                }
                else {
                    djs.unionBySize( u , mpp[accounts[u][v]] );
                }
            }
        }

        for ( auto &[em, u] : mpp ) {
            int Pu = djs.findUltimateParent(u);
            mergedEmails[Pu].insert(em);
        }

        vector<vector<string>> ans;

        for ( int u=0 ; u<n ; u++ ) {
            if ( mergedEmails[u].size() > 0 ) {
                vector<string> temp;
                temp.push_back(accounts[u][0]);
                for ( auto it : mergedEmails[u] ) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }

        return ans;
        
    }
};

// --------------------------------------------------------------------------------------------------------- //

// striver's solution : more effiecient
// Time:  O(N * M log M * 4a) {a is inverse ackernman function}
// Space: O(N * M)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DSU djs(n);

        unordered_map<string, int> mapMailNode;

        for ( int u=0 ; u<n ; u++ ) {
            for ( int v=1 ; v<accounts[u].size() ; v++ ) {
                string mail = accounts[u][v];
                if ( mapMailNode.find(mail) == mapMailNode.end() ) {
                    mapMailNode[mail] = u;
                }
                else {
                    djs.unionBySize( u , mapMailNode[mail] );
                }
            }
        }

        vector<vector<string>> mergedEmails(n);

        for ( auto& it : mapMailNode ) {
            string mail = it.first;
            int node = djs.findUltimateParent(it.second);
            mergedEmails[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for ( int u=0 ; u<n ; u++ ) {
            if ( mergedEmails[u].size() == 0 ) continue;
            sort ( mergedEmails[u].begin(), mergedEmails[u].end() );
            vector<string> temp;
            temp.push_back(accounts[u][0]); // name
            for ( auto& it : mergedEmails[u] ) {
                temp.push_back(it); // emails
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};

// --------------------------------------------------------------------------------------------------------- //