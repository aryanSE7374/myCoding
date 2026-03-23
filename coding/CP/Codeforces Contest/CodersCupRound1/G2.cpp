/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)

vi cat;

void dfs ( vector<vector<int>>& adj, int u, int& maxx, int curr, int& cnt, vector<int>& vis ) {
    
    int curr2 = curr;

    if ( cat[u] ) curr2++;
    else curr2 = 0;

    if ( curr2 > maxx ) return;

    vis[u] = 1;

    bool isLeaf = true;

    for ( auto& v : adj[u] ) {
        if ( !vis[v] ) {
            isLeaf = false;
            dfs ( adj , v , maxx , curr2 , cnt, vis );
        }
    }

    if ( isLeaf ) cnt++;

    vis[u] = 0;
}

void SOLVE(){

    int n, m;
    cin >> n >> m;

    cat.resize(n);

    f(i,0,n){
        cin >> cat[i];
    }

    vector<vector<int>> adj(n);
    vector<int> vis(n,0);

    f (i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;

    dfs(adj, 0, m, 0, cnt, vis);

    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while(t--){
        SOLVE();
    }
    return 0;
}