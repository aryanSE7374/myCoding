/*
code by - Aryan Shrivastav
*/

/*
observations :
- In one operation, at most one node per depth can be colored
- Nodes at same depth can never be colored together
- Hence, minimum operations = maximum frequency of any depth
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

/* ------------------ GLOBALS ------------------ */
vector<vi> adj;
vi distance_from_root;

/* ------------------ BFS DISTANCE ------------------ */
void compute_distances(int n) {
    queue<int> q;
    q.push(1);
    distance_from_root[1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distance_from_root[v] == -1) {
                distance_from_root[v] = distance_from_root[u] + 1;
                q.push(v);
            }
        }
    }
}

/* ------------------ SOLVE FUNCTION ------------------ */
void SOLVE() {

    int n;
    cin >> n;

    adj.assign(n + 1, vi());
    distance_from_root.assign(n + 1, -1);

    f(i,0,n-1){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // compute distances from root
    compute_distances(n);

    // count frequency of each depth
    unordered_map<int,int> cnt;
    int ans = 0;

    f(i,1,n+1){
        cnt[distance_from_root[i]]++;
        ans = max(ans, cnt[distance_from_root[i]]);
    }

    cout << ans;
    co_endl;
}

/* ------------------ MAIN ------------------ */
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        SOLVE();
    }

    return 0;
}