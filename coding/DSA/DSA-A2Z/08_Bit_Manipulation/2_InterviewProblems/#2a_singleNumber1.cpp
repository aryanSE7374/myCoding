#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            res^=nums[i];
        }
        return res;
    }
};


// variation : LC 268 : missing number in range

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0 , xor2 = 0;
        for(int i=0 ; i<nums.size() ; i++){
            xor2^=nums[i]; // contains the xor of all the numbers in the array nums
            xor1^=i+1; // contains xor of all the nums in the range [0,n]
        }
        return xor1^xor2; // cancels out all the numbers thus remaining only one missing number
    }
};

// LC 287 : https://leetcode.com/problems/find-the-duplicate-number/

// my sol 1
// TC : O(N * logN) , SC : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i=1 ; i<n ; i++){
            if(nums[i]==nums[i-1]){return nums[i];}
        }
        return 0; // dummy return
    }
};

// Bit solution

// TC: O(32 * n) ≈ O(n), SC: O(1)
int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int duplicate = 0;

    for (int bit = 0; bit < 32; ++bit) {
        int mask = 1 << bit;
        int countNums = 0, countRange = 0;

        for (int num : nums) {
            if (num & mask) countNums++;
        }

        for (int i = 1; i <= n; ++i) {
            if (i & mask) countRange++;
        }

        if (countNums > countRange) {
            duplicate |= mask;
        }
    }

    return duplicate;
}
