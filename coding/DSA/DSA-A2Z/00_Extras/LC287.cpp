#include<bits/stdc++.h>
using namespace std;


// LC 287 : https://leetcode.com/problems/find-the-duplicate-number/

// my sol 1
// TC : O( (N * logN) + N ) , SC : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i=1 ; i<n ; i++){
            if(nums[i]==nums[i-1]){return nums[i];}
        }
        return 0; // dummy return
    }
};

// sol2 map frequency : O(N) , O(N)


// Optimal – Method 1: Floyd’s Cycle Detection (Tortoise & Hare)

class Solution{
public: 
    // TC: O(n), SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entrance to cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

};


// Optimal - Method 2: Binary Search on Value

class Solution
{
public:
    // TC: O(n log n), SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) ++count;
            }
            if (count > mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }  
};

