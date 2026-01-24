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


ll fun( vll &a , vector<pair<ll,ll>> &vines ){

    ll ans = 0;

    f(i,0,a.size()){

        f(j,0,vines.size()){

            ll orb = a[i];
            ll resist = vines[j].first;
            ll dark = vines[j].second;

            if ( orb >= resist ){

                vll newa = a;
                vector<pair<ll,ll>> newVines = vines;

                newa.erase( newa.begin() + i );

                if ( dark > 0 ){
                    newa.push_back( max( orb , dark ) );
                }

                newVines.erase( newVines.begin() + j );

                ans = max( ans , 1 + fun( newa , newVines ) );

            }

        }

    }

    return ans;

}

void SOLVE(){

    int n , m ;
    cin >> n >> m ;

    vll a(n);

    f(i,0,n){
        cin >> a[i];
    } 
        

    vll b(m) ;
    vll c(m) ;

    f(i,0,m) cin >> b[i];
    f(i,0,m) cin >> c[i];

    vector<pair<ll,ll>> vines;

    f(i,0,m){
        vines.push_back( { b[i] , c[i] } ) ;
    }

    cout << fun( a , vines );

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