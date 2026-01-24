#include<bits/stdc++.h>
using namespace std;

// my recursion based solution - memo

class Solution {
public:

    vector < vector < int >  > dp ;

    int f ( string &s , int i , int j ) {

        if ( i > j ) return 0 ;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s[i] == s[j] ) {
            return dp[i][j] = ( ( (i==j) ? 1 : 2 ) + f ( s , i+1 , j-1 ) ) ;
        }

        return dp[i][j] = max ( f ( s , i+1 , j ) , f ( s , i , j-1 ) ) ;

    }
    int longestPalindromeSubseq(string s) {

        int n = s.size() ;

        dp.assign( n , vector<int>(n,-1) ) ;

        return f ( s , 0 , n-1 ) ;

    }
};

// tabulaiton - method 1

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size() ;

        vector <vector<int>> dp( n , vector<int>(n,0) ) ;

        // i==j base case explicitly handled
        for (int i = 0 ; i < n ; i++ ) {
            dp[i][i] = 1;
        }

        for (int i = n-1 ; i >= 0 ; i-- ) {
            for (int j = i+1 ; j < n ; j++ ) {
                if ( s[i] == s[j] ) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } 
                else {
                    dp[i][j] = max( dp[i+1][j] , dp[i][j-1] );
                }
            }
        }

        return dp[0][n-1];

    }
};

// method 2 - based on LCS idea

class Solution {
    public:

    int LCS(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        vector<int> prev (n+1 , 0) ;
        vector<int> curr (n+1 , 0) ;

        for ( int i=1 ; i<=m ; i++ ) { 
            for ( int j=1 ; j <=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) curr[j] = 1 + prev[j-1] ;
                else curr[j] = max ( prev[j] , curr[j-1] ) ;
            }
            prev = curr ;
        }

        return prev[n] ;

    }

    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(revs.begin() , revs.end() ) ;
        return LCS ( s , revs ) ;
        
    }
};