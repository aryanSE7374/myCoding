#include<bits/stdc++.h>
using namespace std;

// rec

class Solution {
public:

    int f ( string& s1 , string& s2 , int i , int j ) {

        if ( j<0 ) return 1;

        if ( i<0 ) return 0;

        if ( s1[i] == s2[j] ) {
            return f(s1,s2,i-1,j) + f(s1,s2,i-1,j-1) ;
        }

        return f ( s1,s2,i-1,j ) ;

    }

    int numDistinct(string s, string t) {

        int m = s.size(), n = t.size();

        return f (s,t,m-1,n-1);

    }

};

// memo-1 : submitted

class Solution {
public:

    vector<vector<int>> dp;

    int f ( string& s1 , string& s2 , int i , int j ) {

        if ( j<0 ) return 1;

        if ( i<0 ) return 0;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s1[i] == s2[j] ) {
            return dp[i][j] = f(s1,s2,i-1,j) + f(s1,s2,i-1,j-1) ;
        }

        return dp[i][j] = f ( s1,s2,i-1,j ) ;

    }

    int numDistinct(string s, string t) {

        int m = s.size(), n = t.size();

        dp.assign( m+1 , vector<int> ( n+1 , -1 ) ) ;

        return f (s,t,m-1,n-1);

    }

};

// memo-2 ( tabulable memo recurrance ) : submitted

class Solution {
public:

    vector<vector<int>> dp;

    int f ( string& s1 , string& s2 , int i , int j ) {

        if ( j==0 ) return 1;

        if ( i==0 ) return 0;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        if ( s1[i-1] == s2[j-1] ) {
            return dp[i][j] = f(s1,s2,i-1,j) + f(s1,s2,i-1,j-1) ;
        }

        return dp[i][j] = f ( s1,s2,i-1,j ) ;

    }

    int numDistinct(string s, string t) {

        int m = s.size(), n = t.size();

        dp.assign( m+1 , vector<int> ( n+1 , -1 ) ) ;

        return f (s,t,m,n);

    }

};

// tabualate

#define ll long long 

class Solution {
public:

    int numDistinct(string s1, string s2) {

        ll mod = 1e9 + 7;

        int m = s1.size(), n = s2.size();

        vector<vector<ll>> dp( m+1 , vector<ll> ( n+1 , 0 ) ) ;

        for ( int i=0 ; i<=m ; i++ ) {
            dp[i][0] = 1;
            // cout << dp[i][0] << " " ;
        }

        // cout << endl;

        for ( int i=1 ; i<=m ; i++ ) {

            // cout << dp[i][0] << " " ;

            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod ;
                }

                else { 
                    dp[i][j] = dp[i-1][j] ;
                }

                // cout << dp[i][j] << " " ;

            }

            // cout << endl ;
            
        }

        return dp[m][n] ;

    }

};


// space optimized DP

#define ll long long 

class Solution {
public:

    int numDistinct(string s1, string s2) {

        ll mod = 1e9 + 7;

        int m = s1.size(), n = s2.size();

        vector<vector<ll>> dp( m+1 , vector<ll> ( n+1 , 0 ) ) ;

        vector<ll> prev( n+1 , 0 ) ;
        vector<ll> curr( n+1 , 0 ) ;

        prev[0] = 1;
        curr[0] = 1;

        for ( int i=1 ; i<=m ; i++ ) {

            for ( int j=1 ; j<=n ; j++ ) {

                if ( s1[i-1] == s2[j-1] ) {
                    curr[j] = (prev[j] + prev[j-1]) % mod ;
                }

                else { 
                    curr[j] = prev[j] ;
                }

            }

            prev = curr ;
            
        }

        return prev[n] ;

    }

};

// more optimal space - one array DP

#define ll long long 

class Solution {
public:

    int numDistinct(string s1, string s2) {

        ll mod = 1e9 + 7;

        int m = s1.size(), n = s2.size();

        vector<vector<ll>> dp( m+1 , vector<ll> ( n+1 , 0 ) ) ;

        vector<ll> curr( n+1 , 0 ) ;

        curr[0] = 1;

        for ( int i=1 ; i<=m ; i++ ) {

            for ( int j=n ; j>=1 ; j-- ) {

                if ( s1[i-1] == s2[j-1] ) {
                    curr[j] = (curr[j] + curr[j-1]) % mod ;
                }

            }
            
        }

        return curr[n] ;

    }

};
