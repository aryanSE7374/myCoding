/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

ll MOD = 998244353;

ll dfs(vector<ll>& A , int u, ll prev , vector<int>& visited , vector<vector<int>>& adj){
    ll ans = 0;
    visited[u] = 1;

    for(int v : adj[u]){

        if(visited[v]) continue;

        if(A[v] == A[u] + prev){
            ans = (ans + 1) % MOD;
            ans = (ans + dfs(A,v, A[u],visited,adj)) % MOD; 
        }
    }

    visited[u] = 0;
    return ans;
}

void SOLVE(){
    int n, m;
    cin >> n >> m;

    vector<ll> A(n+1,0LL);
    vector<vector<int>> adj(n+1 , vector<int>());
    vector<int> visited(n+1,0);

    for( int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll ans = 0;

    for(int u = 1 ; u <= n ; u++){
        for( int v : adj[u] ){
            ans = ( ans + 1 ) % MOD;           
            ans = ( ans + dfs(A , v , A[u] , visited , adj) ) % MOD;
        }
    }

    cout << ans % MOD << "\n";
}


int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}
