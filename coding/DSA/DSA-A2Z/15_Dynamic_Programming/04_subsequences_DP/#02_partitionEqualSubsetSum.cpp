#include<bits/stdc++.h>
using namespace std;

/*

this problem is same as subset sum problem , with just an odd sum check and some overflow edge cases
i.e.
if(nums[0]<=k) dp[0][nums[0]] = true;

*/ 

// recursive solution

class Solution {
public:

    int f ( int i , int sum , vector<int>& S , int &k) {

        if ( sum == k ) return true;

        if ( sum > k ) return false;

        if ( i==0 ) return ( (sum + S[i]) == k ) ;

        return f ( i-1 , sum + S[i] , S , k ) || f ( i-1 , sum , S , k ) ;

    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0 ;

        for(int num : nums){
            totalSum += num ;
        }

        if(totalSum % 2 == 1) return false;

        int halfSum = totalSum/2;


        return f( n-1 , 0 , nums , halfSum);

    }
};

// memoization

class Solution {
public:

    vector<vector<int>> memo;

    int f ( int i , int sum , vector<int>& S , int &k) {

        if ( sum == k ) return true;

        if ( sum > k ) return false;

        if ( i==0 ) return ( (sum + S[i]) == k ) ;

        if ( memo[i][sum] != -1 ) return memo[i][sum] ;

        return memo[i][sum] = f ( i-1 , sum + S[i] , S , k ) || f ( i-1 , sum , S , k ) ;

    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0 ;

        for(int num : nums){
            totalSum += num ;
        }

        if(totalSum % 2 == 1) return false;

        int halfSum = totalSum/2;

        memo.assign ( n+1 , vector<int>( halfSum+1 , -1 ) );

        return f( n-1 , 0 , nums , halfSum);

    }
};

// tabulation

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = 0 ;

        for(int num : nums){
            totalSum += num ;
        }

        if(totalSum % 2 == 1) return false;

        int halfSum = totalSum/2;
        int k = halfSum;

        vector<vector<bool>> dp( n+1 , vector<bool>( halfSum+1 , false ) );

        for(int i = 0 ; i < n ; i++ ) { 
            dp[i][0] = true;
        }

        if(nums[0]<=k) dp[0][nums[0]] = true;
        
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=k ; j++){

                bool notTake = dp[i-1][j] ;
                bool take = false;

                if( j >= nums[i]) { // j - arr[i] >= 0
                    take = dp[i-1][j-nums[i]];
                }

                dp[i][j] = take || notTake ;

                // this is a compact form of above logic
                // dp[i][j] = ( (j>=nums[i]) ? ( dp[i-1][j - nums[i]] ) : false )|| dp[i-1][j] ;

            }
        }

        return dp[n-1][k];

    }
};