/*
video : https://www.youtube.com/watch?v=zMdbdGJNlh4&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=7
article : https://www.geeksforgeeks.org/dsa/next-smaller-element/
link : https://www.naukri.com/code360/problems/next-greater-element_1112581
*/

#include<bits/stdc++.h>
using namespace std;



// strivwr's optimal solution

// Function to find the Next Smaller Element to the Left for each element in an array
vector<int> findNextSmallerElementToLeft(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    // Iterate through the array
    for (int i = 0; i < n; ++i) {
        // Pop elements greater than or equal to current
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Set NSE or -1 if stack is empty
        nse[i] = st.empty() ? -1 : st.top();

        // Push current element
        st.push(arr[i]);
    }

    return nse;
}

// code 360 practice

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    // Iterate through the array
    for (int i = n-1; i >= 0; i--) {
        // Pop elements greater than or equal to current
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Set NSE or -1 if stack is empty
        nse[i] = st.empty() ? -1 : st.top();

        // Push current element
        st.push(arr[i]);
    }

    return nse;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// GFG articles 

// brute


/* prints element and NSE pair 
for all elements of arr[] of size n */
void printNSE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " 
             << next << endl;
    }
}



// optimal using monotonic stack

// Function to find the next smaller element for each element in the array
vector<int> findNextSmallerElement(const vector<int>& arr) {
    int n = arr.size();

    // Stores the next smaller elements, initialized with -1
    vector<int> nextSmaller(n, -1);

    // Monotonic stack to keep track of indices
    stack<int> stk;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Maintain a increasing order in the stack
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            nextSmaller[stk.top()] = arr[i]; // Assign the next smaller element
            stk.pop(); // Remove processed element
        }

        // Push the current index onto the stack
        stk.push(i);
    }

    return nextSmaller;
}
