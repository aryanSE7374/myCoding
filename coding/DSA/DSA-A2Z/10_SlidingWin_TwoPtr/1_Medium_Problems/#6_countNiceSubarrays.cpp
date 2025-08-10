#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysAtMostGoal1s(vector<int>& nums, int goal){
        if(goal<0){return 0;}//edge case to handle goal=0 => goal-1<0
        int l=0 , r=0 , sum = 0 , count = 0;
        int n = nums.size();
        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-= nums[l]%2;
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarraysAtMostGoal1s(nums , k) - subarraysAtMostGoal1s(nums , k-1);
    }
};