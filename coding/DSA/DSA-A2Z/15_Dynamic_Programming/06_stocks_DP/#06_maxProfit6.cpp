#include<bits/stdc++.h>
using namespace std;

// transaction with a fee only once per buy and sell cycle

// memo 
// i=0 to n

class Solution {
public:

    vector<vector<int>> dp;

    int f ( vector<int>& p , int i , int buy , int fee ) { 
        
        if ( i == p.size() ) return 0 ;
        
        if ( dp[i][buy] != -1 ) return dp[i][buy] ;
        
        if ( buy ) return dp[i][buy] = max ( f( p , i+1 , 0 , fee ) - p[i] - fee , f ( p , i+1 , 1 , fee ) );

        else return dp[i][buy] = max ( f( p , i+1 , 1 , fee  ) + p[i] , f ( p , i+1 , 0 , fee  ) );

    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<int>(2 , -1 ) ) ;

        return f ( prices , 0 , 1 , fee ) ;

    }
};

// tabulate 
// i=n to 0

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size() ;
        vector<vector<int>> dp ( n+1 , vector<int>(2 , 0 ) ) ;

        // base case is inherently handled by 0 initialization of vector

        for ( int i=n-1 ; i>=0 ; i-- ) {
            dp[i][0] = max ( dp[i+1][1] + prices[i] , dp[i+1][0] );
            dp[i][1] = max ( dp[i+1][0] - prices[i] - fee , dp[i+1][1] );
        }


        return dp[0][1];

    }
};


// space optimization 
// i=n to 0

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size() ;

        vector<int> curr(2 , 0 );   // dp[i]
        vector<int> next(2 , 0 );   // dp[i+1]

        // base case is inherently handled by 0 initialization of vector

        for ( int i=n-1 ; i>=0 ; i-- ) {

            curr[0] = max ( next[1] + prices[i] , next[0] );
            curr[1] = max ( next[0] - prices[i] - fee , next[1] );

            next = curr;

        }


        return curr[1];

    }
};
