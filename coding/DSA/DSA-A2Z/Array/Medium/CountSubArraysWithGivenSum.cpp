#include<bits/stdc++.h>
using namespace std;

// brute : O(N^3)

// better : O(n^2)

// loop(i=o to n-1){
//      loop(j=i to n-1){
//          sum+= arr[j];if(sum==k){cnt++}
//      }

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}


// using map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> prefix_sum;
        int count = 0;
        int sum = 0;
        prefix_sum[sum]++; // important edge case
        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];
            if(prefix_sum.find(sum-k)!=prefix_sum.end()){
                count+=prefix_sum[sum-k];
            }
            prefix_sum[sum]++; // this inc should be done after the condition check to hadnle k=0 case
        }
        return count;
    }
};

// 

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> prefixSumCount;
//         int currentSum = 0;
//         int count = 0;

//         // Initialize with prefix sum 0 to handle subarrays starting from the beginning
//         prefixSumCount[0] = 1;

//         for (int num : nums) {
//             currentSum += num;

//             // Check if there is a prefix sum that, when subtracted, equals k
//             if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
//                 count += prefixSumCount[currentSum - k];
//             }

//             // Update the count of the current prefix sum in the map
//             prefixSumCount[currentSum]++;
//         }

//         return count;
//     }
// };