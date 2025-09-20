#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<array<long long, 4>> edges; 
    edges.reserve(n - 1);

    for (int i = 0; i < n - 1; i++) {
        long long u, v, x, y;
        cin >> u >> v >> x >> y;
        edges.push_back({u, v, x, y});
    }

    // TODO: add your logic here

    // Example dummy output (permutation 1..n)
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout<<endl;
}

int main() {

    int t;
    cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}