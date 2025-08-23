#include<bits/stdc++.h>
using namespace std;


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

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my solution - optimal

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // m x n matrix
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> currHeights(n , 0);
        int maxArea= 0;
        for(int i=0 ; i<m ; i++){
            // processing the Heights array 
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == '1'){currHeights[j]++;}
                else{
                    currHeights[j] = 0;
                }
            }
            maxArea = max( maxArea , largestRectangleArea(currHeights) );
        }
        return maxArea;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver sol : used a mxn auxilary currHeights vector of vectors of int to store the psum[i][j]

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// chatGPT bettter sol ;- practically it is the faster one

// BETTER APPROACH (DP with Left, Right, and Height Arrays)

// Time: O(m × n)
// Space: O(n) for each of left, right, height arrays

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            int curr_left = 0, curr_right = n;

            // update height
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            // update left
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], curr_left);
                else {
                    left[j] = 0;
                    curr_left = j + 1;
                }
            }

            // update right
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], curr_right);
                else {
                    right[j] = n;
                    curr_right = j;
                }
            }

            // compute area
            for (int j = 0; j < n; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


// chatGPT optimal sol
// TC : O(mxn)
// SC : O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Sentinel to flush the stack

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < n; ++j) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 