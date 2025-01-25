#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!mpp[nums[i]]){mpp[nums[i]]++;}
            else{return true;}
        }
        return false;
        
    }
};