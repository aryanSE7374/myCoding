#include<bits/stdc++.h>
using namespace std;


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