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

    int n , l , h ;

    cin >> n >> l >> h ;
    vi a(n) ;

    int hc = 0 , lc = 0;

    f(i,0,n) {
        cin >> a[i] ;
        if ( a[i] <= h ) hc++; 
        if ( a[i] <= l) lc++;
    }

    if ( l<=h ) {
        cout << min( lc , (hc/2) );
    }
    else{
        cout << min( hc , (lc/2) );
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