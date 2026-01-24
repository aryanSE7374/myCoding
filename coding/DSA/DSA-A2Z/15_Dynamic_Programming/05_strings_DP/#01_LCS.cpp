#include<bits/stdc++.h>
using namespace std;

// method 1 - rec/memo

class Solution {
public:
    int LCS(string &s1, string &s2, int m, int n, vector<vector<int>>& memo) {

        if (m == 0 || n == 0) 
            return 0;

        if (memo[m][n] != -1) 
            return memo[m][n];

        if (s1[m-1] == s2[n-1]) {
            return memo[m][n] = 1 + LCS(s1, s2, m-1, n-1, memo);
        }

        return memo[m][n] = max(
            LCS(s1, s2, m, n-1, memo),
            LCS(s1, s2, m-1, n, memo)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

        return LCS(text1, text2, m, n, memo);
    }
};


// rec - method 2

class Solution {
public:

    int f ( string& s1, string& s2 , int i , int j ) {

        if ( i<0 || j<0 ) return 0;

        if ( s1[i] == s2[j] ) return 1 + f ( s1 , s2 , i-1 , j-1 ) ;

        return max ( f ( s1, s2, i-1, j ) , f ( s1, s2, i, j-1 ) ) ;

    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size() ;
        int n = text2.size() ;

        return f ( text1 , text2 , m-1 , n-1 );
        
    }
};

// memo - method 2 : NOT POSSIBLE due to negative states of i and j , hence method 3 is used to memoize

// rec - method 3

class Solution {
public:

    int f ( string& s1, string& s2 , int i , int j ) {

        if ( i==0 || j==0 ) return 0;

        if ( s1[i-1] == s2[j-1] ) return 1 + f ( s1 , s2 , i-1 , j-1 ) ;

        return max ( f ( s1, s2, i-1, j ) , f ( s1, s2, i, j-1 ) ) ;

    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size() ;
        int n = text2.size() ;

        return f ( text1 , text2 , m , n );

    }
};

// memo - method 3

class Solution {
public:

    vector<vector<int>> dp ;

    int f ( string& s1, string& s2 , int i , int j ) {

        if ( i==0 || j==0 ) return 0;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s1[i-1] == s2[j-1] ) return dp[i][j] = 1 + f ( s1 , s2 , i-1 , j-1 ) ;

        return dp[i][j] = max ( f ( s1, s2, i-1, j ) , f ( s1, s2, i, j-1 ) ) ;

    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size() ;
        int n = text2.size() ;
        // vector<vector<int>> dp;
        dp.assign ( m+1 , vector<int>( n+1, -1 ) ) ;

        return f ( text1 , text2 , m , n );

    }
};

// tabulate - method 3

class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        vector<vector<int>> dp ( m+1 , vector<int>( n+1, 0 ) ) ;

        for ( int i=1 ; i<=m ; i++ ) { 
            for ( int j=1 ; j <=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1] ;
                else dp[i][j] = max ( dp[i-1][j] , dp[i][j-1] ) ;
            }
        }

        return dp[m][n] ;

    }
};

// space optimization - method 3

class Solution {
public:

    int longestCommonSubsequence(string s1, string s2) {

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
};