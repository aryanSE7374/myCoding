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


ll x;
// map<pll, ll> dp;

unordered_map<ll, unordered_map<ll, ll>> dp;

ll fun(ll a, ll b) {

    if (a == b) return 0;
    
    if (a<b) {
        ll temp = a;
        a = b;
        b = temp;
    }

    if ( (dp.find(a) != dp.end()) && (dp[a].find(b)) != dp[a].end())  return dp[a][b];

    ll ans = a - b;

    if (a > 0) {
        ans = min( ans , 1 + fun(a/x, b) );
    }

    if (b > 0) {

        // ll diff = (x - (b % x));
        // ans = min(ans, diff + 1 + fun(a, (b + diff) / x));
        ans = min( ans, 1 + fun( a, b/x ) );
    }

    // return dp[{a, b}] = ans;
    return dp[a][b] = ans;
}


// ll fun (ll a, ll b, ll x) {

//     if (a==b) return 0;

//     if (a<b) {
//         ll temp = a;
//         a = b;
//         b = temp;
//     }

//     ll ans = a-b;
//     ans = min( ans, 1 + fun(a/x, b/x, x));

//     ll diff = x-(b%x);
//     ans = min (ans, diff + 1 + fun(a, (b+diff)/x, x));

//     return ans;
    
// }


void SOLVE(){

    ll a, b, X;

    cin >> a >> b >> X;

    dp.clear();

    x = X;
    cout << fun(a, b);

    // int moves = 0;

    // while ( llabs(a-b) >= 3 ) {
    //     if (a>b) {
    //         a /= x;
    //     }
    //     else {
    //         b /= x;
    //     }
    //     moves++;
    // }

    // if (a==b) {
    //     cout << moves;
    // }
    // else if ( (llabs(a-b))%x == 0 ) {
    //     cout << moves + 1;
    // }
    // else {
    //     cout << moves + llabs(a-b);
    // }

    // cout << fun (a, b, x);


    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}