#include<bits/stdc++.h>
using namespace std;


// brute
class Solution{
public: 
    int myAtoi(string s) {
        string number = "";
        bool signFlag = true;
        for (char ch : s) {
            if (isspace(ch) && number.empty()) continue;
            if ((ch == '-' || ch == '+') && number.empty()) {
                signFlag = (ch == '+');
                continue;
            }
            if (isdigit(ch)) {
                number += ch;
            } else {
                break;
            }
        }
        if (number.empty()) return 0;
        // uses another biult in method stoll , which is not optimal
        long long result = stoll(number) * (signFlag ? 1 : -1);
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return result;
    }
};




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
// my solution

// TC : O(n)
// SC : O(1)
// Comparable to better solution; can be streamlined further.

class Solution {
public:
    int myAtoi(string s) {
        bool signFlag = true; //sign : true => +ve , false => -ve (set to +ve intially)
        bool encountered = false; //character other than whitespace encountered
        int res = 0; // initial result
        for(auto &ch : s){
            int code = (int)ch; //ASCII code
            if(!encountered){ //if not encountered any character other than whitespace
                if(ch==' '){continue;} //ignoring
                else{ //firsst char other tha whitespace encountered
                    encountered = true; // flag changed
                    if((ch=='-'||ch=='+')){ //checking for signed characters
                        if(ch=='-'){signFlag = false; } //changing flag only for negative
                        continue; //ignore rest logic
                    }
                }
            }
            
            if((48<=code)&&(code<=57)){ //if decimal digit i.e. 0 to 9
                if(signFlag){ // if +ve
                    if((res>INT_MAX/10)||((res==INT_MAX/10)&&((code-48)>7))){ //checking for range
                        return INT_MAX; // rounding off to greatest +ve integer
                    }
                    else{
                        res = res*10 + (code-48); // (code-48) gives decimal integer corresponding to ASCII code
                    }
                }
                else{ // if !signFlag => negative
                    if((res<INT_MIN/10)||((res==INT_MIN/10)&&((code-48)>8))){ //checking for range
                        return INT_MIN; // rounding off to greatest -ve integer
                    }
                    else{
                        res = res*10 - (code-48); // - for negative integers
                    }
                }
            }

            else{
                break; // if any other char (other than decimal encountered again, then break)
            }
        }
        return res; //returning result
    }
};


// my solution refined version by chatGPT

class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0;
        int n = s.length();
        bool isNegative = false;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // Step 2: Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            isNegative = (s[i] == '-');
            ++i;
        }

        // Step 3: Process numeric characters
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (res > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }

            res = res * 10 + digit;
            ++i;
        }

        return isNegative ? -res : res;
    }
};