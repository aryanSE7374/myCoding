// EXTRA HARD QUES

// https://leetcode.com/problems/minimum-operations-to-equalize-binary-string

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {

        int n = s.size();
        int m = 0;
        const int INF = 1e9;
        
        vector<int> dist(n + 1, INF);
        vector<set<int>> nodeSets(2); // 0 for even and 1 for odd
                                      // set of all unvisited nodes (count of zeroes)

        for (int i = 0; i <= n; i++) {
            nodeSets[i%2].insert(i);
            if ( (i<n) && (s[i] == '0') ) {
                m++;
            }
        }

        // dijkstra(bfs-shortes path) for destination m = 0 , from src = m (current)
        queue<int> q;
        q.push(m);

        dist[m] = 0; // source node is initial zeroes count
        nodeSets[m%2].erase(m); // from parity set, remove curr m to mark visited 
                                // or unmark unvisited

        while (!q.empty()) {
            m = q.front();
            q.pop();
            
            int c1 = max( k-n+m , 0 ) , c2 = min( m , k ); // range of selecting valid c

            int lnode = m + k - (2*c2); 
            int rnode = m + k - (2*c1);

            auto& nodeSet = nodeSets[lnode % 2]; // parity set
            
            for (auto it = nodeSet.lower_bound(lnode);
                 it != nodeSet.end() && *it <= rnode;) {

                int m2 = *it;
                dist[m2] = dist[m] + 1; // simple bfs relaxation
                q.push(m2);
                it = next(it); // it must be updated here only and not in the for loop sytnax
                               // if updated within the loop, gives WA bcoz it becomes invalid after erase opn
                nodeSet.erase(m2); // mark visited

            }
        }
        return dist[0] == INF ? -1 : dist[0];
    }
};