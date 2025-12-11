#include<bits/stdc++.h>
using namespace std;


// recursion 

class Solution {
public:
    void f(vector<int>& arr , int n , int i , int sum , int& ans){

        if( i>= n){
            ans = max (ans , sum) ;
            return;
        }

        f(arr,n,i+2,sum+arr[i],ans); // pick i

        f(arr,n,i+1,sum,ans); // not pick

    }
    int rob(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        f(nums,nums.size(),0,sum,ans);
        return ans; 
    }
};


// rec try 2

// recursion 

class Solution {
public:
    int f(vector<int>& arr , int n ){

        if( n < 0){
            return 0;
        }

        int pick = arr[n] + f(arr,n-2); // pick i
        
        int notPick = f(arr,n-1); // not pick
        
        return max (pick , notPick) ;

    }
    int rob(vector<int>& nums) {
        return f(nums,nums.size()-1); 
    }
};

// memorization

class Solution {
public:
    int f(vector<int>& arr , int n , vector<int>& memo ){

        if( n < 0){
            return 0;
        }

        if(memo[n] != -1) return memo[n];

        int pick = arr[n] + f(arr,n-2,memo); // pick i
        
        int notPick = f(arr,n-1,memo); // not pick
        
        return memo[n] = max (pick , notPick) ;

    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> memo(n+1,-1);
        return f(nums,n-1,memo); 
        
    }
};


// tabulation

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1,-1);

        dp[0] = nums[0];

        for(int i=1 ; i<n ; i++){
            int pick = (i>1) ? (nums[i] + dp[i-2]) : nums[i] ;
            int notPick = dp[i-1] ;
            dp[i] = max ( pick , notPick ) ;
        }

        return dp[n-1];
        
    }
};


// space optimized DP

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n<2) return nums[0];

        int curr = nums[1];
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1 ; i<n ; i++){

            int pick = (i>1) ? (nums[i] + prev2) : nums[i] ;
            int notPick = prev ;
            
            curr = max ( pick , notPick ) ;
            prev2 = prev;
            prev = curr;

        }

        return curr;
        
    }
};
