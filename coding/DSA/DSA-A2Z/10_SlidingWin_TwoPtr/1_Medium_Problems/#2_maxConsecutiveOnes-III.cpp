#include<bits/stdc++.h>
using namespace std;


// my try 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l=0,r=0,zeroes=0;

        while(r<n){
            if(nums[r]==0){zeroes++;}
            if(zeroes>k){
                if(nums[l]==0){zeroes--;}
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};


// striver's sol - 1

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l=0,r=0,zeroes=0;

        while(r<n){
            if(nums[r]==0){zeroes++;}
            while(zeroes>k){
                if(nums[l]==0){zeroes--;}
                l++;
            }
            if(zeroes<=k){
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

// optimization : sol-2 striver

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l=0,r=0,zeroes=0;

        while(r<n){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[l]==0){zeroes--;}
                l++;
            }
            if(zeroes<=k){
                maxLen=max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};