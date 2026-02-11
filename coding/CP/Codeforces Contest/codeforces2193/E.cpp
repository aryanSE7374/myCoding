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



// spf table

vll spf;

ll INF = 1e9;

vll stt;
vector<ll> dp;

// rec func

ll func(ll x){

    if( x == 1 ) return 0;

    if( dp[x] != -1 ) return dp[x];

    ll ans = INF;

    for ( ll num : stt ){ 

        if ( num==1 ) continue;
        if ( num > x ) break;

        if ( x % num == 0 ) {
            ll rem = func( x / num );
            if( rem != INF ){
                ans = min(ans, rem + 1);
            }
        }

    }

    return dp[x] = ans;

}

void SOLVE(){

    ll n ;
    cin >> n ;

    vll a(n);

    f(i,0,n) cin >> a[i];
    
    /*
    set<ll> st;
    // unordered_set<ll> st;
    f(i,0,n){
        cin >> a[i];
        st.insert(a[i]);
    }

    int sz = st.size();

    vll a2(sz);
    f(i,0,sz){
        // a2[i] = st.begin();
        st.erase(st.begin());
    }


    unordered_map< ll , ll > ans;

    f(i,0,n){

        ll num = i+1;
        
        if( ans.find(num) != ans.end() ){
            cout << ans[num] << " ";
        }
        else{

            int N = num ; // preserve num
            int cnt = 0;

            // for( all spfs over spf till spf[j] <= num ){

            //     while( num%spf[j] == 0 ) num /= spf[j];
                
            //     cnt++;
            // }

            if( num > 0 ){
                ans[N] = -1;
                cout << -1 << " ";
            }
            else{ 
                ans[N] = cnt;
                cout << cnt << " ";
            }
        }

    }

    */

    // vector<int> freq(n+1, 0);
    // dp.assign(n+1, -1);

    // f(i,0,n){
    //     freq[a[i]] = 1;
    // }

    // stt.clear();

    // f(i,1,n+1){
    //     if(freq[i]) stt.push_back(i);
    // }


    // f(i,1,n+1){

    //     ll res = func(i);

    //     if (res == INF || res == 0 ) cout << -1 << " ";

    //     else cout << res << " ";

    // }

    vector<int> freq(n+1, 0);

    f(i,0,n){
        if(a[i] <= n) freq[a[i]] = 1;
    }

    dp.assign(n+1, INF);

    dp[1] = 0;

    for(ll i = 1 ; i <= n ; i++){

        if(dp[i] == INF) continue;

        for(ll j = 1 ; j * i <= n ; j++){

            if(freq[j]){
                dp[i * j] = min(dp[i * j] , dp[i]+1 );
            }

        }

    }

    f(i,1,n+1){

        if(i == 1){
            if(freq[1]) cout << 1 << " ";
            else cout << -1 << " ";
        }
        else{
            if(dp[i] == INF) cout << -1 << " ";
            else cout << dp[i] << " ";
        }

    }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    // int N = 1e5;
    // spf.assign(N+1 , 0);

    // for(int i = 1 ; i <= N ; i++){
    //     spf[i] = i;
    // }

    // for(int i = 2 ; i * i <= N ; i++){

    //     if( spf[i] == i ){

    //         for(int j = i * i ; j <= N ; j += i){

    //             if( spf[j] == j ){
    //                 spf[j] = i;
    //             }

    //         }

    //     }

    // }

    while(t--){

        SOLVE();

    }

    return 0;
}