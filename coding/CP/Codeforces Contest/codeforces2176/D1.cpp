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

ll fun(int u, ll prev){

    ll paths = 0;
    
    for (int v : adj[u]){
        if ( A[v] == ( A[u] + prev) ){
            paths = (paths + 1 + fun(v, A[u])) % MOD;
        }
    }

    return paths;
}

// In main, you would sum up fun(v, A[u]) for every edge (u, v) + M (for the edges themselves)

void SOLVE(){

    int n;

    cin>>n;

    


    co_endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}
