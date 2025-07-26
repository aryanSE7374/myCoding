#include<bits/stdc++.h>
using namespace std;






//  Brute Force: O(n^3)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mn = INT_MAX, mx = INT_MIN;
                for (int k = i; k <= j; ++k) {
                    mn = min(mn, nums[k]);
                    mx = max(mx, nums[k]);
                }
                total += (mx - mn);
            }
        }
        return total;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

//  Better: O(n^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int mn = nums[i], mx = nums[i];
            for (int j = i; j < n; ++j) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                total += (mx - mn);
            }
        }
        return total;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


//  Optimal: O(n)
// Using approach: Total = sum of subarray maximums - sum of subarray minimums

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumOfSubarrayMaximums(nums);
        long long minSum = sumOfSubarrayMinimums(nums);
        return maxSum - minSum;
    }

private:
    // Next Smaller Element
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    // Previous Smaller or Equal Element
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    // Next Greater Element
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    // Previous Greater or Equal Element
    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    long long sumOfSubarrayMinimums(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        long long total = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }

    long long sumOfSubarrayMaximums(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGEE(arr);
        long long total = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }
};



// ------------------------------------------------------------------------------------------------------------------------------------ // 

