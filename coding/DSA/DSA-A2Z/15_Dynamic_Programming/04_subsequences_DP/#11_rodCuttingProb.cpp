#include<bits/stdc++.h>
using namespace std;


// rec
int f ( vector<int> &price , int i , int n ) {

    if ( i==0 ) {
        return n * price[0] ;
    }

    int notTake = f ( price , i-1 , n ) ;
    // i -> size = i+1
    // rod length = i+1 and if rod length <= n i.e. i+1 <= n , n -> n - rodlength
    int take = (n>i) ? price[i] + f ( price , i , n-i-1 ) : 0 ; 

    return max ( notTake , take ) ;

}

int cutRod(vector<int> &price, int n)
{
	return f ( price , n-1 , n ) ;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// memo
vector<vector<int>> dp;
int f ( vector<int> &price , int i , int n ) {

    if ( i==0 ) {
        return n * price[0] ;
    }

    if ( dp[i][n] != -1 ) return dp[i][n] ;

    int notTake = f ( price , i-1 , n ) ;
    // i -> size = i+1
    // rod length = i+1 and if rod length <= n i.e. i+1 <= n , n -> n - rodlength
    int take = (n>i) ? price[i] + f ( price , i , n-i-1 ) : 0 ; 

    return dp[i][n] = max ( notTake , take ) ;

}

int cutRod(vector<int> &price, int n)
{
    dp.assign( n , vector<int>( n+1 , -1 ) );
	return f ( price , n-1 , n ) ;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 
// tabulate
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp( n , vector<int>( n+1 , 0 ) );

    for ( int N=0 ; N<=n ; N++ ) {
        dp[0][N] = N * price[0];
    }

    for ( int i=1 ; i<n ; i++ ) {
        for ( int N=0 ; N<=n ; N++ ){
            int notTake = dp[i-1][N] ;
            // i -> size = i+1
            // rod length = i+1 and if rod length <= n i.e. i+1 <= n , n -> n - rodlength
            int take = (N>i) ? price[i] + dp[i][N-i-1] : 0 ; 

            dp[i][N] = max ( notTake , take ) ;
        }
    }
	return dp[n-1][n] ;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 
// space optimization - 2 arrays optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev ( n+1 , 0 );
    vector<int> curr ( n+1 , 0 );

    for ( int N=0 ; N<=n ; N++ ) {
        prev[N] = N * price[0];
    }

    for ( int i=1 ; i<n ; i++ ) {
        for ( int N=0 ; N<=n ; N++ ){
            int notTake = prev[N] ;
            // i -> size = i+1
            // rod length = i+1 and if rod length <= n i.e. i+1 <= n , n -> n - rodlength
            int take = (N>i) ? price[i] + curr[N-i-1] : 0 ; 

            curr[N] = max ( notTake , take ) ;
        }
        prev = curr ;
    }
	return prev[n] ;
}


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// space optimization - 1 array optimization
int cutRod(vector<int> &price, int n)
{
    vector<int> prev ( n+1 , 0 );

    for ( int N=0 ; N<=n ; N++ ) {
        prev[N] = N * price[0];
    }

    for ( int i=1 ; i<n ; i++ ) {
        for ( int N=0 ; N<=n ; N++ ){
            int notTake = prev[N] ;
            // i -> size = i+1
            // rod length = i+1 and if rod length <= n i.e. i+1 <= n , n -> n - rodlength
            int take = (N>i) ? price[i] + prev[N-i-1] : 0 ; 

            prev[N] = max ( notTake , take ) ;
        }
    }
	return prev[n] ;
}


// ------------------------------------------------------------------------------------------------------------------------------------ // 