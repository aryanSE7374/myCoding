#include<bits/stdc++.h>
using namespace std;


// my try 1
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        if(n==k){return "0";}
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k-->0){st.pop();}
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin() , res.end());
        int i=0 ;
        while(res[i]=='0'){
            i++;
        }
        // i = no. of trailing zeroes in the res string
        res.erase(res.begin() , res.begin()+i);
        return res.empty() ? "0" : res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// striver's solution
// Time: O(n)
// Space: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        if(n==k){return "0";}
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k-->0){st.pop();}

        if (st.empty()) return "0";

        string res = "";

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        while(res.size()!=0 && res.back() == '0'){res.pop_back();}
        
        reverse(res.begin() , res.end());

        return res.empty() ? "0" : res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// greedy + string slicing solution
// Time: O(k × n)
// Space: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        while (k--) {
            int i = 0;
            while (i + 1 < num.size() && num[i] <= num[i + 1]) {
                i++;
            }
            num.erase(i, 1);
        }
        
        // Remove leading zeroes
        int i = 0;
        while (i < num.size() && num[i] == '0') i++;
        num = num.substr(i);
        
        return num.empty() ? "0" : num;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// my sol optimized by chatGPT

// Time: O(n)
// Space: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();

        if (n == k) return "0";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // Remove remaining digits from the end
        while (k-- > 0) st.pop();

        // Build the result string from the stack
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Reverse to correct order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 
// ------------------------------------------------------------------------------------------------------------------------------------ // 