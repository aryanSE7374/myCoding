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


// GPT brute approach
bool check(ll a1 , ll b1 , ll c1 , ll a2 , ll b2 , ll c2){

    ll da = a1 - a2 ;
    ll db = b1 - b2 ;
    ll dc = c1 - c2 ;

    if ( da < 0 ) return false ;

    if ( da == 0 ){
        if ( db != 0 ) return false ;
        return dc > 0 ;
    }

    return ( db * db - 4 * da * dc ) < 0 ;
}


// DFS
int dfs(int u , const vvi &graph){

    int dmax = 0 ;

    for ( int v : graph[u] ){
        dmax = max( dmax , dfs( v , graph) );
    }

    return 1 + dmax ;
}


void SOLVE(){

    int n;
    cin >> n;

    vll A(n) , B(n) , C(n);

    f(i,0,n){
        cin >> A[i] >> B[i] >> C[i];
    }

    vvi adj(n) , rev_adj(n);

    f(i,0,n){
        f(j,0,n){
            if ( i == j ) continue ;

            if ( check( A[i],B[i],C[i] , A[j],B[j],C[j] ) ){
                adj[i].push_back(j);       // i above j
                rev_adj[j].push_back(i);   // j below i
            }
        }
    }

    vi ans(n);

    f(i,0,n){

        int down = dfs(i , adj);
        int up   = dfs(i , rev_adj);

        ans[i] = down + up - 1 ;
    }

    f(i,0,n){
        cout << ans[i] << ( i==n-1 ? "" : " " );
    }

    cout << '\n';
}


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