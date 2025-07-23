#include<bits/stdc++.h>
using namespace std;


// brute sol
/*
	1.	Time Complexity: O(n*log n)
	•	Sorting both strings takes O(n*log n), where n is the length of the strings.
	2.	Space Complexity: O(1) or O(n)
	•	If sorting is done in-place, the space complexity is O(1).
	•	If a new sorted string is created, the space complexity is O(n).
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length(); 
        int n2 = t.length(); 
        if (n1 != n2) 
            return false; 
    
        sort(s.begin(), s.end()); 
        sort(t.begin(), t.end()); 
    
        return (s==t); 
    }
};

// better
/*
	1.	Time Complexity: O(n)
	•	Single traversal of both strings (O(n)).
	•	Checking the frequency array takes O(26), which is constant.
	2.	Space Complexity: O(1)
	•	The frequency array uses a fixed size of 26, so it is O(1) in terms of auxiliary space.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters

        // Update frequency array
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++; // Increment for s
            freq[t[i] - 'a']--; // Decrement for t
        }

        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

// best : my approach

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> freq;

        // Count characters in s
        for (char c : s) {
            freq[c]++;
        }

        // Subtract counts using characters in t
        for (char c : t) {
            freq[c]--;
            // if (freq[c] < 0) { // Early exit if count goes negative
            //     return false;
            // }
        }

        // check if all mappings are zero
        for(auto it : freq){
            if(it.second!=0){return false;}
        }

        // else true
        return true;
    }
};

// chat GPT's optimizations to best sol


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> freq;

        // Count characters in s
        for (char c : s) {
            freq[c]++;
        }

        // Subtract counts using characters in t
        /*
        how it handles the cases of an extra(mismatched) char in t 	
        If t contains an extra character that does not exist in s, this character will 
        not have an entry in the hashmap. Therefore, freq[c]-- for such a character will 
        result in an implicit initialization of freq[c] to 0 (default behavior for unordered_map) 
        and decrementing it to -1.
        */
        for (char c : t) {
            freq[c]--;
            if (freq[c] < 0) { // Early exit if count goes negative
                return false;
            }
        }

        return true; // All counts should be zero
    }
};