#include<bits/stdc++.h>
using namespace std;

// #4 type 1
// print All the subsequences with sum k

void printS(int ind, vector<int>& ds, int s, int sum, vector<int>& candidates , int n ,vector<vector<int>>& res) {

    if (ind == n) {
        if (s == sum) {
            // for (auto it : ds) cout << it << " ";
            // cout << endl;

        }
        return;
    }

    // Include the current element
    ds.push_back(candidates[ind]);
    s += candidates[ind];
    printS(ind + 1, ds, s, sum, candidates, n , res);

    // Backtrack
    s -= candidates[ind];
    ds.pop_back();

    // Exclude the current element
    printS(ind + 1, ds, s, sum, candidates, n , res);
}


// try 1 on LC : passed


class Solution {
public:
    void combinationSumHelper(int ind, vector<int>& ds, int sum, vector<int>& candidates , int n ,vector<vector<int>>& res) {
        // optimizations
        if(sum==0){
            res.push_back(ds);
            return;
        }
        // if(sum<0){return;}

        // base case
        if (ind == n) {
            if (sum == 0) {
                // vector<int> dummy = ds;
                res.push_back(ds);
            }
            else return;
        }

        // Include the current element

        
        // s += candidates[ind];
        if(candidates[ind]<=sum){
            ds.push_back(candidates[ind]);
            // sum -= candidates[ind];
            combinationSumHelper(ind, ds, sum-candidates[ind], candidates, n , res);
            ds.pop_back();
        }
        // Backtrack
        // s -= candidates[ind];
        // sum += candidates[ind];

        // Exclude the current element
        combinationSumHelper(ind + 1, ds, sum, candidates, n , res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        vector<int> vec = {}; // empty data structure vector
        combinationSumHelper(0 , vec , target , candidates , n , res );
        return res;
    }
};



// try of backtracking function call

void combinationSumHelper(int ind, vector<int>& ds, int sum, vector<int>& candidates , int n ,vector<vector<int>>& res) {
    // optimizations
    if(sum==0){res.push_back(ds);}
    // if(sum<0){return;}

    // base case
    if (ind == n) {
        if (sum == 0) {
            res.push_back(ds);
        }
        else return;
    }

    // Include the current element

    if(candidates[ind]<=sum){
        ds.push_back(candidates[ind]);
        sum -= candidates[ind];
        // s += candidates[ind];
        combinationSumHelper(ind, ds, sum, candidates, n , res);
    }
    // Backtrack
    // s -= candidates[ind];
    sum += candidates[ind];
    ds.pop_back();

    // Exclude the current element
    combinationSumHelper(ind + 1, ds, sum, candidates, n , res);
}



// chatGPT's cleaner implementation


class Solution {
public:
    void helper(int ind, vector<int>& ds, int sum, vector<int>& candidates, int n, vector<vector<int>>& res) {
        if (sum == 0) {
            res.push_back(ds);
            return;
        }
        if (ind == n) return;

        // Pick the current element if it doesn't exceed the remaining sum
        if (candidates[ind] <= sum) {
            ds.push_back(candidates[ind]);
            helper(ind, ds, sum - candidates[ind], candidates, n , res); // Reuse
            ds.pop_back();
        }
        // Don't pick the current element
        helper(ind + 1, ds, sum, candidates, n , res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int n = candidates.size();
        helper(0, ds, target, candidates, n , res);
        return res;
    }
};