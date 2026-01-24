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

    int n;
    cin >> n;

    vll a(n);

    f(i,0,n){
        cin >> a[i] ;
    }

    vll neg(n); // next negative index
    vll zero(n); // next zero index

    ll maxi = a[0]; //
    ll p = 1;

    int ln = n ; // neg pos
    int lz = n ; // zero pos

    f ( i , 0 , n ) {
        p *= a[i];
        maxi = max( maxi , p );
        if ( a[i] == 0) {
            p = 1;
        }
    }

    p = 1;

    for ( int i=n-1 ; i >= 0 ; i-- ) {

        p *= a[i];

        maxi = max(maxi, p);

        if (a[i] == 0) {
            p = 1;
        }
    }


    // for ( int i=n-1 ; i >= 0 ; i-- ) {
        
    //     neg[i] = ln;
    //     zero[i] = lz;

    //     if ( a[i] < 0 ) {
    //         ln = i ;
    //     }

    //     if ( a[i] == 0 ) {
    //         lz = i ;
    //     }

    // }

    // ll maxi = LLONG_MIN ;
    // ll p = 1;

    // int lastZero = lz ;

    // f ( i , 0 , n ) {


    //     if ( a[i] == 0 ){
    //         for ( int j = lastZero+1 ; j < i ; j++ ){
    //             p/=a[j];
    //             maxi = max ( maxi , p ) ;
    //         }
    //         p=1;
    //         lastZero = i;
    //     }

    //     else {
    //         p *= a[i] ;
    //         maxi = max( maxi , p );
    //     }
        
    // }

    // if ( lz < n && maxi<0 ){
    //     maxi = 0;
    // }

    cout <<  maxi ;

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