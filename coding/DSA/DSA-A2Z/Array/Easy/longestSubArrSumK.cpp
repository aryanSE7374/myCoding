
#include<bits/stdc++.h>
using namespace std;


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