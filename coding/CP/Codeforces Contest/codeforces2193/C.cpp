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

    ll n , q ;

    cin >> n >> q;

    vll a(n);
    vll b(n);

    vector< vll > queries( q , vll(2) );

    f(i,0,n) {
        cin >> a[i] ;
    }

    f(i,0,n) {
        cin >> b[i] ;
    }

    f(i,0,q) {

        ll l , r ;
        cin >> l >> r ;

        queries[i][0] = l;
        queries[i][1] = r;

    }

    // ---- //

    vll mx(n);
    mx[n-1] = max ( a[n-1] , b[n-1] ) ;

    vll prefmx(n+1,0);
    prefmx[0] = 0;


    for ( int i=n-2 ; i>=0 ; i-- ) {
        mx[i] = max ( { a[i] , b[i] , mx[i+1] } );
    }

    f(i,1,n+1){
        prefmx[i] = mx[i-1] + prefmx[i-1];
    }

    // ---- //

    f(i,0,q){

        ll l = queries[i][0] , r = queries[i][1] ;

        cout << prefmx[r]-prefmx[l-1] << " " ;

    }


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