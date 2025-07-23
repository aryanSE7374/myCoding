#include<bits/stdc++.h>
using namespace std;


// Brute Force (B)
// •	Approach: Generate all subsets manually (using bitmasks), compute the sum for each.
// •	How: 2^N subsets using 0/1 representation (include/exclude). For each subset, calculate sum.
// •	Time Complexity:
    // •	Generating all subsets: O(2^N)
    // •	Calculating each subset sum (costly in bitmask approach): O(N * 2^N)
// •	Space Complexity: O(2^N) for storing the sums


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// Subsets II problem on LC

// try 1 : failed on test cases having repeated inputs

class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<int>& path, set<vector<int>>& ans , int n) {

        if (idx == n) {
            ans.insert(path);  // base case: store current subset
            return;
        }

        // 1. Include nums[idx] — go LEFT
        path.push_back(nums[idx]);
        backtrack(idx + 1, nums, path, ans , n);
        path.pop_back();  // backtrack

        // 2. Exclude nums[idx] — go RIGHT
        backtrack(idx + 1, nums, path, ans , n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> ans_set;
        vector<int> path;
        int n = nums.size();
        backtrack(0, nums, path, ans_set , n);
        for(auto it : ans_set){
            ans.push_back(it);
        }
        return ans;
    }
}; 

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// Helper code

// genetate subsets I 
// try 1

class psuedoSolution {
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

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// chatGPT solution 1 : accepted on LC


class Solution {
public:
    void backtrack(int ind, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);  // always push current subset

        for (int i = ind; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > ind && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, ans);
            path.pop_back();  // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());  // key step
        backtrack(0, nums, path, ans);
        return ans;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 