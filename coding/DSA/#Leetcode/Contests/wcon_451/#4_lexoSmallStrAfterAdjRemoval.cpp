#include<bits/stdc++.h>
using namespace std;


// not solved

// sub code 1

class Solution {
public:
    bool isConsecutive(char c1, char c2) {
        return abs(c1 - c2) == 1 || abs(c1 - c2) == 25;
    }

    string resultingString(string s) {
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && isConsecutive(stack.back(), c)) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }

        }
        return string(stack.begin(), stack.end());
    }
};



// sub code 2  : better
class Solution {
public:
    bool isConsecutive(char c1, char c2) {
        return abs(c1 - c2) == 1 || abs(c1 - c2) == 25;
    }

    string resultingString(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && isConsecutive(stack.back(), c)) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }
};

// ques 4 
class Solution {
public:
    bool isConsecutive(char c1, char c2) {
        return abs(c1 - c2) == 1 || abs(c1 - c2) == 25;
    }

    string resultingString(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && isConsecutive(stack.back(), c)) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack;
    }
    string lexicographicallySmallestString(string s) {
        string temp = resultingString(s);
        if(s<temp){return s;}
        else return temp;
    }
};
