#include<bits/stdc++.h>
using namespace std;


// rec code

class Solution {
public:
    int f ( vector<vector<int>>& triangle , int i , int j , const int& n ) {

        if( i==n-1 ) return triangle[i][j];

        return triangle[i][j] + min ( f( triangle , i+1 , j , n ) , f( triangle , i+1 , j+1 , n ) );

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return f( triangle , 0 , 0 , n);
    }
};

// memo

class Solution {
public:

    int f ( vector<vector<int>>& triangle , int i , int j , const int& n , vector<vector<int>>& memo ) {

        if( i==n-1 ) return memo[i][j] = triangle[i][j];

        if( memo[i][j] != -1 ) return memo[i][j] ;

        return memo[i][j] = triangle[i][j] + min ( f( triangle , i+1 , j , n , memo ) , f( triangle , i+1 , j+1 , n , memo ) );

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <vector<int>> memo(n,vector<int>(n,-1));
        return f( triangle , 0 , 0 , n , memo);
    }

};

// tabulate

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <vector<int>> dp(n,vector<int>(n,0));

        dp[0][0] = triangle[0][0];

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                dp[i][j] = triangle[i][j] + min (  (j<i) ? dp[i-1][j] : INT_MAX ,  (j>0) ? dp[i-1][j-1] : INT_MAX )  ;
            }
        }

        int mini = INT_MAX;
        for(int i=0 ; i<n ; i++){
            mini = min ( mini , dp[n-1][i] ) ;
        }

        return mini;

    }
};

// space optimize

// tabulate

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <vector<int>> dp(n,vector<int>(n,0));

        // dp[0][0] = triangle[0][0];

        // for(int i=1 ; i<n ; i++){
        //     for(int j=0 ; j<=i ; j++){
        //         dp[i][j] = triangle[i][j] + min (  (j<i) ? dp[i-1][j] : INT_MAX ,  (j>0) ? dp[i-1][j-1] : INT_MAX )  ;
        //     }
        // }

        // int mini = INT_MAX;
        // for(int i=0 ; i<n ; i++){
        //     mini = min ( mini , dp[n-1][i] ) ;
        // }

        // return mini;

    }
};

// striver's solutions 

// top-down : recursive and memo --> same as above solutions

// bottom-up

// tabulation

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <vector<int>> dp(n,vector<int>(n,0));

        for(int j=0 ; j<n ; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=i ; j>=0 ; j--){
                dp[i][j] = triangle[i][j] + min ( dp[i+1][j] , dp[i+1][j+1] ) ;
            }
        }

        return dp[0][0];

    }
};


// space optimized
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0) , cur(n,0);

        for(int j=0 ; j<n ; j++){
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2 ; i>=0 ; i--){
            for(int j=i ; j>=0 ; j--){
                cur[j] = triangle[i][j] + min ( front[j] , front[j+1] ) ;
            }
            front=cur;
        }

        return front[0];

    }
};
