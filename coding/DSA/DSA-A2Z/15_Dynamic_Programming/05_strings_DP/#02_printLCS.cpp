#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string printLCS(string s1, string s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        vector<vector<int>> dp ( m+1 , vector<int>( n+1, 0 ) ) ;

        for ( int i=1 ; i<=m ; i++ ) { 
            for ( int j=1 ; j <=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1] ;
                else dp[i][j] = max ( dp[i-1][j] , dp[i][j-1] ) ;
            }
        }

        int len = dp[m][n] ;

        if ( len == 0 ) return "";

        string str(len,'$') ;

        int idx = len-1 , i = m , j = n ;

        while ( i>0 && j>0 ) {
            if ( s1[i-1] == s2[j-1] ) {
                str[idx] = s1[i-1];
                idx--;
                i--;
                j--;
            }
            else if ( dp[i-1][j] > dp[i][j-1] ) i--;
            else j--;
        }

        return str;

    }

};

// follow up : print lexicographically smallest LCS
