#include<bits/stdc++.h>
using namespace std;

// brute

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int , int> frequency;
        vector<int> ans;
        for(int num : nums){
            frequency[num]++;
        }
        for(auto it : frequency){
            if(it.second == 1){ans.push_back(it.first);}
        }
        return ans;
    }
};


// optimal : using the concept of buckets

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        // vector<int> ans;
        // int xorr = 0;
        long xorr = 0;

        for(int num : nums){
            xorr ^= num;
        }

        int rightMost = ( xorr & (xorr-1) ) ^ xorr ;
        // int rightMost = ( xorr & ~(xorr-1) ) ;

        int b1=0 , b2=0 ;

        for(int num : nums){
            if(rightMost & num){
                b1 ^= num;
            }
            else {
                b2 ^= num;
            }
        }

        return {b1,b2};
        
    }
};