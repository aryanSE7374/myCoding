#include<bits/stdc++.h>
using namespace std;


// my try 1 : Rec -> memo

class Solution {
private:
    int n;
    vector<vector<int>> memo;

    int dfs(int i, int j, vector<vector<int>>& A) {

        if (j < 0 || j >= n) return INT_MAX/2; 

        if (i == n - 1) return A[i][j];

        if (memo[i][j] != INT_MAX) 
            return memo[i][j];

        int down = dfs(i + 1, j, A);
        int downLeft = dfs(i + 1, j - 1, A);
        int downRight = dfs(i + 1, j + 1, A);

        return memo[i][j] = A[i][j] + min({down , downLeft , downRight});
    }

public:
    int minFallingPathSum(vector<vector<int>>& A) {
        n = A.size();
        memo.assign(n, vector<int>(n , INT_MAX));

        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            ans = min(ans , dfs(0 , j , A));
        }
        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------ // 


// Solution by Striver
// recursive - top-down

class Solution {
private:

    int dfs(int i, int j, vector<vector<int>>& A , int n) {

        if (j < 0 || j >= n) return INT_MAX; 

        if (i == 0) return A[i][j];


        int down = dfs( i - 1 , j , A , n);
        int downLeft = dfs( i - 1 , j - 1 , A , n);
        int downRight = dfs( i - 1 , j + 1 , A , n);

        return A[i][j] + min ( { down , downLeft , downRight } );

    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            ans = min(ans , dfs( n-1 , j , matrix , n));
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------ // 

// memoization - top-down

class Solution {
private:

    vector<vector<int>> memo;

    int dfs(int i, int j, vector<vector<int>>& A , int n) {

        if (j < 0 || j >= n) return INT_MAX; 

        if (i == 0) return A[i][j];

        if (memo[i][j] != INT_MAX) 
            return memo[i][j];

        int down = dfs( i - 1 , j , A , n);
        int downLeft = dfs( i - 1 , j - 1 , A , n);
        int downRight = dfs( i - 1 , j + 1 , A , n);

        return memo[i][j] = A[i][j] + min ( { down , downLeft , downRight } );

    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        memo.assign(n, vector<int> ( n , INT_MAX ));

        int ans = INT_MAX;

        for(int j = 0 ; j < n ; j++){
            ans = min(ans , dfs( n-1 , j , matrix , n));
        }

        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------ // 

// tabulation - bottom-down

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp( n+1 , vector<int>(n+1,INT_MAX) );

        for ( int i = 0 ; i < n ; i++ ){
            for ( int j = 0 ; j < n ; j++ ){

                int down = (i>0) ? dp[i-1][j] : INT_MAX;
                int downLeft = (i>0 && j>0) ? dp[i-1][j-1] : INT_MAX;
                int downRight = (i>0 && j<n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = (i==0) ? matrix[i][j] : matrix[i][j] + min ( { down , downLeft , downRight } );
            }
        }

        int ans = INT_MAX;

        for(int j=0 ; j<n ; j++){
            ans = min ( ans , dp[n-1][j]);
        }
        
        return ans;

    }
};

// ------------------------------------------------------------------------------------------------------------------ // 

// space optimized DP

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<int> prev(n+1,INT_MAX);
        vector<int> curr(n+1,INT_MAX);

        for ( int i = 0 ; i < n ; i++ ){
            for ( int j = 0 ; j < n ; j++ ){

                // dp[i-1] is prev
                // dp[i] is curr

                int down = (i>0) ? prev[j] : INT_MAX;
                int downLeft = (i>0 && j>0) ? prev[j-1] : INT_MAX;
                int downRight = (i>0 && j<n-1) ? prev[j+1] : INT_MAX;

                curr[j] = (i==0) ? matrix[i][j] : matrix[i][j] + min ( { down , downLeft , downRight } );
            }
            prev = curr;
        }

        int ans = INT_MAX;

        for(int j=0 ; j<n ; j++){
            ans = min ( ans , prev[j]);
        }
        
        return ans;

    }
};

// ------------------------------------------------------------------------------------------------------------------ // 