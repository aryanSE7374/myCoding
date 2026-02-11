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



void SOLVE(){

    ll n; 
    cin >> n;

    vll a(n) , b(n);

    f(i,0,n){
        cin >> a[i] ;
    }

    vll pref(n+1); // prefix b

    ll maxi = 0;

    f(i,0,n){
        cin >> b[i] ;
    }

    pref[0] = b[0];
    f(i,1,n){
        pref[i] = pref[i-1] + b[i];
        if ( pref[i] <= n ) {
            maxi = max ( maxi , pref[i] );
        }
    }

    sort ( a.rbegin() , a.rend() ) ;

    // ll ans = maxi * mini ;
    ll ans = 0 ;

    f(i, 0, n){

        if ( pref[i] > n ) break;

        ll score = (i+1) * a[ pref[i] - 1 ];
        ans = max ( ans , score );

    }

    cout << ans;
    
    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}
