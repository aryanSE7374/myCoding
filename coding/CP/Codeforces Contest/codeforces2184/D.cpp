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


ll nCr(int n , int r) {

    if ( r < 0 || r > n) return 0;
    if ( r == 0 || r == n) return 1;
    if ( r > n / 2) r = n - r; 
    
    ll res = 1;

    f(i,1,r+1){
        res = res * (n -i+1) / i ;
    }

    return res;
}


void SOLVE(){

    ll n , k ;

    cin >> n >> k ;

    ll ans = 0;


    int d = 0;
    // d : n = 2^d

    while ( ( 1LL << (d + 1) ) <= n ) {
        d++;
    }

    // 
    if ( d > k-1 ) ans++;

    // all MSB 
    f(i,0,d){
        
        ll maxi = k-i-1;

        // count of set bits cobination
        f(j,0,i+1){
            if ( j > maxi ) {
                ans += nCr ( i , j) ;
            }
        }
    }

    cout << ans;


    co_endl;
}

/*

7
4 1
4 2
4 3
4 4
4 5
16 5
16 1

---


3
2
0
0
0
4
15

*/

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

