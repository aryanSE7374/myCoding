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
#define nl cout << '\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    ll n , m , h ;

    cin >> n >> m >> h ; 

    vll a(n) ;

    // vll a2(n) ;

    // vector < vector< ll > > ops( m , vector< ll >(2) ) ;
    vll b(m) ;
    vll c(m) ;

    f(i,0,n) {
        cin >> a[i] ;
    }
    
    // a2 = a ;

    
    f(i,0,m){
        cin >> b[i] ;
        cin >> c[i] ;
        b[i]--;
    }
    
    // ops
    
    unordered_map< ll , ll > mpp;

    f(i,0,m){

        int t;

        if ( mpp.find(b[i]) != mpp.end() ) {
            t = mpp[b[i]] + c[i] ;
        }
        else {
            t = a[b[i]] + c[i] ;
        }
        
        if ( t > h ) {
            // a2 = a ;
            mpp.clear();
        }
        else {
            // a2[b[i]] = t ;
            mpp[b[i]] = t;
        }
    }

    for ( auto &[ idx , val ] : mpp ) {
        a[idx] = val ;
    }

    f(i,0,n) {
        cout << a[i] <<  " " ;
    }

    nl;
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