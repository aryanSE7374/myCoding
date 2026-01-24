#include<bits/stdc++.h>
using namespace std;

// my code
// memo 

class Solution {
public:

    vector<vector<vector<int>>> dp;

    int f ( vector<int>& p , int i , int b , int t ) { 

        if ( i == p.size() ) return 0 ;

        if ( t == 2 && b==0 ) return 0;

        if ( dp[i][b][t] != -1 ) return dp[i][b][t] ;
        
        if ( b==0 ) return dp[i][b][t] = max ( f( p , i+1 , 1 , t+1 ) - p[i] , f ( p , i+1 , 0 , t) );

        else return dp[i][b][t] = max ( f( p , i+1 , 0 , t ) + p[i] , f ( p , i+1 , 1 , t) );

    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<vector<int>>(2 , vector<int>( 3 , -1 ) )) ;

        return f ( prices , 0 , 0  , 0) ;

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

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<vector<int>>(2 , vector<int>( 3 , -1 ) )) ;

        return f ( prices , 0 , 1  , 2 ) ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// tabulate 

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        vector<vector<vector<int>>> dp ( n+1 , vector<vector<int>>(2 , vector<int>( 3 , 0 ) )) ;

        /*
        // not needed - inherently handled by 0 initialization
        for ( int i=0 ; i<=n ; i++ ) {
            dp[i][0][0] = 0 ;
            dp[i][0][1] = 0 ;
        }

        // not needed - inherently handled by 0 initialization
        for ( int cap = 0 ; cap <= 2 ; cap++ ) {
            dp[n][0][cap] = 0 ;
            dp[n][1][cap] = 0 ;
        }
        */

        for ( int i=n-1 ; i>=0 ; i-- ) {
            for ( int cap = 1 ; cap <= 2 ; cap++ ) {
                // if (buy) 
                dp[i][1][cap] = max ( dp[i+1][0][cap] - prices[i] , dp[i+1][1][cap] );
                // else -- if (!buy) 
                dp[i][0][cap] = max ( dp[i+1][1][cap-1] + prices[i] , dp[i+1][0][cap] );
            }
        }

        return dp[0][1][2] ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// space optimized DP

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> curr(2 , vector<int>( 3 , 0 ) ) ;
        vector<vector<int>> next(2 , vector<int>( 3 , 0 ) ) ;

        for ( int i=n-1 ; i>=0 ; i-- ) {
            for ( int cap = 1 ; cap <= 2 ; cap++ ) {
                // if (buy) 
                curr[1][cap] = max ( next[0][cap] - prices[i] , next[1][cap] );
                // else -- if (!buy) 
                curr[0][cap] = max ( next[1][cap-1] + prices[i] , next[0][cap] );
            }
            next = curr ;
        }

        return next[1][2] ;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 