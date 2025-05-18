#include <iostream>
using namespace std;

// my solution : 

// TC : O(N^2) , SC : O(N)


class Solution {
    public:
        // it is a O(len_of_s)
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
            for(int i = n-1 ; i>=0 ; i--){ // O(n)
                // if((int)s[i]!=32){}
                if(s[i]!=' '){
                    string temp = "";
                    while(i>=0 && s[i]!=' '){
                        // temp+=s[i--];
                        temp =  temp + s[i];
                        i--;
                    }
                    // temp = rev(temp);
                    ans = ans+rev(temp); // O(n) : O(len_of_ans)
                    ans += " ";
                }
            }
            int m = ans.length();
            ans.erase(m-1);
            return ans;
        }
};

// brute
// TC : O(N) , SC : O(N)

class Solution {
public:
    string reverseWords(string s) {
        s += " "; // Add a space at the end to push the last word into the stack
        stack<string> st;
        string temp = "";

        // Iterate over the string to extract words and push them onto the stack
        for (char ch : s) {
            if (ch == ' ') {
                if (!temp.empty()) { // Push the word only if it's non-empty
                    st.push(temp);
                    temp = "";
                }
            } else {
                temp += ch;
            }
        }

        string ans = "";

        // Pop words from the stack to form the reversed sentence
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " "; // Add a space between words
            }
        }

        return ans;
    }
};


// Optimal Solution (Two-Pointer with In-Place Concatenation)
// TC : O(N^2) , SC : O(N)

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;
        string temp = "";
        string ans = "";

        // Skip leading and trailing spaces
        while (left <= right) {
            char ch = s[left];

            if (ch != ' ') {
                temp += ch; // Form the current word
            } else if (ch == ' ') {
                if (!temp.empty()) { // Add the current word to the result
                    if (!ans.empty()) {
                        ans = temp + " " + ans; // Add to the front
                    } else {
                        ans = temp; // First word
                    }
                    temp = ""; // Reset the temp for the next word
                }
            }
            left++;
        }

        // Add the last word (if any)
        if (!temp.empty()) {
            if (!ans.empty()) {
                ans = temp + " " + ans;
            } else {
                ans = temp;
            }
        }

        return ans;
    }
};

// chatGPT soln : 
// Optimized Approach
// Instead of manually reversing each word and concatenating, you can:
// 	1.	Split the string into words.
// 	2.	Reverse the order of the words.
// 	3.	Join them into a single string.

// TC : O(N) , SC : O(N)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        int n = s.length();

        // Collect words from the input string
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words into a single string with spaces
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};

// chatGPT soln : 
// Alternative (Two-Pointer In-Place Solution)

// If in-place manipulation is preferred, you can:
// 	1.	Trim leading and trailing spaces.
// 	2.	Reverse the entire string.
// 	3.	Reverse each word individually.

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