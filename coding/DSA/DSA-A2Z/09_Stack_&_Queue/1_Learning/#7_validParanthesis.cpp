#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/description/


// my try 1

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1){return false;}
        stack<int> st;
        for(char c : s){
            if(c=='(' || c=='{' || c=='[' ){st.push(c);}
            else if(st.empty()){return false;}
            else if(c==')' && st.top()=='('){st.pop();}
            else if(c=='}' && st.top()=='{'){st.pop();}
            else if(c==']'&& st.top()=='['){st.pop();}
            else{return false;}
        }
        return st.empty();
        // return st.empty() ? true : false;
        // if(st.empty()) return true;
        // return false;
    }
};


// chatGPT clean sol

// Time Complexity:
// O(N) — traverse the string once.

// Space Complexity:
// O(N) in the worst case (all opening brackets).

bool isValid(string s) {
    if(s.size() % 2 == 1) return false;

    stack<int> st;
    for(char c : s){
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else {
            if(st.empty()) return false;
            if((c==')' && st.top()=='(') || 
               (c=='}' && st.top()=='{') || 
               (c==']' && st.top()=='[')) {
                st.pop();
            } else return false;
        }
    }
    return st.empty();
}



