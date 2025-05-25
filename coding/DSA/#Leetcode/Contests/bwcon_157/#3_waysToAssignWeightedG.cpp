#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;

        // Step 1: Build the adjacency list.
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Find the farthest node from the root (node 1).
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        int farthestNode = 1, maxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (depth[neighbor] == -1) { // Not visited
                    depth[neighbor] = depth[node] + 1;
                    q.push(neighbor);
                    if (depth[neighbor] > maxDepth) {
                        maxDepth = depth[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }

        // Step 3: Determine the number of edges in the path from root to the farthest node.
        int pathLength = maxDepth;

        // Step 4: Calculate the number of ways to assign weights to the edges such that the total cost is odd.
        // If the path has an odd number of edges, we can make the cost odd by assigning an odd number of edges with weight 1.
        // The number of valid assignments is 2^(pathLength - 1), as each edge weight can independently be 1 or 2.
        long long result = 1;
        for (int i = 0; i < pathLength - 1; ++i) {
            result = (result * 2) % MOD;
        }

        return result;
    }
};