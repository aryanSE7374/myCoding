#include<bits/stdc++.h>
using namespace std;

// recursive code

class Solution {
public:

    int f( vector<vector<int>>& grid , int i , int j){

        if( i==0 && j==0 ) return grid[i][j];

        if(i<0 || j<0) return INT_MAX;

        return grid[i][j] + min ( f(grid,i-1,j) , f(grid,i,j-1) ) ;

    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        return f(grid , m-1 , n-1);

    }

};


// memo code

class Solution {
public:

    int f( vector<vector<int>>& grid , int i , int j , vector<vector<int>>& memo){

        if( i==0 && j==0 ) return grid[i][j];

        if(i<0 || j<0) return INT_MAX;

        if( memo[i][j] != -1 ) return memo[i][j] ;

        return memo[i][j] = grid[i][j] + min ( f(grid,i-1,j,memo) , f(grid,i,j-1,memo) ) ;

    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> memo(m,vector<int>(n,-1));

        return f(grid , m-1 , n-1 , memo);

    }
    
};


// tabulate code

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){

                if( i==0 && j==0 ) dp[i][j] = grid[i][j];

                else dp[i][j] = grid[i][j] + min ( (i>0) ? dp[i-1][j] : INT_MAX , (j>0) ? dp[i][j-1] : INT_MAX ) ;
                
            }
        }

        return dp[m-1][n-1] ;

    }
    
};


// space optimized code

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n,0);

        for(int i=0 ; i<m ; i++){

            vector<int> temp(n,0);

            for(int j=0 ; j<n ; j++){

                if( i==0 && j==0 ) temp[j] = grid[i][j];

                else temp[j] = grid[i][j] + min ( (i>0) ? prev[j] : INT_MAX , (j>0) ? temp[j-1] : INT_MAX ) ;

            }

            prev = temp;
            
        }

        return prev[n-1] ;

    }
    
};



// striver's tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } 
                else {
                    int up = grid[i][j];
                    if (i > 0) up += dp[i - 1][j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if (j > 0) left += dp[i][j - 1];
                    else left += 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};