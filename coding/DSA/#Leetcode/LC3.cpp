#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i=0 ; i< s.length() ; i++ ){
            unordered_map<int,char> hashtable;
            int curr=0;
            int j=i;
            while ((hashtable.find(int(s[j]))==hashtable.end())&&(j<s.length()))
            {
                hashtable[int(s[j])] = s[j];
                j++; curr++;
                res=max(res,curr);
            }
        }
        return res;
    }
};


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i=0 ; i< s.length() ; i++ ){
            unordered_map<char,char> hashtable;
            int curr=0;
            int j=i;
            while ((hashtable.find(s[j])==hashtable.end())&&(j<s.length()))
            {
                hashtable[s[j]] = s[j];
                j++; curr++;
                res=max(res,curr);
            }
        }
        return res;
    }
};