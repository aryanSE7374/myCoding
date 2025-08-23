#include<bits/stdc++.h>
using namespace std;

// my brute try from GPT

// TC : O(N)
// SC : O(N)

class Solution {
public:
    bool rotateString(string s, string goal) {
        // code here
        // string temp = s;
        // If the lengths are different, they cannot be rotations of each other
        if(s==goal){return true;}
        if (s.length() != goal.length()) {
            return false;
        }
        // Perform all rotations of `s`
        for (int i = 0; i < s.length(); i++)
        {
            // Rotate `s` by moving the first character to the end
            s = s.substr(1) + s[0];
            // Check if the rotated string matches `goal`
            if(s==goal){return true;}
        }
        return false;
    }
};


// optimal sol : GPT
// The key observation is that a string goal is a rotation of string s 
// if and only if goal is a substring of s + s. 
// This works because concatenating s with itself contains all possible rotations of s.
// TC : O(N)
// SC : O(N)
class Solution{
    public: 
        bool rotateString(string s, string goal) {
            // If lengths are different, they cannot be rotations of each other
            if (s.length() != goal.length()) {
                return false;
            }

            // Concatenate s with itself and check if goal is a substring
            string concatenated = s + s;
            return concatenated.find(goal) != string::npos;
        }
};