/*
code by - Aryan Shrivastav
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    ll n, m, k;
    cin >> n >> m >> k;

    // if ( n+k-3 <= m ) {
    //     cout << n << "\n";
    //     return;
    // }

    ll left = k-1 ;
    ll right = n-k ;

    ll mini = min( left , right );
    ll maxi = max( left , right );

    // (2 * mini) + mini - 1 = (3 * mini) - 1
    // if mini == 0 : ans = 0.
    ll addMini = ( mini == 0 ) ? 0 : ( 3 * mini - 1 ) ;

    ll ans = 0;

    if ( m >= addMini) {
        
        ll T = (m + 1 + mini) / 2;
        
        ans = min(T , mini + maxi );
    } 
    else {
        
        ll T = 2 * (m + 1) / 3;

        while (1) {
            ll curr = T + (T + 1) / 2 - 1;
            
            if (T == 0) curr = 0;

            if (curr <= m) break;

            T--;

        }

        ans = T;

    }
    cout << ans + 1 ;
    
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