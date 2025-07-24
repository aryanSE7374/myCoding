
#include<bits/stdc++.h>
using namespace std;


// GFG : https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1



/*
Approach        |   Time Complexity     |    Space Complexity   |                   Notes
----------------+-----------------------+-----------------------+----------------------------------------------------
Brute Force     |       O(n²)           |       O(n)            |      Simple but inefficient for large input
Optimal (Stack) |       O(n)            |       O(n)            |       Uses monotonic stack; best performance
----------------+-----------------------+-----------------------+----------------------------------------------------
*/

   

// brute

// Function to find the next greater element using a brute force approach
vector<int> findNGEBruteForce(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n); // Vector to store the next greater elements

    // Iterate through each element of the array
    for (int i = 0; i < n; ++i) {
        int nextGreater = -1; // Initialize nextGreater to -1 (default if no greater element is found)
        // Iterate through elements to the right of arr[i]
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                nextGreater = arr[j]; // Found a greater element
                break; // Break the inner loop as we need the *first* greater element
            }
        }
        nge[i] = nextGreater; // Store the result for arr[i]
    }
    return nge; // Return the vector of next greater elements
}

// optimal

// Function to find the next greater element using the optimal stack-based approach
vector<int> findNGE(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n); // Vector to store the next greater elements
    stack<int> st;       // Monotonic stack to keep track of elements

    // Iterate from right to left (from n-1 down to 0)
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack that are less than or equal to the current element
        // These elements cannot be the NGE for arr[i] or any elements to its left
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If the stack is empty, it means no greater element exists to the right
        if (st.empty()) {
            nge[i] = -1;
        } else {
            // Otherwise, the top of the stack is the next greater element
            nge[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }
    return nge; // Return the vector of next greater elements
}