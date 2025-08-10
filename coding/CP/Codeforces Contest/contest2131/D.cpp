#include <bits/stdc++.h>
using namespace std;

pair<int,int> bfs(int start, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthestNode = start;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] > dist[farthestNode]) farthestNode = v;
            }
        }
    }
    return {farthestNode, dist[farthestNode]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n-1; i++) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find diameter
        auto [A, _] = bfs(1, adj);
        auto [B, diameter] = bfs(A, adj);

        int ops = 0;
        if(diameter > 2) {
            ops = (diameter - 2 + 1) / 2; // ceil((diameter - 2)/2)
        }
        cout << ops << "\n";
    }
}