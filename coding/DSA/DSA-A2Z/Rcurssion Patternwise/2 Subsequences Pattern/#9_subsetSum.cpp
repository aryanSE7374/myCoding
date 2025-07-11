#include<bits/stdc++.h>
using namespace std;



// power set helper func

void backtrack(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(path);  // base case: store current subset
        return;
    }

    // 1. Include nums[idx] — go LEFT
    path.push_back(nums[idx]);
    backtrack(idx + 1, nums, path, ans);
    path.pop_back();  // backtrack

    // 2. Exclude nums[idx] — go RIGHT
    backtrack(idx + 1, nums, path, ans);
}


/*
// call

vector<vector<int>> ans;
vector<int> path;
backtrack(0, nums, path, ans);
*/

// try 1 : correct


// TC : O(2^N)
// SC : O(2^N)

class Solution {
  public:
    void backtrack(int idx, vector<int>& nums, int sum , vector<int>& ans) {
        if (idx == nums.size()) {
            ans.push_back(sum);  // base case: store current subset
            return;
        }

        // 1. Include nums[idx] — go LEFT
        // path.push_back(nums[idx]);
        // sum+=nums[idx];
        backtrack(idx + 1, nums, sum+nums[idx], ans);
        // path.pop_back();  // backtrack

        // 2. Exclude nums[idx] — go RIGHT
        backtrack(idx + 1, nums, sum, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        sort(arr.begin() , arr.end());
        backtrack( 0 , arr , 0 , ans);
        return ans;
    }
};



// lil bit optimization by chatGPT : same as given by striver

// Remove sort(arr.begin(), arr.end()) — no use in sorting input;
// just sort the final output (ans) for expected non-decreasing order.

// TC : O(2^N)
// SC : O(2^N)

class Solution {
  public:
    void backtrack(int idx, vector<int>& nums, int sum , vector<int>& ans) {
        if (idx == nums.size()) {
            ans.push_back(sum);  // base case: store current subset
            return;
        }

        // 1. Include nums[idx] — go LEFT
        // path.push_back(nums[idx]);
        // sum+=nums[idx];
        backtrack(idx + 1, nums, sum+nums[idx], ans);
        // path.pop_back();  // backtrack

        // 2. Exclude nums[idx] — go RIGHT
        backtrack(idx + 1, nums, sum, ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        backtrack(0, arr, 0, ans);
        sort(ans.begin(), ans.end());  // sort AFTER generating subset sums
        return ans;
    }
};