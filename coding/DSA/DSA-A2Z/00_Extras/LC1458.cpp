#include<bits/stdc++.h>
using namespace std;

#define INF 1e9


// rec

class Solution {
public:

    int f ( vector<int>& nums1, vector<int>& nums2 , int i , int j ){

        if ( i==0 || j==0 ){
            return -INF ;
        }

        int i1 = f( nums1 , nums2 , i-1 , j ); // skip 1's last
        int i2 = f( nums1 , nums2 , i , j-1 ); // skip 2's last
        int take = nums1[i-1]*nums2[j-1] + max( 0 , f( nums1 , nums2 , i-1 , j-1 )) ; // include both

        return max ( { i1 , i2 , take } ) ;

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        return f(nums1 , nums2 , n , m );
    }

};

// memo

class Solution {
public:

    vector<vector<int>> dp;

    int f ( vector<int>& nums1, vector<int>& nums2 , int i , int j ){

        if ( i==0 || j==0 ){
            return -INF ;
        }

        if ( dp[i][j] != -INF ) return dp[i][j] ;

        int i1 = f( nums1 , nums2 , i-1 , j ); // skip 1's last
        int i2 = f( nums1 , nums2 , i , j-1 ); // skip 2's last
        int take = nums1[i-1]*nums2[j-1] + max( 0 , f( nums1 , nums2 , i-1 , j-1 )) ; // include both

        return dp[i][j] = max ( { i1 , i2 , take } ) ;

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        dp.assign( n+1 , vector<int>( m+1 , -INF ) ) ;

        return f(nums1 , nums2 , n , m );

    }

};


// tabulate

class Solution {
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp( n+1 , vector<int>( m+1 , -INF ) ) ;

        for( int i=1 ; i<=n ; i++ ){
            for( int j=1 ; j<=m ; j++ ){
                int i1 = dp[i-1][j] ; // skip 1's last
                int i2 = dp[i][j-1] ; // skip 2's last
                int take = nums1[i-1]*nums2[j-1] + max( 0 , dp[i-1][j-1] ) ; // include both

                dp[i][j] = max ( { i1 , i2 , take } ) ;   
            }
        }

        return dp[n][m] ;

    }

};


// space optimization

class Solution {
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<int> prev( m+1 , -INF ) ;
        vector<int> curr( m+1 , -INF ) ;

        for( int i=1 ; i<=n ; i++ ){
            for( int j=1 ; j<=m ; j++ ){
                int i1 = prev[j] ; // skip 1's last
                int i2 = curr[j-1] ; // skip 2's last
                int take = nums1[i-1]*nums2[j-1] + max( 0 , prev[j-1] ) ; // include both

                curr[j] = max ( { i1 , i2 , take } ) ;   
            }
            prev = curr;
        }

        return prev[m] ;

    }

};


// rec method 2 : using n-1 , m-1 as inital pass

class Solution {
public:

    int f ( vector<int>& nums1, vector<int>& nums2 , int i , int j ){

        if ( i<0 || j<0 ){
            return -INF ;
        }

        int i1 = f( nums1 , nums2 , i-1 , j ); // skip 1's last
        int i2 = f( nums1 , nums2 , i , j-1 ); // skip 2's last
        int take = nums1[i]*nums2[j] + max( 0 , f( nums1 , nums2 , i-1 , j-1 )) ; // include both

        return max ( { i1 , i2 , take } ) ;

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        return f(nums1 , nums2 , n-1 , m-1 );
    }

};

// rec method 2 : using n-1 , m-1 as inital pass
// memo

class Solution {
public:

    vector<vector<int>> dp;

    int f ( vector<int>& nums1, vector<int>& nums2 , int i , int j ){

        if ( i<0 || j<0 ){
            return -INF ;
        }

        if ( dp[i][j] != -INF ) return dp[i][j] ;

        int i1 = f( nums1 , nums2 , i-1 , j ); // skip 1's last
        int i2 = f( nums1 , nums2 , i , j-1 ); // skip 2's last
        int take = nums1[i]*nums2[j] + max( 0 , f( nums1 , nums2 , i-1 , j-1 )) ; // include both

        return dp[i][j] = max ( { i1 , i2 , take } ) ;

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        dp.assign( n+1 , vector<int>( m+1 , -INF ) ) ;

        return f(nums1 , nums2 , n-1 , m-1 );
        
    }

};

