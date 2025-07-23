#include<bits/stdc++.h>
using namespace std;

// .../7_Rcurssion_Patternwise/2 Subsequences Pattern/#3_generatePowerSet.cpp

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


// b