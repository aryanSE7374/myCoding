#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int idx ,int sum , vector<int>& nums, int target , int n){
        // optimization for nums[i]>=0
        if(sum>target){return 0;}

        // base case
        if(idx == n){
            if(sum == target){return 1;}
            else return 0;
        }

        // sum+=nums[idx];
        int l = f(idx+1 , sum+nums[idx] , nums , target , n );
        // sum-=nums[idx];
        int r = f(idx+1 , sum , nums , target , n );

        return l+r;

    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        return f(0 , 0 , nums , target , n);
    }
};


// a different variation of this question on leetcode