#include<bits/stdc++.h>
using namespace std;


/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order 
of characters. No two characters may map to the same character, but a character may map to itself.
*/

// my try 1 : failed

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // constraints given : t.length() == s.length()
        unordered_map<char , char> mp;
        for (int i = 0; i < s.length(); i++)
        {
            // if(mp.find(s[i])==mp.end()){ // not found key s[i]
            //     mp[s[i]] = t[i];
            // }
            if( (mp.find(s[i])!=mp.end()) && (mp[s[i]] != t[i]) ){
                    return false;
            }
            mp[s[i]] = t[i];
        }
        return true;
    }
};

// my try 2

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // constraints given : t.length() == s.length()
        unordered_map<char , char> mp;
        for (int i = 0; i < s.length(); i++)
        { 
            // if(mp.find(s[i])==mp.end()){ // not found key s[i]
            //     mp[s[i]] = t[i];
            // }
            // check if there's a key s[i] that maps to a different character , then return false
            if( (mp.find(s[i])!=mp.end()) && (mp[s[i]] != t[i]) ){
                    return false;
            }
            for(auto it : mp){ // check whether the s[i] maps to the unique character or not
                if(it.second == t[i]){return false;}
            }
            // add s[i]->t[i]
            mp[s[i]] = t[i];
        }
        return true;
    }
};

// my try 3 : hints -> two maps to check bi directional mapping
// Time complexity: O(N) + O(N) = O(2N) = O(N)
// Space complexity: O(U) + O(U) = O(2U) = O(U)
// working

class Solution {
public:

    bool revIsomorphic(string t , string s){
        unordered_map<char , char> mp;
        for (int i = 0; i < s.length(); i++)
        {
            // if(mp.find(s[i])==mp.end()){ // not found key s[i]
            //     mp[s[i]] = t[i];
            // }
            if( (mp.find(s[i])!=mp.end()) && (mp[s[i]] != t[i]) ){
                    return false;
            }
            mp[s[i]] = t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        // constraints given : t.length() == s.length()
        if(!revIsomorphic(s , t)){return false;}
        unordered_map<char , char> mp;
        for (int i = 0; i < s.length(); i++)
        {
            // if(mp.find(s[i])==mp.end()){ // not found key s[i]
            //     mp[s[i]] = t[i];
            // }
            if( (mp.find(s[i])!=mp.end()) && (mp[s[i]] != t[i]) ){
                    return false;
            }
            mp[s[i]] = t[i];
        }
        return true;
    }
};

// chatGPT's optimization
// Time Complexity: O(N), where N is the length of the strings.
// Space Complexity: O(U), where U is the number of unique characters in the strings, and U <= N. (map)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t, t_to_s;

        for (int i = 0; i < s.length(); i++) {
            char s_char = s[i], t_char = t[i];

            // Check forward mapping
            if (s_to_t.count(s_char) && s_to_t[s_char] != t_char) {
                return false;
            }

            // Check reverse mapping
            if (t_to_s.count(t_char) && t_to_s[t_char] != s_char) {
                return false;
            }

            // Update both mappings
            s_to_t[s_char] = t_char;
            t_to_s[t_char] = s_char;
        }

        return true;
    }
};