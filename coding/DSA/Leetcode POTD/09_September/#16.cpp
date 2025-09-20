#include<bits/stdc++.h>
using namespace std;


// try 1
class Solution {
public:
    int GCD(int a , int b){
        if(b == 0) return a;
        return GCD(b , a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int curr = nums[0];
        for(int i=1 ; i<n ; i++){
            int gcd = GCD(curr , nums[i]);
            if(gcd>1) curr = curr*nums[i]/gcd;
            else{
                res.push_back(curr);
                curr = nums[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};


// using stack try 1

class Solution {
public:
    int GCD(int a , int b){
        if(b == 0) return a;
        return GCD(b , a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        st.push(nums[0]);
        for(int i=1 ; i<n ; i++){
            int curr = st.top();
            int gcd = GCD(curr , nums[i]);
            if(gcd>1){
                st.pop();
                st.push(curr*(nums[i]/gcd));
            }
            else{
                st.push(nums[i]);
            }
        }

        int size = st.size()-1;
        vector<int> res(size+1);

        while(!st.empty()){
            res[size--] = st.top();
            st.pop();
        }

        return res;
    }
};

// using stack try 2 : accepted but redundant code

class Solution {
public:
    int GCD(int a , int b){
        if(b == 0) return a;
        return GCD(b , a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();
        st.push(nums[0]);
        for(int i=1 ; i<n ; i++){
            int gcd = GCD(st.top() , nums[i]);
            if(gcd>1){
                long long merged = (1LL*st.top()*nums[i])/gcd;
                st.pop();
                st.push(merged);

                long long temp = st.top();
                st.pop();

                if(st.empty()){
                    st.push(temp);
                    continue;
                }
                int top = st.top();
                st.push(temp);
                gcd = GCD(temp , top);
                while(gcd>1){
                    st.pop();
                    st.pop();
                    long long merged2 = (1LL*temp*top)/gcd;
                    st.push(merged2);

                    temp = st.top();
                    st.pop();

                    if(st.empty()){
                        st.push(temp); 
                        break;
                    }

                    top = st.top();
                    st.push(temp);
                    gcd = GCD(temp , top);
                }
            }
            else{
                st.push(nums[i]);
            }
        }

        int size = st.size()-1;
        vector<int> res(size+1);

        while(!st.empty()){
            res[size--] = st.top();
            st.pop();
        }

        return res;
    }
};



// chatGPT clean and optimal code : 


class Solution {
public:
    int GCD(int a , int b){
        if(b == 0) return a;
        return GCD(b , a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;   // use long long to prevent overflow
        for (int num : nums) {
            long long curr = num;
            while (!st.empty()) {
                long long gcd = GCD(st.top(), curr);
                if (gcd == 1) break;
                curr = (st.top() * curr) / gcd;  // merge
                st.pop();
            }
            st.push(curr);
        }

        int n = st.size();
        vector<int> res(n);
        for (int i = n-1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};


