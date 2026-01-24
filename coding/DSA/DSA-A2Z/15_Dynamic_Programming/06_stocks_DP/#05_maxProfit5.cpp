#include<bits/stdc++.h>
using namespace std;

// buy and sell stock with 1 day cooldown

// memo 
// i=0 to n

class Solution {
public:

    vector<vector<int>> dp;

    int f ( vector<int>& p , int i , int buy ) { 
        
        if ( i >= p.size() ) return 0 ;
        
        if ( dp[i][buy] != -1 ) return dp[i][buy] ;
        
        if ( buy ) return dp[i][buy] = max ( f( p , i+1 , 0  ) - p[i] , f ( p , i+1 , 1  ) );

        else return dp[i][buy] = max ( f( p , i+2 , 1  ) + p[i] , f ( p , i+1 , 0  ) );

    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        dp.assign ( n+1 , vector<int>(2 , -1 ) ) ;

        return f ( prices , 0 , 1 ) ;

    }
};


// tabulate 
// n to 0

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;
        vector<vector<int>> dp ( n+2 , vector<int>(2 , 0 ) ) ;

        // base case -> inherently hadled by 0 initialization of the vector
        // dp[n][0] = dp[n+1][0] = 0;
        // dp[n][1] = dp[n+1][1] = 0;

        for ( int i=n-1 ; i>=0 ; i-- ) {
            dp[i][0] = max ( dp[i+2][1] + prices[i] , dp[i+1][0] );
            dp[i][1] = max ( dp[i+1][0] - prices[i] , dp[i+1][1] );
        }

        return dp[0][1] ;

    }
};


// space optimization 
// n to 0

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        vector<int> curr(2 , 0 ) ;      // dp[i]
        vector<int> next(2 , 0 ) ;      // dp[i+1]
        vector<int> next2(2 , 0 ) ;     // dp[i+2]

        /*

        0       |           |
        1       |           |
        .       |           |
        .       |           |
        .       |           |
        n-2     |           |   curr
        n-1     |   curr    |<- next
        n       |   next    |<- next2
        n+1     |   next2   |   

        */

        for ( int i=n-1 ; i>=0 ; i-- ) {

            curr[0] = max ( next2[1] + prices[i] , next[0] );
            curr[1] = max ( next[0] - prices[i] , next[1] );

            next2 = next;
            next = curr;

        }

        return curr[1] ;

    }
};