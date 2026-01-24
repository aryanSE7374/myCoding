#include<bits/stdc++.h>
using namespace std;


// memo
class Solution {
public:

    vector<vector<int>> dp ;

    // max cost common subsequence

    int LCS( string s1 ,  string s2 , int i , int j ) {
        // base case
        if ( i==0 || j==0 ) {
            // return ( s1[i] == s2[j] ) ? s1[i] : 0 ;
            if ( s1[i] == s2[j] ) { 
                return s1[i];
            }
            else {
                int str1 = ( i>0 ) ? LCS ( s1 , s2 , i-1 , j ) : 0 ;
                int str2 = ( j>0 ) ? LCS ( s1 , s2 , i , j-1 ) : 0 ;
                return max ( str1 , str2 ) ; 
            }
        }

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if( s1[i] == s2[j] ) {
            return dp[i][j] = s1[i] + LCS(s1,s2,i-1,j-1);
        }

        else {
            return dp[i][j] = max ( LCS(s1,s2,i,j-1) , LCS(s1,s2,i-1,j) ) ;
        }

    }
    
    int minimumDeleteSum(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        int cost1 = 0;
        int cost2 = 0;

        dp.assign ( m+1 , vector<int>( n+1 , -1 ) ) ; 

        for ( int i=0 ; i < m ; i++ ){
            cost1 += s1[i];
        }

        for ( int i=0 ; i < n ; i++ ){
            cost2 += s2[i];
        }

        return cost1 + cost2 - 2 * LCS( s1 , s2 , m-1 , n-1 ) ;

    }
};



// tabulation 

class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        int cost1 = 0;
        int cost2 = 0;

        vector<vector<int>> dp ( m+1 , vector<int>( n+1 , 0 ) ) ; // max cost common subsequence

        for ( int i=0 ; i < m ; i++ ){
            cost1 += s1[i];
        }

        for ( int i=0 ; i < n ; i++ ){
            cost2 += s2[i];
        }

        if ( s1[0] == s2[0] ) dp[0][0] = s1[0] ;

        for( int i = 1 ; i < m ; i++ ) { 
            dp[i][0] = ( s1[i] == s2[0] ) ? s2[0] : dp[i-1][0] ;
        }

        for( int j = 1 ; j < n ; j++ ) { 
            dp[0][j] = ( s1[0] == s2[j] ) ? s1[0] : dp[0][j-1] ;
        }

        for ( int i = 1 ; i<m ; i++ ) {
            for ( int j = 1 ; j<n ; j++ ) { 
                if( s1[i] == s2[j] ) {
                    dp[i][j] = s1[i] + dp[i-1][j-1] ;
                }

                else {
                    dp[i][j] = max ( dp[i][j-1] , dp[i-1][j] ) ;
                }
            }
        }

        return cost1 + cost2 - 2 * dp[m-1][n-1] ;

    }
};

// space optimization 

class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        int cost1 = 0;
        int cost2 = 0;

        // vector<vector<int>> dp ( m+1 , vector<int>( n+1 , 0 ) ) ; // max cost common subsequence

        for ( int i=0 ; i < m ; i++ ){
            cost1 += s1[i];
        }

        for ( int i=0 ; i < n ; i++ ){
            cost2 += s2[i];
        }

        vector<int> prev(n,0);
        vector<int> curr(n,0);

        if ( s1[0] == s2[0] ) prev[0] = s1[0] ;

        // for( int i = 1 ; i < m ; i++ ) { 
        //     dp[i][0] = ( s1[i] == s2[0] ) ? s2[0] : dp[i-1][0] ;
        // }

        for( int j = 1 ; j < n ; j++ ) { 
            prev[j] = ( s1[0] == s2[j] ) ? s1[0] : prev[j-1] ;
        }

        for ( int i = 1 ; i<m ; i++ ) {
            // j=0 case
            curr[0] = ( s1[i] == s2[0] ) ? s2[0] : prev[0] ;

            for ( int j = 1 ; j<n ; j++ ) { 

                if( s1[i] == s2[j] ) {
                    curr[j] = s1[i] + prev[j-1] ;
                }

                else {
                    curr[j] = max ( curr[j-1] , prev[j] ) ;
                }

            }
            prev = curr ;
        }

        return cost1 + cost2 - 2 * prev[n-1] ;

    }
};

