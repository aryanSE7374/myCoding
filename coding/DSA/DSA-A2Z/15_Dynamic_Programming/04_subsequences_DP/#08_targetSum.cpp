#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // space optimize

    int findWays(vector<int>& arr, int k)
    {
        int n = arr.size();

        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);

        // dp[i] = curr , dp[i-1] = prev

        int MOD = 1e9 + 7;

        for(int j=0 ; j<=k ; j++){
            prev[j] = ( j==0 && arr[0] == 0 ) ? 2 : ( ( j==0 || j == arr[0] ) ? 1 : 0 ) ;
        }

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=k ; j++){
                int notTake = prev[j];
                int take = 0;
                if ( j >= arr[i] ) take = prev[j-arr[i]] ;
                curr[j] = (notTake + take) % MOD ;
            }
            prev = curr;
        }

        return prev[k];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int S = 0;
        for(int i=0 ; i<n ; i++){
            S += arr[i];
        }
        if ( S-d < 0 || (S-d)%2 == 1 ) return 0;
        int k = (S-d)/2 ;
        return findWays(arr , k );
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        return countPartitions( n , target , nums ) ;
    }
    
};


// ---------------------------------------------------------------- // 

// rec - get submitted on LC
class Solution {
public:
    int f(vector<int>& nums, int target , int n , int sum){

        if(n==0){
            return ((sum + nums[0] == target) ? 1 : 0) + ((sum - nums[0] == target) ? 1 : 0);
        }

        return f(nums,target,n-1,sum+nums[n]) + f(nums,target,n-1,sum-nums[n]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(nums , target , n-1 , 0);
    }
};

// rec : modified - get submitted on LC
class Solution {
public:
    int f(vector<int>& nums, int target , int n ){

        if(n==0){
            return ((target - nums[0] == 0) ? 1 : 0) + ( (target + nums[0] == 0) ? 1 : 0);
        }

        return f(nums,target+nums[n],n-1) + f(nums,target-nums[n],n-1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(nums , target , n-1 );
    }
};


// memo on modified rec - index out of bound due to possible negative target arguments , soln
class Solution {
public:
    vector<vector<int>> memo;
    int f(vector<int>& nums, int target , int n ){

        if(n==0){
            return ((target - nums[0] == 0) ? 1 : 0) + ( (target + nums[0] == 0) ? 1 : 0);
        }

        if ( memo[n][target] != -1 ) return memo[n][target] ;

        return memo[n][target] = f(nums,target+nums[n],n-1) + f(nums,target-nums[n],n-1);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memo.assign ( n+1 , vector<int>( target+1 , -1 ) ) ;
        return f(nums , target , n-1 );
    }
};


// solution : offset DP

class Solution {
public:
    vector<vector<int>> memo;
    int offset;

    int f(vector<int>& nums, int target, int n) {

        // critical bounds check
        if (target < -offset || target > offset)
            return 0;

        if (n == 0) {
            return ((target - nums[0] == 0) ? 1 : 0) +
                   ((target + nums[0] == 0) ? 1 : 0);
        }

        if (memo[n][target + offset] != -1)
            return memo[n][target + offset];

        return memo[n][target + offset] =
            f(nums, target + nums[n], n - 1) +
            f(nums, target - nums[n], n - 1);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;

        if (abs(target) > sum) return 0;

        offset = sum;
        memo.assign(n, vector<int>(2 * sum + 1, -1));

        return f(nums, target, n - 1);
    }
};