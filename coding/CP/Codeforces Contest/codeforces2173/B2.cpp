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

// flag -> 0 : a , 1 : b
ll fun(ll i , ll n , ll k , vll& a , vll& b , vector<vll> dp ){ 

    if( i == n) return k;

    if(dp[k][i] != -1) return dp[k][i];

    return dp[k][i] = max( fun(i+1 , n , k-a[i] , a , b , dp ) , fun(i+1 , n , b[i]-k , a , b , dp ) ); 

}

void SOLVE(){

    ll n;
    ll k = 0;

    cin>>n;

    vll a(n);
    vll b(n);

    f(i,0,n){
        cin >> a[i];
    }

    f(i,0,n){
        cin >> b[i];
    }

    // vector<vll> dp(100000 , vll (n,-1));
    vector<vector<long long>> dp(1000 , vector<long long>(n,-1));
    
    ll ans = fun(0,n,k,a,b,dp);
    cout << ans;

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