#include<bits/stdc++.h>
using namespace std;

// try 1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = 0;
        for(vector<int> vec : triangle){
            int n = vec.size();
            int mini = INT_MAX;
            for(int i=0 ; i<n ; i++){
                mini = min(mini , vec[i]);
            }
            sum += mini;
        }
        return sum;
    }
};


// try 2
// [[-1],[2,3],[1,-1,-3]]
//   -1
//   2,3
// 1,-1,-3
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = {triangle[0][0]};

        for(int i=1 ; i<n ; i++){
            int m = triangle[i].size();
            for(int j=0 ; j<m ; j++){
                // dp[i][j] = triangle[i][j] + min(triangle[i-1][j] , triangle[i-1][j-1] );
                if(j!=0){
                    dp[i].push_back( triangle[i][j] + min(triangle[i-1][j] , triangle[i-1][j-1] ));
                }
                else{
                    dp[i].push_back( triangle[i][j] + triangle[i-1][j]);
                }
            }
        }

        int res = INT_MAX;

        for(int i=0 ; i<n ; i++){
            res = min(res , dp[n-1][i]);
        }

        return res;
    }
};



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = {triangle[0][0]};

        for (int i = 1; i < n; i++) {
            int m = triangle[i].size();
            dp[i].resize(m);  // 🔹 FIX 1: resize instead of push_back

            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    // 🔹 FIX 2: leftmost element only comes from directly above
                    dp[i][j] = triangle[i][j] + dp[i-1][0];
                } 
                else if (j == m - 1) {
                    // 🔹 FIX 3: rightmost element only comes from top-left
                    dp[i][j] = triangle[i][j] + dp[i-1][m-2];
                } 
                else {
                    // 🔹 FIX 4: middle elements take min of two parents
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }

        int res = INT_MAX;
        for (int val : dp[n-1]) {
            res = min(res, val);
        }

        return res;
    }
};