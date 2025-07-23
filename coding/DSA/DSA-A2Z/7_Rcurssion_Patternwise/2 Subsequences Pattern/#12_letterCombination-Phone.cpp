#include<bits/stdc++.h>
using namespace std;


//  my try 1  : wasted

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};

        // brute sol will be a hell of loops...
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


// chatGPT solution

class Solution {
public:
    vector<string> res;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int idx, string current) {
        if (idx == digits.length()) {
            res.push_back(current);
            return;
        }

        string letters = mapping[digits[idx] - '0'];
        for (char c : letters) {
            backtrack(digits, idx + 1, current + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(digits, 0, "");
        return res;
    }
};