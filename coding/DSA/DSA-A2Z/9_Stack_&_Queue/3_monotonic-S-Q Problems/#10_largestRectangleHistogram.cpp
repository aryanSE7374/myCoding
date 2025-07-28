#include<bits/stdc++.h>
using namespace std;


// brute 
// TC : O(n^2)
// SC : O(1)

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        int left = i, right = i;

        // Expand to the left
        while (left > 0 && heights[left - 1] >= heights[i])
            left--;

        // Expand to the right
        while (right < n - 1 && heights[right + 1] >= heights[i])
            right++;

        int width = right - left + 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better 
// TC : O(N)
// SC : O(N)


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's optimal sol

/*
❗ Improvement
You could add sentinel 0 to avoid the second loop (optional)
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0 ;
        int n = heights.size();
        for(int i=0 ; i<n ; i++){
            while (!st.empty() && heights[st.top()]>heights[i])
            {
                int element = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea , element * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int element = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea , element * (nse - pse - 1));
        }
        return maxArea;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// chatGPT optimal sol

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);  // sentinel
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// Gemini's optimal sol

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        stack<int> st; // Stores indices of bars
        int maxArea = 0;

        // Iterate through all bars, and an extra iteration for processing remaining stack elements
        for (int i = 0; i <= n; ++i) {
            // currentHeight is 0 when i == n to ensure all elements in stack are processed
            int currentHeight = (i == n) ? 0 : heights[i];

            // While stack is not empty and current bar is smaller than the bar at stack top
            // This means the bar at stack top has found its Next Smaller Element (NSE)
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int poppedIndex = st.top(); // Index of the bar being popped
                st.pop(); // Remove the index from stack

                int h = heights[poppedIndex]; // Height of the popped bar

                // Calculate the Previous Smaller Element (PSE) index
                // If stack is empty, it means no PSE to the left, so PSE index is -1
                int pse = st.empty() ? -1 : st.top();

                // Calculate the width: (NSE index - PSE index - 1)
                // NSE index is 'i' (the current bar's index)
                int w = i - pse - 1;

                // Update maxArea
                maxArea = max(maxArea, h * w);
            }
            // Push current bar's index onto the stack
            st.push(i);
        }
        return maxArea;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 