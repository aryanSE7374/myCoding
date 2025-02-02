#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> prefix_sum;
        int count = 0;
        int sum = 0;
        prefix_sum[sum]++;
        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];
            if(prefix_sum.find(sum-k)!=prefix_sum.end()){
                count+=prefix_sum[sum-k];
            }
            prefix_sum[sum]++;
        }
        return count;
    }
};



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