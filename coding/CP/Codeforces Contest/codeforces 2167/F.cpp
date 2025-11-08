#include <bits/stdc++.h>
using namespace std;

#define ll long long


// Gemini Solution

const int limit = 200000;
vector<int> g[limit];
int n , k;
int subT[limit];

void dfs(int u, int p) {
    subT[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        subT[u] += subT[v];
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);

    ll total = 0;

    for (int v = 1; v <= n; v++) {
        ll bad_roots = 0;

        // For each child of v — subT component
        for (int c : g[v]) {
            int sz = (subT[c] < subT[v]) ? subT[c] : (n - subT[v]);
            // The check below ensures we get the correct component size
            // For children (downward), it's subT[c]
            // For parent side (upward), it's n - subT[v]
        }

        // We must collect all components properly:
        vector<int> comps;
        for (int c : g[v]) {
            if (subT[c] < subT[v]) comps.push_back(subT[c]);
        }
        if (n - subT[v] > 0) comps.push_back(n - subT[v]);

        for (int sz : comps) {
            if (n - sz < k) bad_roots += sz;
        }

        ll count_v = n - bad_roots;
        total += count_v;
    }

    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}