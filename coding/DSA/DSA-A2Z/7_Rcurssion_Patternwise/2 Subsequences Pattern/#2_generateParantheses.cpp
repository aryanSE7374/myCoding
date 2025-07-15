#include<bits/stdc++.h>
using namespace std;

// this should be done after #3  :the power set problem 

// generate parantheses problem

// brute solution

// Approach:
// 	•	Generate all possible strings of length 2n consisting of only '(' and ')'.
// 	•	For each string, check if it is valid (balanced).

// Time Complexity:
// 	•	Generating all combinations: O(2^{2n})
// 	•	Checking each combination: O(n)
// 	•	Final Time: O(n * 2^{2n})

// Space Complexity:
// 	•	Recursion stack: O(2n)
// 	•	Storing valid strings: depends on output, O(2^n * n)

class Solution {
public:
    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }

    void generate(string current, int n, vector<string>& res) {
        if (current.size() == 2 * n) {
            if (isValid(current)) res.push_back(current);
            return;
        }
        generate(current + '(', n, res);
        generate(current + ')', n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", n, res);
        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better/optimal solution
// Time Complexity:
// 	We only generate valid combinations, and the number of valid combinations is Catalan number:
// overall : O(4^n / sqrt{n}) =̂~ O(4^n * n^(-1/2))
// Space Complexity:
//      Output space + recursion: O(n) per recursion stack call.


class Solution {
public:
    void backtrack(int open, int close, int n, string current, vector<string>& res) {
        if (current.size() == 2 * n) {
            res.push_back(current);
            return;
        }

        if (open < n)
            backtrack(open + 1, close, n, current + '(', res);

        if (close < open)
            backtrack(open, close + 1, n, current + ')', res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 


// Memory-Optimized Version

// Use a char[] to reduce memory allocations from string concatenation.


class Solution {
public:
    void backtrack(int open, int close, int n, char* str, int idx, vector<string>& res) {
        if (idx == 2 * n) {
            res.push_back(string(str, idx));
            return;
        }

        if (open < n) {
            str[idx] = '(';
            backtrack(open + 1, close, n, str, idx + 1, res);
        }

        if (close < open) {
            str[idx] = ')';
            backtrack(open, close + 1, n, str, idx + 1, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        char str[2 * n];
        backtrack(0, 0, n, str, 0, res);
        return res;
    }
};



// ------------------------------------------------------------------------------------------------------------------------------------ // 