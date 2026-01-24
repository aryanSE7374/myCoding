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


int mini ;
unordered_map<ll,int> dp;

void fun(long long n, int t, long long k) {

    if ( t >= mini ) return;

    if (dp.count(n) && dp[n] <= t) return;
    dp[n] = t;

    if ( n == k ) {
        mini = min(mini, t);
        return;
    }

    if ( n < k ) return;

    fun ( (n/2) , t+1 , k ); // floor
    fun ( (n + 1)/2, t+1 , k );  // Ceil

}


void SOLVE(){

    ll n , k ;

    cin >> n >> k ;

    mini = INT_MAX ;

    dp.clear() ;
    
    fun (n,0,k);

    if ( mini == INT_MAX ) cout << -1;
    else cout << mini;
    // cout << (mini == INT_MAX) ? -1 : mini ;

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}