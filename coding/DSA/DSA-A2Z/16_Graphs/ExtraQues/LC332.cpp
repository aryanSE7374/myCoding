// https://leetcode.com/problems/reconstruct-itinerary/description/

// NOT SOLVED YET - submitted for teaching purpose

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<string, vector<string>> &adj,
             vector<string> &path, string u)
    {
        while (!adj[u].empty()) {
            string v = adj[u].back();
            adj[u].pop_back();
            dfs(adj, path, v);
        }
        path.push_back(u);
    }

    vector<string> buildPath(string source,
                             unordered_map<string, vector<string>>& adj)
    {
        vector<string> path;
        dfs(adj, path, source);
        reverse(path.begin(), path.end());
        return path;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string,int> indegree, outdegree;
        set<string> nodes;

        for (auto &t : tickets) {
            adj[t[0]].push_back(t[1]);
            indegree[t[1]]++;
            outdegree[t[0]]++;
            nodes.insert(t[0]);
            nodes.insert(t[1]);
        }

        for (auto &p : adj) {
            sort(p.second.rbegin(), p.second.rend()); 
        }

       
        string source = "JFK";

        for (auto &node : nodes) {
            if (outdegree[node] >indegree[node] ) {
                source = node;     
                break;
            }
            
        }


        
        if (source == "") {
            source = *nodes.begin();
        }

        return buildPath(source, adj);
    }
};
