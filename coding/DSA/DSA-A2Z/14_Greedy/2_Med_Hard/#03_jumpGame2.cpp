#include<bits/stdc++.h>
using namespace std;



// try 1 : passed
// optimal - Reverse Greedy
// TC : O(n)
// SC : O(n) can be optimized to O(1)

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n , 0);

        for(int i=0 ; i<n ; i++){
            dp[i] = i + nums[i];
        }

        int min_jump = 0;

        int i = n-1;
        // int curr = n-1;
        while( i>0 ){
            for(int j=0 ; j<n-1 ; j++){
                if(dp[j] >= i){
                    i=j;
                    min_jump++;
                    break;
                }
            }
        }

        return min_jump;

    }
};


// ----------------------------------------------------------------------- //

// space optimized version of try 1


class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int min_jump = 0;

        int i = n-1;

        while( i>0 ){
            
            for(int j=0 ; j<n-1 ; j++){
                if(j + nums[j] >= i){
                    i=j;
                    min_jump++;
                    break;
                }
            }
            
        }

        return min_jump;

    }
};


// ----------------------------------------------------------------------- //

// brute using recursion - TLE
// TC : O(n^n)
// SC : O(n)


class Solution {
public:
    int helper(vector<int>& nums , int idx , int n , int jumps ){
        

        if(idx >= n-1){
            return jumps;
        }


        int mini = INT_MAX;
        for(int i=idx+1 ; i<n && i <= idx+nums[idx] ; i++){
            mini = min(mini , helper(nums , i , n , jumps+1 ));
        }

        return mini;

    }

    int jump(vector<int>& nums) {

        // idx , n  , numJumps
        int n = nums.size();
        return helper(nums , 0 , n , 0 );

    }
};

// ----------------------------------------------------------------------- //

// better : memorization of n^2 space - TLE
// TC : O(n^3)
// SC : O(n^2)


class Solution {
public:
    int helper(vector<int>& nums , int idx , int n , int jumps , vector<vector<int>>& memo){
        

        if(idx >= n-1){
            return jumps;
        }

        if( memo[idx][jumps] != -1)  return memo[idx][jumps];


        int mini = INT_MAX;
        for(int i=idx+1 ; i<n && i <= idx+nums[idx] ; i++){
            mini = min(mini , helper(nums , i , n , jumps+1 , memo));
        }

        memo[idx][jumps] = mini;
        return mini;

    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        // vector<int> memo(n+1,-1);

        // idx , n  , numJumps
        vector<vector<int>> memo(n+1 , vector<int>(n+1,-1));
        return helper(nums , 0 , n , 0 , memo);

    }
};
// ----------------------------------------------------------------------- //

// optimal - Greedy : Concept of Range Based greedy
// TC : O(n)
// SC : O(1)

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int l=0 , r=0 , jumps = 0;

        while (r < n-1)
        {
            jumps++;
            int maxReach = r+1;

            for (int i = 0; i <= r; i++)
            {
                maxReach = max(maxReach , i + nums[i]);
            }

            l = r+1;
            r = maxReach;
            
        }

        return jumps;
        
    }
};

// ----------------------------------------------------------------------- //