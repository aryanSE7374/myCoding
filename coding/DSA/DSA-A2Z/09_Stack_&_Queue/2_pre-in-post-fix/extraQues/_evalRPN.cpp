#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// my try 1

int evalHelper(int op1 , int op2 , string optr){
    char op = optr[0];
    switch (op)
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

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if((token == "+" || token == "-" || token == "*" || token == "/")){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(evalHelper(op1 , op2 , token));
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};



// chat GPT sol

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // integer division
            } else {
                st.push(stoi(token));  // convert number string to int and push
            }
        }

        return st.top();
    }
};

// int main(){
//     cout<<'9'-'0'<<endl;
//     return 0;
// }
