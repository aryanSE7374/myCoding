#include<bits/stdc++.h>
using namespace std;

// sol 1 : map based O(N) , O(N)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int , int> prefix_sum;
            int count = 0;
            int sum = 0;
            prefix_sum[sum]++; // important edge case
            for(int i=0 ; i<nums.size() ; i++){
                sum+=nums[i];
                if(prefix_sum.find(sum-goal)!=prefix_sum.end()){
                    count+=prefix_sum[sum-goal];
                }
                prefix_sum[sum]++; // this inc should be done after the condition check to hadnle goal=0 case
            }
            return count;
        }
};



// sol2 : striver's optimal sol
// re-frame the problem such that u r finding number of subarrays having sum<=goal
// and hence return func(goal)-func(goal-1)
// TC : O(N)
// SC : O(1)


class Solution {
public:
    int subarrayslessThanEqualWithSum(vector<int>& nums, int goal){
        if(goal<0){return 0;}//edge case to handle goal=0 => goal-1<0
        int l=0 , r=0 , sum = 0 , count = 0;
        int n = nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-= nums[l++];
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrayslessThanEqualWithSum(nums , goal) - subarrayslessThanEqualWithSum(nums,goal-1);
    }
};




// LC sol1 : same as above 2 pass sol
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
private:
    // Helper function to count the number of subarrays with sum at most the given goal
    int slidingWindowAtMost(vector<int> &nums, int goal){
        int start = 0, currentSum = 0, totalCount = 0; 
        
        // Iterate through the array using a sliding window approach
        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];
            
            // Adjust the window by moving the start pointer to the right
            // until the sum becomes less than or equal to the goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start++];
            }

            // Update the total count by adding the length of the current subarray
            totalCount += end - start + 1;
        }
        return totalCount;
    }
};



//LC sol 2 : LC editorial's mpst optimal one pass sol

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;
        
        // Loop through the array using end pointer
        for (int end = 0; end < nums.size(); ++end) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                currentSum -= nums[start];
                start += 1;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        
        return totalCount;
    }
};

