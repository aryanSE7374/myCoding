#include<bits/stdc++.h>
using namespace std;


// brute force O(n^3)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mini = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    mini = min(mini, arr[k]);
                }
                total = (total + mini) % mod;
            }
        }
        return total;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better O(n^2)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            int mini = INT_MAX;
            for (int j = i; j < n; ++j) {
                mini = min(mini, arr[j]);
                total = (total + mini) % mod;
            }
        }
        return total;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimal O(N) solution

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

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);
        long long total = 0;
        long long mod = (long long)(1e9 + 7);
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (right * left % mod * arr[i]) % mod) % mod;
        }
        return total;
    }
};
// ------------------------------------------------------------------------------------------------------------------------------------ // 