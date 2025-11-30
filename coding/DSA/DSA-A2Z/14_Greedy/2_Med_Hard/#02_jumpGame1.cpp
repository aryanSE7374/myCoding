#include<bits/stdc++.h>
using namespace std;

// brute using recursion - TLE
// TC : O(2^n)
// SC : O(n)

class Solution {
public:
    bool canJumpFrom(int pos, vector<int>& nums) {

        int n = nums.size();
        if (pos >= n - 1) return true;  // reached or passed last index

        int farthest = pos + nums[pos];
        for (int next = pos + 1; next <= farthest; next++) {

            if (canJumpFrom(next, nums))
                return true;            // if any path works, success
        }

        return false;   // no jump path works
    }

    bool canJump(vector<int>& nums) {
        return canJumpFrom(0, nums);
    }

};

// ----------------------------------------------------------------------- //

// better : memorization
// TC : O(n^2)
// SC : O(n)

class Solution {
public:
    bool canJumpFrom(int pos, vector<int>& nums, vector<int>& memo) {

        int n = nums.size();
        if (pos >= n - 1) return true;

        if (memo[pos] != 0)
            return memo[pos] == 1;   // return GOOD or BAD

        int farthest = min(pos + nums[pos], n - 1);

        for (int next = pos + 1; next <= farthest; next++) {
            if (canJumpFrom(next, nums, memo)) {
                memo[pos] = 1;       // mark GOOD
                return true;
            }
        }

        memo[pos] = -1;              // mark BAD
        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 0);      // 0 = unknown, 1 = good, -1 = bad
        return canJumpFrom(0, nums, memo);
    }
};

// ----------------------------------------------------------------------- //

// optimal - Greedy
// TC : O(n)
// SC : O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int max_r = 0;

        for(int i=0 ; i<n-1 ; i++){
            if(max_r < i) return false;
            max_r = max(max_r , i + nums[i]);
            if(max_r >= n-1) return true;
        }

        return (max_r >= n-1) ;

    }
};

// ----------------------------------------------------------------------- //