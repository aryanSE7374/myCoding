#include<bits/stdc++.h>
using namespace std;


// ------------------------------------------------------------------------------------------------------------------------------------ // 

/*

// combination target 1 ka code
class Solution {
public:
    void helper(int ind, vector<int>& ds, int target, vector<int>& candidates, int n, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }
        if (ind == n) return;

        // Pick the current element if it doesn't exceed the remaining target
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            helper(ind+1, ds, target - candidates[ind], candidates, n , res); // Reuse
            ds.pop_back();
        }
        // Don't pick the current element
        helper(ind + 1, ds, target, candidates, n , res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int n = candidates.size();
        helper(0, ds, target, candidates, n , res);
        return res;
    }
};



// try 1

class Solution {
public:
void helper(int ind, vector<int>& ds, int target, vector<int>& candidates, int n, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }
        if (ind == n) return;

        // Pick the current element if it doesn't exceed the remaining target
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            helper(ind+1, ds, target - candidates[ind], candidates, n , res); // Reuse
            ds.pop_back();
        }
        // Don't pick the current element
        helper(ind + 1, ds, target, candidates, n , res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int n = candidates.size();
        helper(0, ds, target, candidates, n , res);
        return res;
        
        
    }
};


// try 2

class Solution {
public:
void helper(int ind, vector<int>& ds, int target, vector<int>& candidates, int n, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }
        if (ind == n) return;

        // Pick the current element if it doesn't exceed the remaining target
        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            helper(ind+1, ds, target - candidates[ind], candidates, n , res); // Reuse
            ds.pop_back();
        }
        // Don't pick the current element
        helper(ind + 1, ds, target, candidates, n , res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_set<int> mySet;
        for(int candidate : candidates){
            mySet.insert(candidate);
        }
        vector<int> uniqueCandidates;
        for(auto it : mySet){
            uniqueCandidates.push_back(it);
        }
        vector<vector<int>> res;
        vector<int> ds;
        int n = uniqueCandidates.size();
        helper(0, ds, target, uniqueCandidates, n , res);
        return res;
    }
};


*/


// ------------------------------------------------------------------------------------------------------------------------------------ // 



// try 3 : worked but produced a TLE due to very high TC
// c++ does not allow hashing sets of vectors hence set used instead
// TC : O ( (2^t) * k * log(N)) , set insertions are O(logN) expensive

// try3
class Solution {
public:
void helper(int ind, vector<int>& ds, int sum, vector<int>& candidates, int n, set<vector<int>>& res) {
        if (sum == 0) {
            res.insert(ds);
            return;
        }
        if (ind == n) return;

        // Pick the current element if it doesn't exceed the remaining sum
        if (candidates[ind] <= sum) {
            ds.push_back(candidates[ind]);
            helper(ind+1, ds, sum - candidates[ind], candidates, n , res); // Reuse
            ds.pop_back();
        }
        // Don't pick the current element
        helper(ind + 1, ds, sum, candidates, n , res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> resSet;
        vector<int> ds;
        sort(candidates.begin() , candidates.end());
        int n = candidates.size();
        helper(0, ds, target, candidates, n , resSet);
        for(auto it : resSet){
            res.push_back(it);
        }
        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's solution
// 	•	n = number of elements in candidates
// •	k = average size of each combination
// •	2^n = potential number of subsets
// TC : O(2^n * k)
// SC : O(k) + O(2^n * k)
//  |=>  [stack]+[output DS]

class Solution {
public:
void helper(int ind, vector<int>& ds, int target, vector<int>& candidates, int n, vector<vector<int>>& res) {
    
    // base case

        if (target == 0) {
            res.push_back(ds);
            return;
        }

        // if (ind == n) return; // optional safety check

        // looping from i=ind to n-1
        for(int i=ind ; i<n ; i++){

            // check for repeated elements in the data structure so as to remove redundant combinations
            if(i>ind && candidates[i]==candidates[i-1]){continue;} // inherently handles the out of bounds edge case when i-1<0

            // break when target exceeds (target<0)
            if(candidates[i]>target){break;}

            // add to data sructure
           ds.push_back(candidates[i]);

            // recursive;y call for the next indices
            helper(i+1 , ds , target-candidates[i] , candidates , n , res) ;

            // backtrack to the previos node
            ds.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> ds;
        int n = candidates.size();
        sort(candidates.begin() , candidates.end());

        helper(0, ds, target, candidates, n , res);

        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 