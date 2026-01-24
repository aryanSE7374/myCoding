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

    vi a(n) ;

    f(i,0,n) cin >> a[i] ;

    int i = n-1 ;
    // int idx = -1;

    while ( i >= 0 && ( a[i] == i+1 ) ) {
        i-- ;
        // if ( a[i] != i+1 )
    }

    if ( i < 0 ) cout << 0 ;
    else cout << a[i] ;

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