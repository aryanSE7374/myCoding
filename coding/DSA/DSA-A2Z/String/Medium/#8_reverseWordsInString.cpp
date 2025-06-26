#include<bits/stdc++.h>
using namespace std;
/*
// my brute try

class Solution {
    public:
    
        string reverseString(string &s){
            int n = s.length();
            int l = 0 , h = n-1;
            while(l <= h){
                char temp = s[l];
                s[l] = s[h];
                s[h] = temp;
                l++;
                h--;
            }
            return s;
        }

        // void reverseString(string &s){
        //     int n = s.length();
        //     int l = 0 , h = n-1;
        //     while(l <= h){
        //         char temp = s[l];
        //         s[l] = s[h];
        //         s[h] = temp;
        //     }
        //     return s;
        // }


        string reverseWords(string s) {
            vector<string> vec;

            // int n = strlen(s);
            int n = s.length();
            for(int i = n-1 ; i>=0 ; i--){
                string word = "";
                while ((i>=0) && (s[i] != " "))
                {
                    i--;
                }
                
            }

        }
    };
*/



// chat GPT brute solution : limitation:-inefficient concatenation
// Time Complexity
// Traversing the string once: O(n).
// Constructing words and the result string: O(k) (where k is the total number of characters processed during word concatenation).
// Overall: O(n^2) (due to string concatenation in the result).

// Space Complexity
// 	•	Storage for vector<string>: O(n).
// 	•	Final result string: O(n).
// 	•	Total: O(n).

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words; // To store the words
        int n = s.length();
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') { // Skip spaces
                string word = "";
                while (i >= 0 && s[i] != ' ') { // Build a word
                    word = s[i] + word; // Add character to the front : inefficient concatenation
                    i--;
                }
                words.push_back(word); // Add the word to the list
            }
        }
        
        // Build the final string
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) { // Add a space between words
                result += " ";
            }
        }
        /*
        // alternatively
        string result = "";
        for (int i = 0; i < words.size()-1; i++) {
            result += words[i]+" ";
        }
        result+=words[words.size()-1];
        */
        
        return result;
    }
};


// chatGPT better sol
// 1.	Traverse the string from the end.
// 2.	Extract words, reverse them using a helper function, and add to the result.

// •	Time Complexity: O(n^2).
// •	Space Complexity: O(n).

class Solution {
    public:
        string rev(string &s){
            int n = s.length();
            int l = 0 , h = n-1;
            while(l <= h){
                char temp = s[l];
                s[l] = s[h];
                s[h] = temp;
                l++;
                h--;
            }
            return s;
        }

        string reverseWords(string s) {
            int n = s.length();
            string ans = "";
            for (int i = n-1; i >= 0; i--) {
                if (s[i] != ' ') {
                    string temp = "";
                    while (i >= 0 && s[i] != ' ') {
                        temp = temp + s[i];
                        i--;
                    }
                    ans = ans + rev(temp) + " ";
                }
            }
            ans.erase(ans.length() - 1); // Remove trailing space
            return ans;
        }
};


// solnn 2 : O(n^2) solution

class Solution {
    public:
        string rev(string s){
            int n = s.length();
            int l=0 , h = n-1;
            while(l<h){
                // swap(s[l] , s[h]);
                char temp = s[l];
                s[l] = s[h];
                s[h] = temp;
                l++; h--;
            }
            return s;
        }
        string reverseWords(string s) {
            int n = s.length();
            string ans = "";
            for(int i = n-1 ; i>=0 ; i--){
                // if((int)s[i]!=32){}
                if(s[i]!=' '){
                    string temp = "";
                    while(i>=0 && s[i]!=' '){
                        // temp+=s[i--];
                        temp =  temp + s[i];
                        i--;
                    }
                    ans = ans+rev(temp);
                    // if(i>=0){ans += " ";}
                    ans += " ";
                }
            }
            int m = ans.length();
            ans.erase(m-1);
            return ans;
        }
};


// chatGPT optimal sol
// •	Time Complexity: O(n) (single pass for each step).
        	// 1.	Trimming Spaces: O(n)
            // 2.	Reversing Entire String: O(n)
            // 3.	Reversing Individual Words: O(n)
            // 4.	Overall: O(n).
// •	Space Complexity: O(1) (in-place operations).

//Description:
	// 1.	Trim Spaces: Remove leading, trailing, and redundant spaces.
	// 2.	Reverse Entire String: Reverse the string as a whole.
	// 3.	Reverse Individual Words: Reverse each word in the reversed string.


// (Two-Pointer In-Place Solution)

// If in-place manipulation is preferred, you can:
// 	1.	Trim leading and trailing spaces.
    // •	Traverse the string and add characters to trimmed if:
    // 1.	It's not a space, OR
    // 2.	It's a space but the last character in trimmed is not a space (to avoid multiple spaces).
// 	2.	Reverse the entire string.
// 	3.	Reverse each word individually.
    // •	Use two pointers: start (beginning of the current word) and end (find spaces to locate the end of a word).
    // •	When a space or end of the string is encountered, reverse the substring from start to end - 1.
    // •	Move start to the next word after the space.


// TC : O(N) , SC : O(1)

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        int n = s.length();
        string trimmed = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ' || (!trimmed.empty() && trimmed.back() != ' ')) {
                trimmed += s[i];
            }
        }
        // remove last space
        if (!trimmed.empty() && trimmed.back() == ' ') {
            trimmed.pop_back();
        }

        // Step 2: Reverse the entire string
        reverse(trimmed.begin(), trimmed.end());

        // Step 3: Reverse each word
        int start = 0;
        for (int end = 0; end <= trimmed.length(); end++) {
            if (end == trimmed.length() || trimmed[end] == ' ') {
                reverse(trimmed.begin() + start, trimmed.begin() + end); 
                start = end + 1;
            }
        }

        return trimmed;
    }
};