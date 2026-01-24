#include<bits/stdc++.h>
using namespace std;

// rec
// 1-based indexing recursion
class Solution {
public:

    int f ( string& s1 , string& s2 , int i , int j ) {
        // base case
        if (i==0) return j;
        if (j==0) return i;

        // recurrance
        if ( s1[i-1] == s2[j-1] ) {
            return f ( s1 , s2 , i-1 , j-1 ) ;
        }

        int ins = 1 + f(s1 , s2 , i , j-1) ;
        int del = 1 + f(s1 , s2 , i-1 , j) ;
        int rep = 1 + f(s1 , s2 , i-1 , j-1) ;

        return min ( {ins , del , rep} ) ;

    }

    int minDistance(string s1, string s2) {
        
        int m = s1.size() , n = s2.size() ;
        return f ( s1 , s2 , m , n ) ;

    }
};

// 1-based indexing memo
class Solution {
public:

    vector<vector<int>> dp;

    int f ( string& s1 , string& s2 , int i , int j ) {
        // base case
        if (i==0) return j;
        if (j==0) return i;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        // recurrance
        if ( s1[i-1] == s2[j-1] ) {
            return dp[i][j] = f ( s1 , s2 , i-1 , j-1 ) ;
        }

        int ins = 1 + f(s1 , s2 , i , j-1) ;
        int del = 1 + f(s1 , s2 , i-1 , j) ;
        int rep = 1 + f(s1 , s2 , i-1 , j-1) ;

        return dp[i][j] = min ( {ins , del , rep} ) ;

    }

    int minDistance(string s1, string s2) {
        
        int m = s1.size() , n = s2.size() ;
        dp.assign(m+1 , vector<int>(n+1 , -1));
        return f ( s1 , s2 , m , n ) ;

    }
};

// 1-based indexing tabulate
class Solution {
public:

    int minDistance(string s1, string s2) {
        
        int m = s1.size() , n = s2.size() ;
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));

        for ( int i=0 ; i<=m ; i++ ) {
            dp[i][0] = i;
        }
        for ( int j=0 ; j<=n ; j++ ) {
            dp[0][j] = j;
        }

        for ( int i=1 ; i<=m ; i++ ) {
            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1] ;
                }

                else{
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int rep = 1 + dp[i-1][j-1];
    
                    dp[i][j] = min ( {ins , del , rep} ) ;
                }

            }
        }

        return dp[m][n];

    }
};

// 1-based indexing space optimized DP
class Solution {
public:

    int minDistance(string s1, string s2) {
        
        int m = s1.size() , n = s2.size() ;
        // vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));

        vector<int> prev(n+1 , 0);
        vector<int> curr(n+1 , 0);

        for ( int j=0 ; j<=n ; j++ ) {
            prev[j] = j;
        }
        
        for ( int i=1 ; i<=m ; i++ ) {
            curr[0] = i;
            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] ) {
                    curr[j] = prev[j-1] ;
                }

                else{
                    int ins = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];
    
                    curr[j] = min ( {ins , del , rep} ) ;
                }

            }

            prev = curr ;
        }

        return prev[n];

    }
};