#include<bits/stdc++.h>
using namespace std;

// rec 

#define INF 1e9

class Solution {
public:
    int f ( vector<int>& coins , int i , int T ){
        
        if ( i==0 ) {
            if ( T % coins[i] == 0 ){
                return T / coins[i] ;
            }
            else return INF;
        }

        int notTake = f ( coins , i-1 , T ) ;
        int take = INF ;

        if ( T >= coins[i] ) take = 1 + f ( coins , i , T - coins[i] ) ;
        
        return min ( notTake , take ) ;

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f ( coins , n-1 , amount ) ;
        return  (ans >= INF) ? -1 : ans ;
    }
    
};


// memo

#define INF 1e9

class Solution {
public:
    vector<vector<int>> memo;

    int f ( vector<int>& coins , int i , int T ){
        
        if ( i==0 ) {
            if ( T % coins[0] == 0 ){
                return T / coins[i] ;
            }
            else return INF;
        }

        if ( memo[i][T] != -1 ) return memo[i][T] ;

        int notTake = f ( coins , i-1 , T ) ;
        int take = INF ;

        if ( T >= coins[i] ) take = 1 + f ( coins , i , T - coins[i] ) ;
        
        return memo[i][T] = min ( notTake , take ) ;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memo.assign( n , vector<int>(amount+1 , -1));
        int ans = f ( coins , n-1 , amount ) ;
        return  (ans >= INF) ? -1 : ans ;
    }
};


// tabulate

#define INF 1e9

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp( n , vector<int>(amount+1 , INF));

        for( int T = 0 ; T <= amount ; T++ ){
            if ( T%coins[0] == 0 ) dp[0][T] = T/coins[0] ;
        }

        for ( int i=1 ; i<n ; i++ ){
            for( int T=0 ; T<=amount ; T++ ){

                int notTake = dp[i-1][T] ;
                int take = INF ;

                if ( T >= coins[i] ) take = 1 + dp[i][T-coins[i]] ;
                
                dp[i][T] = min ( notTake , take ) ;

            }
        }

        int ans = dp[n-1][amount];
        return  (ans >= INF) ? -1 : ans ;

    }

};

// space optimization

#define INF 1e9

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp( n , vector<int>(amount+1 , INF));

        vector<int> prev ( amount+1 , INF ) ;
        vector<int> curr ( amount+1 , INF ) ;

        for( int T = 0 ; T <= amount ; T++ ){
            if ( T%coins[0] == 0 ) prev[T] = T/coins[0] ;
        }

        for ( int i=1 ; i<n ; i++ ){
            for( int T=0 ; T<=amount ; T++ ){

                int notTake = prev[T] ;
                int take = INF ;

                if ( T >= coins[i] ) take = 1 + curr[T-coins[i]] ;
                
                curr[T] = min ( notTake , take ) ;

            }
            prev = curr;
        }

        int ans = prev[amount];
        return  (ans >= INF) ? -1 : ans ;

    }

};