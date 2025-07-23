#include<bits/stdc++.h>
using namespace std;


// brute force

// 1.Consider each element either present or absent.
// 2.Enumerate every one of the 2ⁿ binary states and collect elements whose bit is 1.
// 3.Complexity – Time O(n·2ⁿ) (because for each mask we may scan up to n bits);
//                Space O(2ⁿ·n) for the output.

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n;  // 2^n subsets
    vector<vector<int>> ans;

    for (int mask = 0; mask < total; ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            // Check if the ith bit in mask is set (1)
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}


// better try 1
// Time O(n·2ⁿ) 
// Space O(2ⁿ·n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        int n = nums.size();
        // vector<vector<int>> curr = res;
        for(int i=0 ; i<n ; i++){
            vector<vector<int>> curr = res;
            for(int j=0 ; j<curr.size() ;j++){
                curr[j].push_back(nums[i]);
                res.push_back(curr[j]);
            }
        }
        return res;
    }
};

// optimal backtracking based solution

// left side is for exclude the element , and right is to include it

class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(path);  // save the current subset
            return;
        }

        // 1. Exclude nums[idx]
        backtrack(idx + 1, nums, path, ans);

        // 2. Include nums[idx]
        path.push_back(nums[idx]);
        backtrack(idx + 1, nums, path, ans);
        path.pop_back();  // backtrack to previous state
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);
        return ans;
    }
};



// otimal alternative implementation : 
// •	Left side means include the element
// •	Right side means exclude the element

class Solution {
public:
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

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(0, nums, path, ans);
        return ans;
    }
};



