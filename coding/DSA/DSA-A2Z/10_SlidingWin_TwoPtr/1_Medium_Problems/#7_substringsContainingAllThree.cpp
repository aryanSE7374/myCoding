#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1}; // last seen index of 'a', 'b', 'c'
        int count = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
            
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += (min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1); // or use nested min()
            }
        }
        return count;
    }
};

// sliding window version by chatGPT

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> freq(3, 0); // To count 'a', 'b', 'c'
        int left = 0, count = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;

            // shrink window from left until we still have at least one of each
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n - right); // all substrings from s[left...right] to s[left...n-1] are valid
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};