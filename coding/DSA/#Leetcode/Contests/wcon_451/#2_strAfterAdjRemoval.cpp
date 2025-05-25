#include<bits/stdc++.h>
using namespace std;


// my try 1

class Solution {
public:
    bool isConsecutive(char c1  ,char c2){
        return ((c1-c2==1) || (c2-c1==1) || (c1-c2==25) || (c2-c1==25));
    }
    string resultingString(string s) {
        string res = "";
        int n = s.size();
        int i = 0;
        for (; i < n-1; i++)
        {
            if(isConsecutive(s[i] , s[i+1])){i++;}
            else{
                res+=s[i];
            }
        }
        if(i==n-1){res+=s[i];}
        return res;
    }
};

// gpt sol1

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

