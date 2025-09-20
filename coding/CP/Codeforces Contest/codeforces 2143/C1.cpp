#include <bits/stdc++.h>
using namespace std;

struct EdgeInfo {
    int to;
    int x, y;
};

// void solve() {
//     int n;
//     cin >> n;
//     vector<vector<EdgeInfo>> adj(n + 1);
//     for (int i = 0; i < n - 1; ++i) {
//         int u, v, x, y;
//         cin >> u >> v >> x >> y;
//         adj[u].push_back({v, x, y});
//         adj[v].push_back({u, x, y});
//     }
//     vector<int> p(n,0);
//     for (int i = 0; i < n; ++i) {
//         cout << p[i] << (i == n - 1 ? "" : " ");
//     }
// }

void solve() {

    int n;
    cin>>n;

    vector<int> values(n + 1, 0);

    for(int i=0 ; i<n-1 ; i++){
        int u, v, x, y;
        cin>>u;
        cin>>v;
        cin>>x;
        cin>>y;

        if(x>y){
            values[u]++;
        } 
        else if(y>x){
            values[v]++;
        }
    }

    vector<int> nodes(n,0);

    for(int i=0 ; i<n ; i++){
        nodes[i]=i+1;
    }

    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        return ( values[a]>values[b] );
    });

    vector<int> p(n+1 , 0);
    int value = n;
    for(int u : nodes){
        p[u] = value--;
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? "" : " ");
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