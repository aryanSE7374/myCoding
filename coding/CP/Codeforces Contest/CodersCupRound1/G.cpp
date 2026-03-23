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

void dfs ( vector<vector<int>>& adj, int u, int& maxx, int curr, int& cnt ) {
    int curr2 = curr;
    if ( cat[u] ) {
        curr2++;
    }
    else{
        curr2=0;
    }
    if ( curr2 > maxx ) {
        return;
    }
    if ( adj[u].size() == 0 ) {
        cnt++;
        return;
    }
    for ( auto& v : adj[u] ) {
        dfs ( adj , v , maxx , curr2 , cnt ) ;
    }
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

    f (i,0,n-1) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    int cnt = 0;

    dfs(adj, 0, m, 0, cnt);

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