#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> inDegree(V,0);
        
        for ( auto e : prerequisites ) {
            // reversed order
            int u = e[0] , v = e[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        vector<int> vis(V,0);
        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( inDegree[i] == 0 ) {
                q.push(i);
            }
        }
        
        int cnt = 0 ;
        vector<int> order;
        
        while ( !q.empty()) {
            
            int u = q.front();
            q.pop();
            vis[u] = 1;
            cnt++;
            order.push_back(u);
            
            for ( int v : adj[u] ) {
                if ( !vis[v] ) {
                    inDegree[v]--;
                    if ( inDegree[v] == 0 ) {
                        q.push(v);
                    }
                }
            }
        }
        
        if ( cnt == V ) return order ;
        else return {};
    }
};