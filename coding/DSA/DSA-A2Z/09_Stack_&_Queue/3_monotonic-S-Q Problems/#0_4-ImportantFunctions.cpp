#include<bits/stdc++.h>
using namespace std;

// NOTE :  they will return array of indices , not the elements or values

class ImportantFunctions {
public:
    // Next Smaller Element (NSE)
    static vector<int> findNSE(const vector<int>& arr) {
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

    // Previous Smaller Element or Equal (PSE)
    static vector<int> findPSE(const vector<int>& arr) {
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

    // Next Greater Element (NGE)
    static vector<int> findNGE(const vector<int>& arr) {
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

    // Previous Greater Element or Equal (PGE)
    static vector<int> findPGE(const vector<int>& arr) {
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
};