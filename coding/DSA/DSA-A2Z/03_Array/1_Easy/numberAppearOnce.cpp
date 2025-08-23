#include<bits/stdc++.h>
using namespace std;


// brute : two loops count appearance, return as soon as find one with single appearance
// O(n^2)


// better soln : theta(N) , O(N^2) in case of unordered map  , space : O(N/2)

// theta(NlogM) , in case of map , space : O(N/2)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mpp; // map will also work
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it  : mpp){
            if(it.second==1){
                return it.first;
            }
        }
        return -1; // to get rid of warnings
    }
};


// optimal soln : O(N) , O(1)space

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            res^=nums[i];
        }
        return res;
    }
};