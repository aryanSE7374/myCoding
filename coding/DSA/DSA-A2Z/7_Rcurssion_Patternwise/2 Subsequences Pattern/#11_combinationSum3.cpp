#include<bits/stdc++.h>
using namespace std;


// Brute
// approach : All Subsets of 1–9
// code-style : Bitmask or recursion
// TC : O(2⁹ × k)
// SC : O(k)

// brute helper function

// Try all subsets of {1..9}, keep only those with size == k and sum == n
void generate(int i, vector<int>& ds, int sum, int k, int n, vector<vector<int>>& res) {
    if (i > 9) {
        if (ds.size() == k && sum == n) res.push_back(ds);
        return;
    }
    // pick
    ds.push_back(i);
    generate(i+1, ds, sum+i, k, n, res);
    ds.pop_back();

    // not pick
    generate(i+1, ds, sum, k, n, res);
}



// combination sum2 helper function

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
        helper(i+1 , ds , target-candidates[i] , candidates , n , res);

        // backtrack to the previos node
        ds.pop_back();

    }
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my try 1

// TC : O( C(9,k) )
// SC : O(k)


class Solution {
public:
    void helper(int ind, vector<int>& ds, int target, int k , vector<int>& candidates, int n, vector<vector<int>>& res) {
        
        // base case

        if (target == 0 && ds.size() == k) {
            res.push_back(ds);
            return;
        }

        // if (ind == n) return; // optional safety check

        // looping from i=ind to n-1
        for(int i=ind ; i<n ; i++){

            // check for repeated elements in the data structure so as to remove redundant combinations
            if(i>ind && candidates[i]==candidates[i-1]){continue;} // unnecessary here

            // break when target exceeds (target<0)
            if(candidates[i]>target){break;}

            // add to data sructure
            ds.push_back(candidates[i]);

            // recursive;y call for the next indices
            helper(i+1 , ds , target-candidates[i] , k , candidates , n , res);

            // backtrack to the previos node
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> ds;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        // int n = candidates.size();

        helper(0, ds, n , k , candidates, 9 , res);

        return res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my try 2 :- better

// TC : O( C(9,k) )
// SC : O(k)

class Solution {
public:
    void helper(int ind, vector<int>& ds, int target, int k , vector<int>& candidates, int n, vector<vector<int>>& res) {
        
        // base case

        if (target == 0 && ds.size() == k) {
            res.push_back(ds);
            return;
        }

        // if (ind == n) return; // optional safety check

        // looping from i=ind to n-1
        for(int i=ind ; i<n ; i++){

            // check for repeated elements in the data structure so as to remove redundant combinations

            // break when target exceeds (target<0)
            if(candidates[i]>target || k==0){break;}

            // add to data sructure
            ds.push_back(candidates[i]);

            // recursive;y call for the next indices
            helper(i+1 , ds , target-candidates[i] , k-1 , candidates , n , res);

            // backtrack to the previos node
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> ds;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        // int n = candidates.size();

        helper(0, ds, n , k , candidates, 9 , res);

        return res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// my try 3 :- most Optimal Solution

// TC : O( C(9,k) )
// SC : O(k)

class Solution {
public:
    void helper(int ind, vector<int>& ds, int target, int k , vector<int>& candidates, int n, vector<vector<int>>& res) {
        
        // base case

        if (target == 0 && k == 0) {
            res.push_back(ds);
            return;
        }

        // if (ind == n) return; // optional safety check

        // looping from i=ind to n-1
        for(int i=ind ; i<n ; i++){

            // check for repeated elements in the data structure so as to remove redundant combinations

            // break when target exceeds (target<0)
            if(candidates[i]>target){break;}

            // add to data sructure
            ds.push_back(candidates[i]);

            // recursive;y call for the next indices
            helper(i+1 , ds , target-candidates[i] , k-1 , candidates , n , res);

            // backtrack to the previos node
            ds.pop_back();

        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> ds;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        // int n = candidates.size();

        helper(0, ds, n , k , candidates, 9 , res);

        return res;
    }
};


