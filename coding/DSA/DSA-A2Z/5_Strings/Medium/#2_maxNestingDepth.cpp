#include<bits/stdc++.h>
using namespace std;

// my brute try 1 : using stack 
// there's no need to use stack either

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0;
        int count = 0;
        for(char c : s){
            if(c=='('){
                st.push('(');
                count++;
            }
            else if(c==')'){
                st.pop();
                count--;
            }
            maxi = max(maxi , count);
        }
        return maxi;
    }
};

// my optimal try 1 : without using stack

/*
Time and Space Complexity:
•	Time Complexity: O(n), where n is the length of the string (single pass through the string).
•	Space Complexity: O(1), as we only use a few variables.
*/

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count = 0;
        for(char c : s){
            if(c=='('){
                count++;
                maxi = max(maxi , count); // there's no need to check explicitly outside the if block as
                // it needs to be changed only if '(' encountered
            }
            else if(c==')'){
                count--;
            }
        }
        return maxi;
    }
};