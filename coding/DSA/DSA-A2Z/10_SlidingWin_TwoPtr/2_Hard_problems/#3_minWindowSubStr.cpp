#include<bits/stdc++.h>
using namespace std;


// brute solution : O(N^2) , O(256) : produces TLE

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        int minLen = INT_MAX , sIndex = -1; // startIndex
        for(int i= 0; i<n ; i++ ){
            int hash[256] = {0};
            int count = 0; // will keep track of no. of preInserted elements 
            // in hash that has been used in the current soliding window
            for(int j=0 ; j<m ; j++){
                hash[t[j]]++;
            }
            for(int j=i ; j<n ; j++){
                if(hash[s[j]]>0){ // a precomputed element from hash has been inserted in the window
                    count++;
                }
                hash[s[j]]--;
                if(count==m){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        sIndex = i;
                        break;
                    }
                }
            }
        }
        return sIndex==-1 ? "" : s.substr(sIndex , minLen);
    }
};


// my optimal try 
// TC : O(N) , 
// SC : O(m)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        unordered_map<char , int> t_freq;
        for(char c : t){
            t_freq[c]++;
        }
        int l=0 , r=0 , minLen=INT_MAX , count=0 , sIndex = -1;

        while(r<n){
            if(t_freq[s[r]]>0){count++;}
            t_freq[s[r]]--;
            while(count == m){
                if(r-l+1 < minLen ){
                    minLen = r-l+1;
                    sIndex = l;
                }
                t_freq[s[l]]++;
                if(t_freq[s[l]]>0){count--;}
                l++;
            }
            r++;
        }
        return sIndex==-1 ? "" : s.substr(sIndex , minLen);
    }
};

// striver's optimal solution
// TC : O(N) , 
// SC : O(256)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        int t_freq[256] = {0};
        for(char c : t){
            t_freq[c]++;
        }
        int l=0 , r=0 , minLen=INT_MAX , count=0 , sIndex = -1;

        while(r<n){
            if(t_freq[s[r]]>0){count++;}
            t_freq[s[r]]--;
            while(count == m){
                if(r-l+1 < minLen ){
                    minLen = r-l+1;
                    sIndex = l;
                }
                t_freq[s[l]]++;
                if(t_freq[s[l]]>0){count--;}
                l++;
            }
            r++;
        }
        return sIndex==-1 ? "" : s.substr(sIndex , minLen);
    }
};


