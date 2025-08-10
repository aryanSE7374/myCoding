#include<bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)  (assumes ASCII charset, freq size constant)

// sol1
// TC: O(n) 
// SC: O(k) — at most k characters in the map
class Solution1 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size() , maxLen = 0;
        int l=0 , r=0;
        unordered_map<char , int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){mpp.erase(s[l]);}
                l++;
            }
            if(mpp.size()<=k){maxLen = max(maxLen , r-l+1 );}
            r++;
        }
        return maxLen;
    }
};

// sol2
// TC: O(n) 
// SC: O(k)
class Solution1 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size() , maxLen = 0;
        int l=0 , r=0;
        unordered_map<char , int> mpp;
        while(r<n){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){mpp.erase(s[l]);}
                l++;
            }
            if(mpp.size()<=k){maxLen = max(maxLen , r-l+1 );}
            r++;
        }
        return maxLen;
    }
};

// GFG alternative  : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// sol1
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size() , maxLen = -1;
        int l=0 , r=0;
        unordered_map<char , int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){mpp.erase(s[l]);}
                l++;
            }
            if(mpp.size()==k){maxLen = max(maxLen , r-l+1 );}
            r++;
        }
        return maxLen;
        
    }
};

// sol2 
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size() , maxLen = -1;
        int l=0 , r=0;
        unordered_map<char , int> mpp;
        while(r<n){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){mpp.erase(s[l]);}
                l++;
            }
            if(mpp.size()==k){maxLen = max(maxLen , r-l+1 );}
            r++;
        }
        return maxLen;
        
    }
};