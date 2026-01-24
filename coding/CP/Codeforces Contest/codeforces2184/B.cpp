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

    ll s , k , m ;

    cin >> s >> k >> m ;

    if ( k>m ) cout << ( max ( 0LL , s-m )) ;
    else if ( s <= k ) cout << max ( 0LL , s - m%k ) ;
    else if ( s > k ) {
        if ( (m/k)%2 == 0 ) {
            cout << ( s - m%k ) ;
        }
        else {
            cout << ( k - m%k ) ;
        }
    }
    else cout << 0; // dummy
    // else if ( ( m%k >= s ) ) cout << "0" ;
    // else cout << ( m - m%k ) ;

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