#include<bits/stdc++.h>
using namespace std;

// rec

class Solution {
  public:

    int f ( int i , int W , vector<int>& wt , vector<int>& val ) {
        if ( i==0 ) return ( W >= wt[0] ) ? val[i] : 0 ;
        int take = ( W >= wt[i] ) ?  ( val[i] + f( i-1 , W-wt[i] , wt , val ) ) : 0;
        int notTake = f ( i-1 , W , wt , val ) ;
        return max ( take , notTake ) ;

    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        return f ( n-1 , W , wt , val ) ;
    
    }
};

// memo

class Solution {
  public:

    vector<vector<int>> memo;

    int f ( int i , int W , vector<int>& wt , vector<int>& val ) {
        if ( i==0 ) return ( W >= wt[0] ) ? val[i] : 0 ;
        if ( memo[i][W] != -1 ) return memo[i][W] ;
        int take = ( W >= wt[i] ) ?  ( val[i] + f( i-1 , W-wt[i] , wt , val ) ) : 0;
        int notTake = f ( i-1 , W , wt , val ) ;
        return memo[i][W] = max ( take , notTake ) ;

    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        memo.assign ( n , vector<int>(W+1 , -1) ) ;
        return f ( n-1 , W , wt , val ) ;
    
    }
};

// tabulation

class Solution {
  public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        vector<vector<int>> dp( n , vector<int>(W+1 , 0) ) ;

        for(int j=1 ; j<=W ; j++){
            if (j>=wt[0]) dp[0][j] = val[0];
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<=W ; j++ ){
                int take = ( j >= wt[i] ) ?  ( val[i] + dp[i-1][j-wt[i]] ) : 0;
                int notTake = dp[i-1][j] ;
                dp[i][j] = max ( take , notTake ) ;
            }
        }

        return dp[n-1][W];
    
    }
};

// tabulation : minor optimization by striver

class Solution {
  public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        vector<vector<int>> dp( n , vector<int>(W+1 , 0) ) ;

        for(int j=wt[0] ; j<=W ; j++){ // loop initials changed
            dp[0][j] = val[0]; // redundant if checks removed
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<=W ; j++ ){
                int take = ( j >= wt[i] ) ?  ( val[i] + dp[i-1][j-wt[i]] ) : 0;
                int notTake = dp[i-1][j] ;
                dp[i][j] = max ( take , notTake ) ;
            }
        }

        return dp[n-1][W];
    
    }
};

// space optimization

class Solution {
  public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        vector<int> prev ( W+1 , 0 ) ;
        vector<int> curr ( W+1 , 0 ) ;
        // dp[i-1] -> prev , dp[i] -> curr

        for(int j=wt[0] ; j<=W ; j++){ // loop initials changed
            prev[j] = val[0]; // redundant if checks removed
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<=W ; j++ ){
                int take = ( j >= wt[i] ) ?  ( val[i] + prev[j-wt[i]] ) : 0;
                int notTake = prev[j] ;
                curr[j] = max ( take , notTake ) ;
            }
            prev = curr;
        }

        return prev[W];
    
    }
};

// space optimization : upto single auxilary vector space
// 

class Solution {
  public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        vector<int> prev ( W+1 , 0 ) ;
        // vector<int> curr ( W+1 , 0 ) ;
        // dp[i-1] -> prev , dp[i] -> curr

        for(int j=wt[0] ; j<=W ; j++){ // loop initials changed
            prev[j] = val[0]; // redundant if checks removed
        }
        for(int i=1 ; i<n ; i++){
            for(int j=W ; j>=1 ; j-- ){
                int take = ( j >= wt[i] ) ?  ( val[i] + prev[j-wt[i]] ) : 0;
                int notTake = prev[j] ;
                prev[j] = max ( take , notTake ) ;
            }
        }

        return prev[W];
    
    }
};