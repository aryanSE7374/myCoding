#include<bits/stdc++.h>
using namespace std;


// iterative solution

// better / optimal solution

// •	Time Complexity: O(n), where n is the length of the string.
// •	Space Complexity: O(1), as no extra data structures are used.

/*
Overflow check : 
condition :- (res * 10) + digit <= INT_MAX 
negation :- (res * 10) + digit > INT_MAX  ; if this then overflow is encountered
rearange : res > (INT_MAX - digit) / 10;
*/  

class Solution{
public: 

    int myAtoi(string s) {
        int i = 0, n = s.size(), result = 0;
        bool isNegative = false;

        while (i < n && s[i] == ' ') i++;  // Ignore leading spaces
        if (i < n && (s[i] == '-' || s[i] == '+')) { 
            isNegative = (s[i] == '-');
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > (INT_MAX - digit) / 10) {  // Overflow check
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + digit;
            i++;
        }

        return isNegative ? -result : result;
    }

};


// chatGPT conversion using lambda function

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        
        // Helper function to handle recursion
        function<int(int, int, bool)> atoiHelper = [&](int idx, int result, bool isNegative) -> int {
            // Base Case 1: End of the string
            if (idx >= n || !isdigit(s[idx])) {
                return isNegative ? -result : result;
            }

            // Extract digit and check for overflow
            int digit = s[idx] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }

            // Recursive Step: Add the digit to the result and move to the next character
            return atoiHelper(idx + 1, result * 10 + digit, isNegative);
        };

        // Step 1: Ignore leading spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Handle sign
        bool isNegative = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-');
            i++;
        }

        // Step 3: Start recursion
        return atoiHelper(i, 0, isNegative);
    }
};

// without lambda function 
class Solution {
public:

    // Helper function for recursion
    int atoiHelper(int idx, int result, bool isNegative, const string& str) {
        // Base Case: End of string or non-digit character
        if (idx >= str.size() || !isdigit(str[idx])) {
            return isNegative ? -result : result;
        }

        // Extract digit and check for overflow
        int digit = str[idx] - '0';
        if (result > (INT_MAX - digit) / 10) {
            return isNegative ? INT_MIN : INT_MAX;
        }

        // Recursive Step: Add digit to result and process next character
        return atoiHelper(idx + 1, result * 10 + digit, isNegative, str);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Step 1: Ignore leading spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Handle sign
        bool isNegative = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-');
            i++;
        }

        // Step 3: Start recursion
        return atoiHelper(i, 0, isNegative, s);
    }
};