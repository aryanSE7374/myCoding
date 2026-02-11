#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

// vector <vector<int> > dp; 

// int f ( vi B , int i , int num ) {

//     // if ( num <= 1 ) return ( B[i] == 1 ) ? 1 : 0 ;
    
//     if ( i==0 ) {
//         return ( B[0] == 1 || B[0] == num ) ? 1 : 0 ;
//     }

//     if ( num < 0 ) return 0;

//     if ( dp[i][num] != -1 ) return dp[i][num] ;

//     if ( B[i] == 1 ) return 1 + f ( B , i-1 , num ) ;
//     else if ( B[i] == num ) return 1 + f ( B , i-1 , num-1 ) ;
//     else return max ( f( B , i-1 , num ) , f( B , i-1 , B[i-1]-1 ) ) ;

//     // if ( i<0 ) return 0;
    
//     // int found = ( B[i] == 1 || B[i] == num ) ? 1 + f ( B , i-1 , num-1 ) : 0;
    
//     // int notfound = max ( f( B , i-1 , num ) , f( B , i-1 , B[i-1] ) );
    
//     // return max ( found , notfound );


    
// }

// int f ( vi B , int i , int num ) {

//     // if ( num <= 1 ) return ( B[i] == 1 ) ? 1 : 0 ;
    
//     if ( i==0 ) {
//         return ( B[0] == 1 || B[0] == num ) ? 1 : 0 ;
//     }

//     if ( num < 0 ) return 0;

//     if ( dp[i][num] != -1 ) return dp[i][num] ;
    
//     if ( B[i] == 1 ) return 1 + f ( B , i-1 , num ) ;
//     else if ( B[i] == num ) return 1 + f ( B , i-1 , num-1 ) ;
//     else return max ( f( B , i-1 , num ) , f( B , i-1 , B[i-1]-1 ) ) ;

//     // if ( i<0 ) return 0;
    
//     // int found = ( B[i] == 1 || B[i] == num ) ? 1 + f ( B , i-1 , num-1 ) : 0;
    
//     // int notfound = max ( f( B , i-1 , num ) , f( B , i-1 , B[i-1] ) );
    
//     // return max ( found , notfound );


    
// }

// void SOLVE () {

//     int n ;
//     cin >> n;
    
//     vi B(n);
    
//     for ( int i=0 ; i<n ; i++ ) {
//         cin >> B[i];
//     }

//     dp.assign ( n+1 , vector<int> ( 1001 , 0 ) );

//     for ( int i = 0 ; i<n ; i++ ) {

//     }
    
//     int ans = f ( B , n-1 , B[n-1]-1 ) ;
//     if ( ans > 0 ) ans++;
//     cout << ans << "\n";
    
// }


void SOLVE () {

    int n ;
    cin >> n;
    
    vi B(n);
    
    for ( int i=0 ; i<n ; i++ ) {
        cin >> B[i];
    }

    // dp.assign ( n+1 , vector<int> ( 1001 , 0 ) );

    // dp[0][B[0]] = 1;
    
    // for ( int i = 1 ; i<n ; i++ ) {
    //     dp[i][B[i]] = dp[i-1][B[i]] + 1;
    // }
    
    // int ans = 0;
    
    // for ( int i=0 ; i<n ; i++ ) {
    //     int curr = 0;
    //     int cmax = 0;
    //     for ( int j=2 ; j<1001 ; j++ ) {
    //         if ( dp[i][j] > 0 ) curr+=dp[i][j] ;
    //         else {
    //             cmax = max ( cmax , curr );
    //             curr=0;
    //         }
    //     }
    //     ans = max ( ans , cmax + dp[i][1] ) ;
    // }

    // vector<int> freq(n+2 , 0);

    // for (int i=0 ; i<n ; i++ ) freq[B[i]]++;

    // vector<int> dp(n+ 2, 0);

    // dp[1] = freq[1];

    // int ans = dp[1];

    // for (int i = 2 ; i <= n ; i++) {
    //     dp[i] = min( freq[i] , dp[i - 1] );
    //     ans += dp[i];
    // }

    // cout << ans << "\n";



    
}

int main() {
	// your code goes here

    int t;
    cin >> t;

    while ( t-- ) {
        SOLVE();
    }

}
