// NOTE : binary search se nahi kia , DP se kia h so no cheating anymore

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

vector<vector<ll>> dp;

ll dfs( int idx , int k , vll &pref , int n ){

    if ( k == 1 ){
        return pref[n] - pref[idx];
    }

    if ( dp[idx][k] != -1 ){
        return dp[idx][k];
    }

    ll ans = LLONG_MAX;

    for ( int i = idx ; i < n - 1 ; i++ ){

        ll lSum = pref[i + 1] - pref[idx];
        ll rSum = dfs( i + 1 , k - 1 , pref , n );

        ans = min( ans , max( lSum , rSum ) );
    }

    return dp[idx][k] = ans;
}

void SOLVE(){

    int n , k;
    cin >> n >> k;

    vll nums(n);
    f(i,0,n){
        cin >> nums[i];
    }

    // pref sum
    vll pref( n + 1 , 0 );
    f(i,0,n){
        pref[i + 1] = pref[i] + nums[i];
    }

    dp.assign( n , vll( k + 1 , -1 ) );

    cout << dfs( 0 , k , pref , n );
    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while ( t-- > 0 ){
        SOLVE();
    }

    return 0;
}