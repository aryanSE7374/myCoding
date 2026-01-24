#include<bits/stdc++.h>
using namespace std;

// just change 2 max transactions to general k trasnactions in maxProfit3 problem

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my try
// memo 

class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f ( vector<int>& p , int i , int b , int t , const int k ) { 

        if ( i == p.size() ) return 0 ;

        if ( t == k && b==0 ) return 0;

        if ( dp[i][b][t] != -1 ) return dp[i][b][t] ;
        
        if ( b==0 ) return dp[i][b][t] = max ( f( p , i+1 , 1 , t+1 , k ) - p[i] , f ( p , i+1 , 0 , t , k) );

        else return dp[i][b][t] = max ( f( p , i+1 , 0 , t , k ) + p[i] , f ( p , i+1 , 1 , t , k ) );

    }

    int maxProfit( int k , vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<vector<int>>(2 , vector<int>( k+1 , -1 ) )) ;

        return f ( prices , 0 , 0  , 0 , k ) ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's solution
// memo 

class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f ( vector<int>& p , int i , int buy , int cap ) { 

        if ( cap == 0 ) return 0;
        
        if ( i == p.size() ) return 0 ;
        
        if ( dp[i][buy][cap] != -1 ) return dp[i][buy][cap] ;
        
        if ( buy ) return dp[i][buy][cap] = max ( f( p , i+1 , 0 , cap ) - p[i] , f ( p , i+1 , 1 , cap ) );

        else return dp[i][buy][cap] = max ( f( p , i+1 , 1 , cap-1 ) + p[i] , f ( p , i+1 , 0 , cap ) );

    }

    int maxProfit( int k , vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<vector<int>>(2 , vector<int>( k+1 , -1 ) )) ;

        return f ( prices , 0 , 1  , k ) ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// tabulate 
class Solution {
public:

    int maxProfit( int k , vector<int>& prices) {

        int n = prices.size() ;
        vector<vector<vector<int>>> dp ( n+1 , vector<vector<int>>(2 , vector<int>( k+1 , 0 ) )) ;

        // base cases inherently handled by 0 initialization

        for ( int i=n-1 ; i>=0 ; i-- ) {
            for ( int cap = 1 ; cap <= k ; cap++ ) {
                // if (buy) 
                dp[i][1][cap] = max ( dp[i+1][0][cap] - prices[i] , dp[i+1][1][cap] );
                // else -- if (!buy) 
                dp[i][0][cap] = max ( dp[i+1][1][cap-1] + prices[i] , dp[i+1][0][cap] );
            }
        }

        return dp[0][1][k] ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// space optimized DP

class Solution {
public:

    int maxProfit( int k , vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> curr(2 , vector<int>( k+1 , 0 ) ) ;
        vector<vector<int>> next(2 , vector<int>( k+1 , 0 ) ) ;

        for ( int i=n-1 ; i>=0 ; i-- ) {
            for ( int cap = 1 ; cap <= k ; cap++ ) {
                // if (buy) 
                curr[1][cap] = max ( next[0][cap] - prices[i] , next[1][cap] );
                // else -- if (!buy) 
                curr[0][cap] = max ( next[1][cap-1] + prices[i] , next[0][cap] );
            }
            next = curr ;
        }

        return next[1][k] ;

    }
};
// ------------------------------------------------------------------------------------------------------------------------------------ // 