#include<bits/stdc++.h>
using namespace std;

// try s = "zjveiiwvc" , ans = 5

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

    int minInsertions(string s) {
        
        int n = s.size ( ) ;
        return n - longestPalindromeSubseq(s);

    }
};