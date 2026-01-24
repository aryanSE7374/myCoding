#include<bits/stdc++.h>
using namespace std;


// 0-based index rec-memo
class Solution {
public:

    vector<vector<int>> dp ;

    bool f ( string& s1 , string& s2 , int i , int j ) {

        if ( i<0 && j<0 ) return true;

        if ( i<0 && j>=0 ) return false;

        if ( j<0 && i>=0 ) {
            for ( int k=i ; k>=0 ; k-- ) if ( s1[k] != '*' ) return false;
            return true;
        }

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s1[i] == s2[j] || s1[i] == '?' ) return dp[i][j] = f ( s1 , s2 , i-1 , j-1 ) ;

        if ( s1[i] == '*' ) return dp[i][j] = f ( s1 , s2 , i-1 , j ) || f ( s1 , s2 , i , j-1 ) ;

        return dp[i][j] = false; 

    }

    bool isMatch(string s, string p) {

        string s1 = p , s2 = s ;
        // inverse convention : s1 <-> s2 i.e. s2 has wildcard chars

        int m = s1.size() , n = s2.size() ;
        dp.assign( m+1 , vector<int>( n+1 , -1 ) ) ;
        return f ( s1 , s2 , m-1 , n-1 ) ;

    }

};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// 1-based index rec-memo
class Solution {
public:

    vector<vector<int>> dp ;

    bool f ( string& s1 , string& s2 , int i , int j ) {

        if ( i==0 && j==0 ) return true;

        if ( i==0 && j>0 ) return false;

        if ( j==0 && i>0 ) {
            for ( int k=i ; k>0 ; k-- ) if ( s1[k-1] != '*' ) return false;
            return true;
        }

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s1[i-1] == s2[j-1] || s1[i-1] == '?' ) return dp[i][j] = f ( s1 , s2 , i-1 , j-1 ) ;

        if ( s1[i-1] == '*' ) return dp[i][j] = f ( s1 , s2 , i-1 , j ) || f ( s1 , s2 , i , j-1 ) ;

        return dp[i][j] = false; 

    }

    bool isMatch(string s, string p) {

        string s1 = p , s2 = s ;
        // inverse convention : s1 <-> s2 i.e. s2 has wildcard chars

        int m = s1.size() , n = s2.size() ;
        dp.assign( m+1 , vector<int>( n+1 , -1 ) ) ;
        return f ( s1 , s2 , m , n ) ;

    }

};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// 1-based index tabulate
class Solution {
public:

    bool isMatch(string s, string p) {

        string s1 = p , s2 = s ;
        // inverse convention : s1 <-> s2 i.e. s2 has wildcard chars on leetcode

        int m = s1.size() , n = s2.size() ;
        vector<vector<bool>> dp( m+1 , vector<bool>( n+1 , false ) ) ;

        // base case 1
        dp[0][0] = true;

        // base case 2 : not needed as inital values are already 0 

        // base case 3
        for ( int i=1 ; i<=m ; i++ ) {
            bool flag = true;
            for ( int k=i ; k>0 ; k-- ) {
                if ( s1[k-1] != '*' ) {
                    flag = false; 
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for ( int i=1 ; i<=m ; i++ ) {
            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] || s1[i-1] == '?' ) dp[i][j] = dp[i-1][j-1] ;

                else if ( s1[i-1] == '*' ) dp[i][j] = dp[i-1][j] || dp[i][j-1] ;

                else dp[i][j] = false; 

            }
        }

        return dp[m][n] ;

    }

};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// 1-based index space optimization
class Solution {
public:

    bool isMatch(string s, string p) {

        string s1 = p , s2 = s ;
        // inverse convention : s1 <-> s2 i.e. s2 has wildcard chars on leetcode

        int m = s1.size() , n = s2.size() ;

        vector<bool> prev( n+1 , false ) ;
        vector<bool> curr( n+1 , false ) ;

        // base case 1
        prev[0] = true;

        // base case 2 : not needed as inital values are already 0 

        for ( int i=1 ; i<=m ; i++ ) {

            // base case 3
            bool flag = true;
            for ( int k=i ; k>0 ; k-- ) {
                if ( s1[k-1] != '*' ) {
                    flag = false; 
                    break;
                }
            }
            curr[0] = flag;

            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] || s1[i-1] == '?' ) curr[j] = prev[j-1] ;

                else if ( s1[i-1] == '*' ) curr[j] = prev[j] || curr[j-1] ;

                else curr[j] = false; 

            }
            prev = curr ;
        }

        return prev[n] ;

    }

};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

