#include<bits/stdc++.h>
using namespace std;


// memo 

class Solution {
public:

    vector<vector<int>> dp;

    int f ( vector<int>& p , int i , int b ) { 

        if ( i == p.size() ) return 0 ;

        if ( dp[i][b] != -1 ) return dp[i][b] ;
        
        if ( b==0 ) return dp[i][b] = max ( f( p , i+1 , 1 ) - p[i] , f ( p , i+1 , 0) );

        else return dp[i][b] = max ( f( p , i+1 , 0 ) + p[i] , f ( p , i+1 , 1) );

    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<int>(2 , -1 )) ;

        return f ( prices , 0 , 0 ) ;

    }
};

// tabulate

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<vector<int>> dp ( n+1 , vector<int>(2 , 0 )) ; // hadnles base case inherently

        for ( int i=n-1 ; i>=0 ; i-- ) {
            dp[i][0] = max ( dp[i+1][1] - prices[i] , dp[i+1][0] );
            dp[i][1] = max ( dp[i+1][0] + prices[i] , dp[i+1][1] );
        }

        return dp[0][0] ;

    }
};

// space optimization

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<int> prev(2 , 0 ) ;
        vector<int> curr(2 , 0 ) ;

        for ( int i=n-1 ; i>=0 ; i-- ) {
            curr[0] = max ( prev[1] - prices[i] , prev[0] );
            curr[1] = max ( prev[0] + prices[i] , prev[1] );
            prev = curr ;
        }

        return prev[0] ;

    }
};