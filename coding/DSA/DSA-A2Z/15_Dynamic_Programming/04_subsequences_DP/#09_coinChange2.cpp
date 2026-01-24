#include<bits/stdc++.h>
using namespace std;

// rec

class Solution {
public:

    int f ( vector<int>& coins , int i , int T ) {

        if ( i==0 ) {
            return ( T % coins[i] == 0 ) ? 1 : 0 ;
        }

        int notTake = f( coins , i-1 , T );
        int take = 0;

        if ( coins[i] <= T ) {
            take = f ( coins , i , T-coins[i] ) ;
        }

        return notTake + take ;

    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size() ;

        return f ( coins , n-1 , amount ) ;

    }
};

// memo

class Solution {
public:

    vector<vector<int>> dp ;

    int f ( vector<int>& coins , int i , int T ) {

        if ( i==0 ) {
            return ( T % coins[i] == 0 ) ? 1 : 0 ;
        }

        if ( dp[i][T] != -1 ) return dp[i][T];

        int notTake = f( coins , i-1 , T );
        int take = 0;

        if ( coins[i] <= T ) {
            take = f ( coins , i , T-coins[i] ) ;
        }

        return dp[i][T] = notTake + take ;

    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size() ;

        dp.assign (n+1 , vector<int>( amount+1 , -1 ) ) ;

        return f ( coins , n-1 , amount ) ;

    }
};

// tabulation

#define ull unsigned long long

class Solution {
public:

    int change(int amount, vector<int>& coins) {

        int n = coins.size() ;
        // int T = amount ;

        vector<vector<ull>> dp (n+1 , vector<ull>( amount+1 , 0 ) ) ;

        for ( int T=0 ; T <= amount ; T++) {
            if ( T%coins[0] == 0 ) dp[0][T] = 1;
        }

        for(int i=1 ; i<n ; i++ ) {
            for ( int T=0 ; T <= amount ; T++ ){ 

                ull notTake = dp[i-1][T];
                ull take = ( coins[i] <= T ) ? dp[i][T-coins[i]] : 0;
                dp[i][T] = notTake + take ;

            }
        }

        return dp[n-1][amount] ;

    }
};