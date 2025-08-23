#include<bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;
    for (char c : s) {
        if (isalnum(c)) res += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top(); st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        } else {
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

string prefixToInfix(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isalnum(s[i])) st.push(string(1, s[i]));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    return st.top();
}

string prefixToPostfix(string s) {
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (isalnum(s[i])) st.push(string(1, s[i]));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + s[i]);
        }
    }
    return st.top();
}

string postfixToPrefix(string s) {
    stack<string> st;
    for (char c : s) {
        if (isalnum(c)) st.push(string(1, c));
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push(c + op1 + op2);
        }
    }
    return st.top();
}

string postfixToInfix(string s) {
    stack<string> st;
    for (char c : s) {
        if (isalnum(c)) st.push(string(1, c));
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    int choice;
    string expr;
    cout << "Expression Conversion Menu:\n";
    cout << "1. Infix to Postfix\n";
    cout << "2. Prefix to Infix\n";
    cout << "3. Prefix to Postfix\n";
    cout << "4. Postfix to Prefix\n";
    cout << "5. Postfix to Infix\n";
    cout << "6. Infix to Prefix\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;
    cout << "Enter the expression: ";
    cin >> expr;

    switch (choice) {
        case 1: cout << "Postfix: " << infixToPostfix(expr) << endl; break;
        case 2: cout << "Infix: " << prefixToInfix(expr) << endl; break;
        case 3: cout << "Postfix: " << prefixToPostfix(expr) << endl; break;
        case 4: cout << "Prefix: " << postfixToPrefix(expr) << endl; break;
        case 5: cout << "Infix: " << postfixToInfix(expr) << endl; break;
        case 6: cout << "Prefix: " << infixToPrefix(expr) << endl; break;
        default: cout << "Invalid choice." << endl;
    }
    return 0;
}

