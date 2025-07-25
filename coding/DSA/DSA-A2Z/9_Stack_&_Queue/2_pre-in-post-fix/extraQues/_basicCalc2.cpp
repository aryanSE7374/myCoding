#include<bits/stdc++.h>
using namespace std;


// try1

// https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int precedence(char c) {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string res;
        for (char c : s) {
            if(c==' '){continue;} 
            else if(isdigit(c)) res += c;
            // if operator
            else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    res += st.top(); st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            res += st.top(); st.pop();
        }
        return res;
    }

    int evalHelper(int op1 , int op2 , char optr){
        switch (optr)
        {
        case '+':
            return op2 + op1;
        case '-':
            return op2 - op1;
        case '*':
            return op2 * op1;
        case '/':
            return op2 / op1;
        default:
            return 0;
        }
    }

    int evalRPN(string tokens) {
        stack<int> st;
        for(char token : tokens){
            if((token == '+' || token == '-' || token == '*' || token == '/')){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(evalHelper(op1 , op2 , token));
            }
            else{
                st.push((token-'0'));
            }
        }
        return st.top();
    }

    int calculate(string s) {
        return evalRPN(infixToPostfix(s));
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


// my approach fixed by chatGPT

class Solution {
public:
    int precedence(char c) {
        if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else return -1;
    }

    // Convert infix string to postfix (RPN) string with space-separated tokens
    string infixToPostfix(const string& s) {
        stack<char> st;
        string res;
        int i = 0;
        while (i < s.size()) {
            char c = s[i];

            if (c == ' ') {
                i++;
                continue;
            }

            if (isdigit(c)) {
                string number;
                while (i < s.size() && isdigit(s[i])) {
                    number += s[i++];
                }
                res += number + " ";
                continue; // Don't increment i again here
            }

            // Operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.push(c);
            i++;
        }

        while (!st.empty()) {
            res += st.top();
            res += " ";
            st.pop();
        }

        return res;
    }

    int evalHelper(int op1, int op2, char optr) {
        switch (optr) {
            case '+': return op2 + op1;
            case '-': return op2 - op1;
            case '*': return op2 * op1;
            case '/': return op2 / op1;
            default: return 0;
        }
    }

    int evalRPN(const string& tokens) {
        stack<int> st;
        stringstream ss(tokens);
        string token;

        while (ss >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                st.push(evalHelper(op1, op2, token[0]));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }

    int calculate(string s) {
        string postfix = infixToPostfix(s);
        return evalRPN(postfix);
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better approach using stack :  O(N) |  O(N)
// very complex solution , diificult to be understood; consider optimal solution

int calculate(string s) {
    stack<int> st;
    int currNum = 0;
    char lastSign = '+';
    
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        
        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if (lastSign == '+') st.push(currNum);
            else if (lastSign == '-') st.push(-currNum);
            else if (lastSign == '*') {
                int val = st.top(); st.pop();
                st.push(val * currNum);
            }
            else if (lastSign == '/') {
                int val = st.top(); st.pop();
                st.push(val / currNum);
            }

            lastSign = c;
            currNum = 0;
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimal solution O(N) |  O(1)

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int cur = 0, prev = 0, res = 0;
        char cur_operation = '+';

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
            }

            // If the character is an operator or we're at the end of the string
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (cur_operation == '+') {
                    res += cur;
                    prev = cur;
                }
                else if (cur_operation == '-') {
                    res -= cur;
                    prev = -cur;
                }
                else if (cur_operation == '*') {
                    res -= prev;
                    res += prev * cur;
                    prev = prev * cur;
                }
                else if (cur_operation == '/') {
                    res -= prev;
                    res += prev / cur;
                    prev = prev / cur;
                }
                cur_operation = c;
                cur = 0;
            }
        }

        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


// aniket's solution

class Solution {
public:
int pref(char ch){
if(ch=='+' || ch=='-'){
return 1;
}

return 2;
}

int solve(int val1, int val2, int ch){
if(ch=='+'){
return val1+val2;
}

if(ch=='-'){
return val1-val2;
}

if(ch=='/'){
return val1/val2;
}

return val1*val2;
}
   
    int calculate(string s) {

    stack<int> st1;
    stack<char> st2;
    int prev=0;

    for(int i=0; i<s.size(); i++){
    
    if(s[i]>=48 && s[i]<=57){
    if(prev>0){
    int num=st1.top()*10+(s[i]-48);
    st1.pop();
    st1.push(num);
    prev++;
    continue;
    }

    else{
    st1.push(s[i]-48);
    prev++;
    continue;
    }
    }

    if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
    prev=0;
    if(st2.size()==0 || pref(s[i])>pref(st2.top())){
    st2.push(s[i]);
    continue;
    }

    else{
    while(st2.size()>0 && pref(s[i])<=pref(st2.top())){
    int val2=st1.top();
    st1.pop();
    int val1=st1.top();
    st1.pop();
    char op=st2.top();
    st2.pop();

    int ans=solve(val1,val2,op);
    st1.push(ans);
    }
    st2.push(s[i]);
    continue;
    }
    }
    }
    

    while(st2.size()>0){
    
    int val2=st1.top();
    st1.pop();
    int val1=st1.top();
    st1.pop();
    int op=st2.top();
    st2.pop();

    int ans=solve(val1,val2,op);
    st1.push(ans);

    }

    return st1.top();
        
    }
};