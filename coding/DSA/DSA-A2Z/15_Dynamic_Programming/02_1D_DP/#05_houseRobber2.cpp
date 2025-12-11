#include<bits/stdc++.h>
using namespace std;


// testcase : [9,6,2,5,6,4,1,8,8,8,9,3,1,1,7,7,9,3,5,9,6,2,5,6,4,1,8,8,8,9,3,1,1,7,7,9,3,5,9,6,2,5,6,4,1,8,8,8,9,3,1,1,7,7,9,3,5,9,6,2,5,6,4,1,8,8,8,9,3,1,1,7,7,9,3,5]

// recursion 

class Solution {
public:

    int f(vector<int>& arr , int n , int s ){

        if( n < s){
            return 0;
        }

        int pick = arr[n] + f(arr,n-2,s); // pick i
        
        int notPick = f(arr,n-1,s); // not pick
        
        return max (pick , notPick) ;

    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        return max ( f(nums,n-1,1) , f(nums,n-2,0) );

    }

};

// memo 

class Solution {
public:

    int f(vector<int>& arr , int n , int s , vector<int>& memo){

        if( n < s){
            return 0;
        }

        if ( memo[n] != -1 ) return memo[n];

        int pick = arr[n] + f(arr,n-2,s,memo); // pick i
        
        int notPick = f(arr,n-1,s,memo); // not pick
        
        return memo[n] = max (pick , notPick) ;

    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n<2) return nums[0];

        vector<int> memo1(n+1 , -1);
        vector<int> memo2(n+1 , -1);

        return max ( f(nums,n-1,1,memo1) , f(nums,n-2,0,memo2) );

    }

};


// tabulation

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n<2) return nums[0];

        vector<int> dp1(n+1 , -1);
        vector<int> dp2(n+1 , -1);

        dp1[0] = nums[0];
        dp2[1] = nums[1];

        for(int i=1 ; i<n-1 ; i++){

            int pick = (i>1) ? nums[i] + dp1[i-2] : nums[i] ; // pick i
            int notPick = dp1[i-1]; // not pick

            dp1[i] = max (pick , notPick) ;

        }

        for(int i=2 ; i<n ; i++){

            int pick = (i>2) ? nums[i] + dp2[i-2] : nums[i] ; // pick i
            int notPick = dp2[i-1]; // not pick

            dp2[i] = max (pick , notPick) ;

        }

        return max ( dp1[n-2] , dp2[n-1] );
        
    }

};


// space optimized DP

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n<2) return nums[0];

        if ( n==2 ) return max(nums[0],nums[1]);

        int dp1curr = nums[1];
        int dp1prev = nums[0];
        int dp1prev2 = 0;

        int dp2curr = nums[2];
        int dp2prev = nums[1];
        int dp2prev2 = 0;

        for(int i=1 ; i<n-1 ; i++){

            int pick = (i>1) ? nums[i] + dp1prev2 : nums[i] ; // pick i
            int notPick = dp1prev; // not pick

            dp1curr = max (pick , notPick) ;
            dp1prev2 = dp1prev;
            dp1prev = dp1curr;

        }

        for(int i=2 ; i<n ; i++){

            int pick = (i>2) ? nums[i] + dp2prev2 : nums[i] ; // pick i
            int notPick = dp2prev; // not pick

            dp2curr = max (pick , notPick) ;
            dp2curr = max (pick , notPick) ;
            dp2prev2 = dp2prev;
            dp2prev = dp2curr;

        }

        return max ( dp1curr , dp2curr );
        
    }

};


// striver's space optimized DP code

class Solution {
public:

    int rob1(vector<int>& nums) {

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

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];
        if (n==2) return max (nums[0] , nums[1]);

        vector<int> nums1 , nums2;

        for(int i=0 ; i<n ; i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=(n-1)) nums2.push_back(nums[i]);
        }

        return max ( rob1(nums1) , rob1(nums2) );

    }

};

