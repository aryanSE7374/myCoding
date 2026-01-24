#include<bits/stdc++.h>
using namespace std;

// GFG : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// tabulation 

class Solution {
    public:

    int longestCommonSubstr(string& s1, string& s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        int ans = 0;

        vector<vector<int>> dp(m+1 , vector<int>(n+1,0));

        for ( int i=1 ; i<=m ; i++ ) {
            for ( int j=1 ; j<=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max ( ans , dp[i][j] ) ;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return ans;
        
    }
};

// space optimization

class Solution {
    public:

    int longestCommonSubstr(string& s1, string& s2) {

        int m = s1.size() ;
        int n = s2.size() ;

        int ans = 0;

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for ( int i=1 ; i<=m ; i++ ) {
            for ( int j=1 ; j<=n ; j++ ) {
                if ( s1[i-1] == s2[j-1] ) {
                    curr[j] = 1 + prev[j-1];
                    ans = max ( ans , curr[j] ) ;
                }
                else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return ans;
        
    }
};