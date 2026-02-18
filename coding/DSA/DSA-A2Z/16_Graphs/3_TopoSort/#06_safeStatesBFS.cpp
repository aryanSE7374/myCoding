#include<bits/stdc++.h>
using namespace std;

// my code : passed

class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
        }
        
        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( adj[i].size() == 0 ) {
                q.push(i);
            }
        }
        
        adj.clear();
        adj.assign( V , vector<int>() );
        
        
        vector<int> inDegree( V , 0 );
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[v].push_back(u); // reverse edges
            inDegree[u]++;
        }
        
        vector<int> topo;
        
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for ( int v : adj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        
        return topo;
        
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ //

// striver's solution

class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for ( auto e : edges ) {
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
        }

        // Reverse graph
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i); // reverse edge
                indegree[i]++;           // increase indegree of original node
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Nodes with indegree 0 are terminal nodes
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Standard BFS (Kahn's)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ //

// best/optimized implimentation , by ChatGPT

class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjRev(V);
        vector<int> outdegree(V, 0);

        // Single pass over edges
        for (auto &e : edges) {
            int u = e[0], v = e[1];

            adjRev[v].push_back(u);  // reverse edge
            outdegree[u]++;          // count outgoing edges
        }

        queue<int> q;

        // Terminal nodes (original outdegree 0)
        for (int i = 0; i < V; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(V, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (auto prev : adjRev[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (safe[i]) ans.push_back(i);
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ //

// leetcode version

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {

        int V = adj.size();

        queue<int> q;
        
        for ( int i=0 ; i<V ; i++ ) {
            if ( adj[i].size() == 0 ) {
                q.push(i);
            }
        }
        
        vector<vector<int>> revAdj(V);  
        vector<int> inDegree( V , 0 );
        
        for ( int u=0 ; u<V ; u++ ) {
            for ( int v : adj[u] ) {
                revAdj[v].push_back(u); // reverse edges
                inDegree[u]++;
            }
        }
        
        vector<int> topo;
        
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for ( int v : revAdj[u] ) {
                inDegree[v]--;
                if ( inDegree[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        
        sort(topo.begin(),topo.end());
        return topo;
        
    }
};