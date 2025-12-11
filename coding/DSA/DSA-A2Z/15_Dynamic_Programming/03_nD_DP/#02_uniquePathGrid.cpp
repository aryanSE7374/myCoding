#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------------ //

// my solutions

// rec sol

class Solution{
public:

    int f(int i , int j){

        if(i==0 && j==0) return 1;

        int up = (i>0) ? f(i-1,j) : 0;
        int left = (j>0) ? f(i,j-1) : 0;

        return up + left;

    }

    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }

};

// memo

class Solution{
public:

    int f(int i , int j , vector<vector<int>>& memo){

        if(i==0 && j==0) return 1;

        if(memo[i][j] != -1) return memo[i][j];

        int up = (i>0) ? f(i-1,j,memo) : 0;
        int left = (j>0) ? f(i,j-1,memo) : 0;

        return memo[i][j] = up + left;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return f(m-1,n-1,memo);
    }

};


// tabulate

class Solution{
public:

    int uniquePaths(int m, int n) {

        if(m==1 || n==1) return 1;

        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0] = 1;

        for(int i=0 ; i<m ; i++ ){

            for(int j=0 ; j<n ; j++ ){

                if(i==0 || j==0) {
                    dp[i][j] = 1;
                    continue;
                }


                int up = dp[i-1][j] ;
                int left = dp[i][j-1] ;

                dp[i][j] = up + left ;

            }

        }

        return dp[m-1][n-1] ;

    }

};


// space optimized DP

class Solution{
public:

    int uniquePaths(int m, int n) {

        if(m==1 || n==1) return 1;
        
        vector<int> dp(n,1); // dp[i-1]

        for(int i=1 ; i<m ; i++ ){

            vector<int> temp(n); // dp[i]

            for(int j=0 ; j<n ; j++ ){

                if(j==0) {
                    temp[j] = 1;
                    continue;
                }

                temp[j] = dp[j] + temp[j-1];

            }

            dp = temp;

        }

        return dp[n-1] ;

    }

};


// ------------------------------------------------------------------------------------ //

// striver's recursive algo

class Solution {
public:
    int f(int i, int j) {
        // Base Case
        if(i == 0 && j == 0) return 1;
        
        // Boundary check
        if(i < 0 || j < 0) return 0;
        
        // Recursive calls
        int up = f(i - 1, j);
        int left = f(i, j - 1);
        
        return up + left;
    }
    
    int uniquePaths(int m, int n) {
        return f(m - 1, n - 1);
    }
};

// striver's memo code

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& memo) {
        // Base Case
        if(i == 0 && j == 0) return 1;
        
        // Boundary check
        if(i < 0 || j < 0) return 0;
        
        // Check memo
        if(memo[i][j] != -1) return memo[i][j];
        
        // Recursive calls
        int up = f(i - 1, j, memo);
        int left = f(i, j - 1, memo);
        
        return memo[i][j] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return f(m - 1, n - 1, memo);
    }
};

// striver's tabulation code

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

// striver's space optimized code

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    cur[j] = 1;
                }
                else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = cur[j-1];
                    cur[j] = up + left;
                }
            }
            
            prev = cur;
        }
        
        return prev[n-1];
    }
};


// ------------------------------------------------------------------------------------ //

// insta reel sol (tabulation)

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector< vector<int> > vec( m , vector<int>(n) );

        for(int i=0 ; i<m ; i++){
            vec[i][0] = 1;
        }

        for(int i=0 ; i<n ; i++){
            vec[0][i] = 1;
        }

        for(int i=1 ; i<m ; i++) {
            for (int j=1 ; j<n ; j++) {
                vec[i][j] = vec[i-1][j] + vec[i][j-1];
            }
        }

        return vec[m-1][n-1];

    }
};

// ------------------------------------------------------------------------------------ //

// most optimal combinatorics based soltuion (not DP)

class Solution {
public:
    int uniquePaths(int m, int n) {

        int N = n + m - 2;  // Total moves needed
        int r = m - 1;      // Number of down moves
        double res = 1;
        
        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        
        return (int)res;
        
    }
};


// ------------------------------------------------------------------------------------ //