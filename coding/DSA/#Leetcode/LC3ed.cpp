#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hash.find(s[r]) != hash.end()
        int maxLen=0;
        int n = s.length();
        int start=-1;
        vector<int> dist(256,-1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dist[s[i]] > start) {
                start = dist[s[i]];
                cnt = i - start;
            } else {
                cnt++;
            }
            dist[s[i]] = i;
            maxLen = max(maxLen, cnt);
        }
        return maxLen;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
       int maxLength=0,start=-1;
       vector<int> dict(256,-1);
        for(int i=0;i<s.size();i++){
            if(dict[s[i]]>start){
                start=dict[s[i]];
            }
            dict[s[i]]=i;
            maxLength=max(maxLength,i-start);
        }
        return maxLength;
    }
};