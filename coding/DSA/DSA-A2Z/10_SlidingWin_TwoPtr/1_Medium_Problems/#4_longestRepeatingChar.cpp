#include<bits/stdc++.h>
using namespace std;


// my brute try
// TC : O(n * 26)
// SC : O(26)

class Solution {
public:

    int findMax(unordered_map<char , int> freq){
        int maxi = 0;
        for(auto it : freq){
            maxi = max(maxi , it.second);
        }
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int l=0 , r=0 , maxLen = 0 , n=s.size();
        unordered_map<char , int> freq;
        while(r<n){
            freq[s[r]]++;
            while(r-l+1 - findMax(freq) > k){
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};


// my optimal try 
// TC : O(n)
// SC : O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 , r=0 , maxLen = 0 , n=s.size();
        unordered_map<char , int> freq;
        int maxFreq = 0;
        while(r<n){
            freq[s[r]]++;
            maxFreq = max(maxFreq , freq[s[r]]);
            while(r-l+1 - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};


// optimal sol : map
// TC : O(n)
// SC : O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 , r=0 , maxLen = 0 , n=s.size();
        unordered_map<char , int> freq;
        int maxFreq = 0;
        while(r<n){
            freq[s[r]]++;
            maxFreq = max(maxFreq , freq[s[r]]);
            if(r-l+1 - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};



// striver's better sol
// TC : O(n * 26)
// SC : O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int l = 0, r = 0, maxLen = 0;

        while (r < n) {
            freq[s[r] - 'A']++;

            // Recalculate maxFreq in the current window
            int maxFreq = 0;
            for (int i = 0; i < 26; ++i) {
                maxFreq = max(maxFreq, freq[i]);
            }

            // If more than k replacements needed, shrink the window
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

// striver's optimal sol
// TC : O(n)
// SC : O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, maxLen = 0;

        for (int r = 0; r < n; ++r) {
            maxFreq = max(maxFreq, ++freq[s[r] - 'A']); // increment and update maxFreq
            // If more than k replacements are needed, shrink window
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

