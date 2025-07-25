#include<bits/stdc++.h>
using namespace std;

// brute : 
// Time: O(N²)
// Space: O(1)

int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;

    for (int i = 1; i < n - 1; i++) {
        int left_max = 0, right_max = 0;

        for (int j = i; j >= 0; j--) {
            left_max = max(left_max, height[j]);
        }
        for (int j = i; j < n; j++) {
            right_max = max(right_max, height[j]);
        }

        water += min(left_max, right_max) - height[i];
    }

    return water;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better : Precompute left_max[] and right_max[] arrays, avoid redundant lookups.
// Time: O(N)
// Space: O(N)

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> left_max(n), right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
        left_max[i] = max(left_max[i - 1], height[i]);

    for (int i = n - 2; i >= 0; i--)
        right_max[i] = max(right_max[i + 1], height[i]);

    int water = 0;
    for (int i = 1; i < n - 1; i++) {
        water += min(left_max[i], right_max[i]) - height[i];
    }

    return water;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimal appraoch : striver & GPT : optimal 1
// Time: O(N)
// Space: O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    water += left_max - height[left];
                left++;
            } else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    water += right_max - height[right];
                right--;
            }
        }

        return water;
    }

};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// shradha khapra's solution : optimal 2
// Time: O(N)
// Space: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) { // Handle empty input
            return 0;
        }

        int ans = 0;
        int l = 0, r = n - 1; // Two pointers for left and right ends
        int lmax = 0, rmax = 0; // Maximum heights encountered from left and right

        while (l < r) {
            // Update lmax and rmax
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            // If the left maximum is smaller, we can trap water on the left side
            if (lmax < rmax) {
                ans += lmax - height[l]; // Add trapped water
                l++; // Move left pointer
            } else { // Otherwise, trap water on the right side
                ans += rmax - height[r]; // Add trapped water
                r--; // Move right pointer
            }
        }
        return ans;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// stack based solution for the interviews : O(N) , O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        stack<int> st; // stack to store indices

        for (int i = 0; i < n; ++i) {
            // While current height is greater than the top of the stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top(); // the bar where water may be trapped
                st.pop();

                if (st.empty()) {
                    break; // no left boundary
                }

                int distance = i - st.top() - 1; // width between current and stack top
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                totalWater += distance * bounded_height;
            }

            st.push(i); // push current index as potential boundary
        }

        return totalWater;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 