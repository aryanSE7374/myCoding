#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
        
        // length of shortest Common Supersequence = n1 + n2 - LCS ( str1 , str2 ) ;
        int m = str1.size() , n = str2.size() ;

        vector<vector<int>> dp ( m+1 , vector<int>( n+1, 0 ) ) ;

        for ( int i=1 ; i<=m ; i++ ) { 
            for ( int j=1 ; j <=n ; j++ ) {
                if ( str1[i-1] == str2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1] ;
                else dp[i][j] = max ( dp[i-1][j] , dp[i][j-1] ) ;
            }
        }

        int len = m + n - dp[m][n] ;

        string str(len,'$') ;

        int idx = len-1 , i = m , j = n ;

        while ( i>0 && j>0 ) {

            if ( str1[i-1] == str2[j-1] ) {
                str[idx] = str1[i-1];
                idx--;
                i--;
                j--;
            }

            else if ( dp[i-1][j] > dp[i][j-1] ) {
                str[idx] = str1[i-1];
                idx--;
                i--;
            }
            else {
                str[idx] = str2[j-1];
                idx--;
                j--;
            }
        }
        while (i>0) {
            str[idx] = str1[i-1];
            idx--;
            i--;
        }
        while(j>0) {
            str[idx] = str2[j-1];
            idx--;
            j--;
        }

        return str ;

    }
};