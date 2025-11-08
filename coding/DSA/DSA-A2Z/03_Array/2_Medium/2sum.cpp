#include<bits/stdc++.h>
using namespace std;


// optimal map based approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int , int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp.insert({nums[i],i});
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end()){
                res.push_back(i);
                res.push_back(mpp[target-nums[i]]);
                return res;
            }
        }
        return res;
    }
};

// 2 pointer approach 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = arr[l].first + arr[r].first;
            if (sum == target) {
                return {arr[l].second, arr[r].second};
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {};
    }
};