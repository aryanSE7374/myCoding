#include <iostream>
using namespace std;



// chatGPT solution : brute
// TC : O(n+k) , SC : O(n) ; k=no. of primitives (extraction overhead)

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        string primitive = "";
        for (char c : s) {
            primitive += c;
            if (c == '(') balance++;
            else balance--;
            if (balance == 0) { // Found a primitive
                result += primitive.substr(1, primitive.size() - 2); // Remove outermost
                primitive = "";
            }
        }
        return result;
    }
};


// my solution : algo taken from yt video (using stack) : (large but easy algo)
// •	Time: O(n), as we traverse the string once.
// •	Space: O(n), for the stack.
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            // check empty -> if yes then push and ignore 
            if (st.empty())
            {
                // assuming only valid parantheses input
                st.push('(');
                continue;
            }
            // if '(' the push else if ')' then pop
            if (s[i]=='(')
            {
                st.push('(');
            }
            else{ // s[i]==')'
                st.pop();
            }
            // if stack has elements then only add to ans else it is the outer parantheses , ignore it
            if(!st.empty()){ans+=s[i];}
        }
        
    }
};

// chatGPT stack implementation : more concise and clear (complex algo)
// •	Time: O(n), as we traverse the string once.
// •	Space: O(n), for the stack.
class Solution { 
public:
    string removeOuterParentheses(string s) {
        string result = "";
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) result += c; // Not the outermost '('
                st.push(c);
            } else { // c == ')'
                st.pop();
                if (!st.empty()) result += c; // Not the outermost ')'
            }
        }
        return result;
    }
};



// chatGPT solution : Optimal Approach - Using a Counter Without Stack

// •	Time: O(n), single traversal of the string.
// •	Space: O(1), minimal auxiliary space.

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) result += c; // Not the outermost '('
                balance++;
            } else { // c == ')'
                balance--;
                if (balance > 0) result += c; // Not the outermost ')'
            }
        }
        return result;
    }
};

