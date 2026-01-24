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


vector<vector<int> > dp;

int fun ( vector<int>& a , int i , int n , int N ) { 

    if ( i == N ) return 0;
    n++;

    if ( n<0 ) return INT_MIN;

    if ( dp[i][n] != -1 ) return dp[i][n] ;

    int curr = n+1 ;

    int hold = fun ( a , i+1 , n , N ) ;
    int sell1 = ( n>0 ) ? a[i] + fun( a , i+1 , n-1 , N ) : INT_MIN ;
    int sell2 = ( n>1 ) ? 2*a[i] + fun( a , i+1 , n-2 , N ) : INT_MIN ;

    return dp[i][n] = max ( {hold , sell1 , sell2} ) ;

}

void SOLVE(){

    int n ;
    cin >> n;

    vi a(n) ;

    f(i,0,n) {
        cin >> a[i] ;
    }

    dp.assign ( n+1 , vector<int>(n+1 , -1)  );

    cout << fun ( a , 0 , 0 , n ) ;

    // greedy fails 

    // sort ( a.begin() , a.end() ) ;

    // int m = (n+1)/2 ;
    // int left = n ;
    // int i = n-1 ;
    // int ans = 0 ;

    // while ( left > 0 ) {
    //     if ( left == 1 ) {
    //         ans += a[i] ;
    //         i--;
    //         left -= 1;
    //     }
    //     else { 
    //         ans += 2*a[i] ;
    //         i--;
    //         left -= 2 ;
    //     }
    // }

    // cout << ans ;




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