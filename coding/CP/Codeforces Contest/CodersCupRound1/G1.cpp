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
    if ( cat[u] ) {
        curr2++;
    }
    else{
        curr2=0;
    }
    if ( curr2 > maxx ) {
        // vis[u]=0;
        return; 
    }
    vis[u] = 1;
    if ( adj[u].size() == 0 ) {
        cnt++;
        vis[u] = 0;
        return;
    }
    for ( auto& v : adj[u] ) {
        if ( !vis[v] ) {
            dfs ( adj , v , maxx , curr2 , cnt, vis ) ;
        }
    }
    vis[u] = 0;
}

void SOLVE(){

    int n, m;

    cin >> n >> m;

    cat.reserve(n);

    f(i,0,n){
        cin >> cat[i];
    }

    // vector<vector<int>> edges(n-1);

    vector<vector<int>> adj(n);
    vector<int> vis(n,0);

    f (i,0,n-1) {
        int u, v;
        cin >> u >> v;
        // adj[u-1].push_back(v-1);
        int mini = min ( u , v );
        int maxi = max( u, v);
        adj[mini-1].push_back(maxi-1);
    }

    int cnt = 0;

    dfs(adj, 0, m, 0, cnt, vis);

    cout << cnt;


    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}