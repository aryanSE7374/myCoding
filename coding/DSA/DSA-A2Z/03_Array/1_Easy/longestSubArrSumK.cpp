#include<bits/stdc++.h>
using namespace std;

// if array has only positives, then sliding window approach will also work : 

class Solution{
public:
    // Function to find the length of longest subarray having sum k
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        
        // To store the maximum length of the subarray
        int maxLen = 0;
        
        // Pointers to mark the start and end of window
        int l = 0, r = 0;
        
        // To store the sum of elements in the window
        int sum = nums[0];
        
        // Traverse all the elements
        while(r < n) {
            
            // If the sum exceeds K, shrink the window
            while(l <= r && sum > k) {
                sum -= nums[l];
                l++;
            }
            
            // store the maximum length
            if(sum == k) {
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
            if(r < n) sum += nums[r];
        }
        
        return maxLen;
    }
};

// --------------------------------------------------------------------------- //

// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray 
//  where the sum of  its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int , int> preSumMap;
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum+=arr[i];
            if(sum==k){
                maxLen = max(maxLen , i+1);
            }
            // int rem = sum-k;
            if(preSumMap.find(sum-k)!=preSumMap.end()){
                maxLen = max(maxLen , i-preSumMap[sum-k]);
            }
            // preSumMap[sum] = i;
            if(preSumMap.find(sum)==preSumMap.end()){ // if sum not found, then only insert, 
            // repeated sum values will not be overwritten with greater indices
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};