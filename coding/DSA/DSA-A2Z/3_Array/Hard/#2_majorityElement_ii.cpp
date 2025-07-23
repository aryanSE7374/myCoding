#include <bits/stdc++.h>
using namespace std;


// O(N) space solution

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> vec;
            int n = nums.size();
            unordered_map<int ,int> mpp;
            for(auto it : nums){
                mpp[it]++;
            }
            for(auto it : mpp){
                if(it.second>n/3){vec.push_back(it.first);}
            }
            return vec;
        }
    };