#include<bits/stdc++.h>
using namespace std;

// striver's sol

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int maxLen = 0;
        int n = s.length();
        vector<int> hash(256 , -1); // hash table to store indices of each char

        while (r<n)
        {
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                    l = hash[s[r]]+1;
            }
            maxLen = max(maxLen , r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};