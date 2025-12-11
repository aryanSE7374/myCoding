#include<bits/stdc++.h>
using namespace std;

// my rec soln

class Solution {
public:

    int f( vector<vector<int>>& grid, int i , int j ) {

        if( i == 0 && j==0 ) return 1;

        int up , left;

        if( i>0 && grid[i-1][j] == 1 ) up = 0 ;
        else up = (i>0) ? f(grid,i-1,j) : 0 ;
        
        if( j>0 && grid[i][j-1] == 1 ) left = 0 ;
        else left = (j>0) ? f(grid,i,j-1) : 0 ;

        return up + left;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if ( obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1 ) return 0;

        return f(obstacleGrid,m-1,n-1);

    }
};

// my memo soln

class Solution {
public:

    int f( vector<vector<int>>& grid, int i , int j , vector<vector<int>>& memo ) {

        if( i == 0 && j==0 ) return 1;

        if(memo[i][j] != -1) return memo[i][j] ;

        int up , left;

        if( i>0 && grid[i-1][j] == 1 ) up = 0 ;
        else up = (i>0) ? f(grid,i-1,j,memo) : 0 ;
        
        if( j>0 && grid[i][j-1] == 1 ) left = 0 ;
        else left = (j>0) ? f(grid,i,j-1,memo) : 0 ;

        return memo[i][j] = up + left;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if ( obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1 ) return 0;

        vector<vector<int>> memo(m,vector<int>(n,-1));

        return f(obstacleGrid,m-1,n-1,memo);

    }
};


// my tabulation soln

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if ( obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1 ) return 0;

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){

                if ( i==0 && j==0 ) dp[0][0] = 1;

                else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

                else{
                    // int left = (i>0 && ( obstacleGrid[i-1][j] == 0 ) ) ? dp[i-1][j] : 0 ;
                    // int right = (j>0 && ( obstacleGrid[i][j-1] == 0 ) ) ? dp[i][j-1] : 0 ;

                    int up = (i>0) ? dp[i-1][j] : 0 ;
                    int left = (j>0) ? dp[i][j-1] : 0 ;
                    
                    dp[i][j] = up + left ;
                    
                }

            }
        }

        return dp[m-1][n-1] ;

    }
};

// my space optimized code

class Solution{
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> dp(n,1); // dp[i-1]

        for(int i=0 ; i<m ; i++ ){

            vector<int> temp(n); // dp[i]

            for(int j=0 ; j<n ; j++ ){

                if( obstacleGrid[i][j] == 1 ){
                    temp[j] = 0;
                }
                else if(i==0 && j==0) {
                    temp[j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = dp[j];
                    if(j > 0) left = temp[j-1];
                    temp[j] = up + left;
                }

            }

            dp = temp;

        }

        return dp[n-1] ;

    }

};



// ------------------------------------------------------------------------------------ //

// striver's rec

class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j) {

        if( i>=0 && j>=0 && grid[i][j] == 1 ) return 0;

        // Base Case
        if(i == 0 && j == 0) return 1;
        
        // Boundary check
        if(i < 0 || j < 0) return 0;
        
        // Recursive calls
        int up = f(grid, i - 1, j);
        int left = f(grid, i, j - 1);
        
        return up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return f( obstacleGrid, m - 1, n - 1);
    }
};



// striver's memo

class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {

        if( i>=0 && j>=0 && grid[i][j] == 1 ) return 0;

        // Base Case
        if(i == 0 && j == 0) return 1;
        
        // Boundary check
        if(i < 0 || j < 0) return 0;

        if( memo[i][j] != -1 ) return memo[i][j] ;
        
        // Recursive calls
        int up = f(grid, i - 1, j, memo);
        int left = f(grid, i, j - 1, memo);
        
        return memo[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> memo(m,vector<int>(n,-1));

        return f( obstacleGrid, m - 1, n - 1, memo);
    }
};


// striver's tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if ( obstacleGrid[i][j] == 1 ) {
                    dp[i][j] = 0;    
                }
                else if(i == 0 && j == 0) {
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            
            for(int j = 0; j < n; j++) {

                if( obstacleGrid[i][j] == 1 ){
                    cur[j] = 0;
                }
                else if(i == 0 && j == 0) {
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






/*

sample testcases : 

1.

[
[0,0,0,1,1,0],
[0,0,0,1,1,0],
[0,0,1,1,0,1],
[0,0,0,1,1,0],
[0,0,0,1,1,0],
[0,0,1,1,0,1],
[0,0,0,1,1,0],
[0,0,0,1,1,0],
[0,0,0,0,0,0]
]

2.

[
[0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0],
[1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1],
[0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0],
[0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
[0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0],
[1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0],
[0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],
[1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,1],
[0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0],
[0,0,1,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],
[0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0],
[0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0],
[0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0],
[0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0],
[0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,1],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1],
[0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0],
[0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1],
[0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0],
[0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0],
[0,0,0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1],
[0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0],
[0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0]
]

*/