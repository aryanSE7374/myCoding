#include<bits/stdc++.h>
using namespace std;


// my try 1
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k==1){
            res = nums;
            return res;
        }
        int n = nums.size();
        unordered_map<int , int> freq;
        for(int i=0 ; i< k ; i++){
            freq[nums[i]]++;
        }
        for(int i=1 ; i<n-k+1 ; i++){
            
            if(freq[nums[i]]<=0){
                
            }
        }
    }
};

// brute

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1 , 0);
        for(int i=0 ; i<n-k+1 ; i++){
            int maxi = INT_MIN;
            for(int j=i ; j < i+k ; j++){
                maxi = max(maxi , nums[j]);
            }
            res[i] = maxi;
        }
        return res;
    }
};


// there's also a heap based sol


// striver's solution (same as optimal)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current element's index
            dq.push_back(i);

            // Record the max for the window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// more solutions by chatGPT

// Leetcode 239: Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:

    // ------------------- //
    // 🧨 Brute Force
    // ------------------- //
    // Time: O(n * k)
    // Space: O(1)
    vector<int> bruteMaxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= nums.size() - k; i++) {
            int maxVal = nums[i];
            for (int j = 1; j < k; j++) {
                maxVal = max(maxVal, nums[i + j]);
            }
            result.push_back(maxVal);
        }
        return result;
    }

    // ------------------- //
    // 🧪 Heap (Max Priority Queue)
    // ------------------- //
    // Time: O(n log k)
    // Space: O(k)
    vector<int> heapMaxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;  // {value, index}
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            
            // Remove elements outside the window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Window starts from index k - 1
            if (i >= k - 1) {
                result.push_back(pq.top().first);
            }
        }

        return result;
    }

    // ------------------- //
    // ⚡ Optimal (Monotonic Deque)
    // ------------------- //
    // Time: O(n)
    // Space: O(k)
    vector<int> dequeMaxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // store indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside the window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Add max of current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }

    // ------------------- //
    // Leetcode Driver
    // ------------------- //
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Uncomment the approach you want to test:

        // return bruteMaxSlidingWindow(nums, k);
        // return heapMaxSlidingWindow(nums, k);
        return dequeMaxSlidingWindow(nums, k);
    }
};

/*
===============================
📌 Final Notes:
===============================

Approach 1: Brute Force
- Simple and easy to understand.
- Inefficient for large input sizes.

Approach 2: Heap (Max Priority Queue)
- Uses max-heap to track max values.
- Each element pushed/popped once.
- Slower than optimal but clean.

Approach 3: Optimal Deque (Monotonic Queue)
- Uses deque to maintain decreasing values.
- Most efficient solution: O(n).
- Suitable for all input sizes and passes constraints easily.

✅ Recommended: Use deque-based solution in contests or interviews.
*/