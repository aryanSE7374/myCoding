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

    ll n , X ;
    cin >> n >> X ;

    vector< vll > V(n , vll(3)) ;

    ll M = 0 ;
    ll maxi = 0 ;

    ll am = 0 ;
    ll cm = 0 ;

    f( i,0,n ) {

        ll a , b , c ;

        cin >> a >> b >> c ;
        V[i][0] = a ;
        V[i][1] = b ;
        V[i][2] = c ;

        M += ( a*(b-1) ) ;

        ll temp = (a*b) - c ;
        if ( maxi < temp  ) {
            maxi = temp ;
            am = a;
            cm = c;
        }
        // maxi = max ( maxi , (a*b) - c ) ;

    }

    if ( M >= X ) {
        cout << 0 ;
    }
    // else if ( n==1 ) {
    //     cout << X/maxi ;
    // }
    else if ( maxi == 0 ) {
        cout << -1 ;
    }
    else {
        // cout << 1+( ( X-M+am-cm )/maxi ) ;
        // cout << 1+( ( X-M-am+cm )/maxi ) ;
        cout << ( ( X-M+maxi-1 )/maxi ) ;
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

