#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    string str="";
    int maxi=0;
    for(int i=0; i<s.size(); i++){
        int size=str.size();
        for(int j=0; j<size; j++){
            if(str[j]==s[i]){
                str.erase(str.begin(),str.begin()+j+1);
                break;
            }
        }
        str.push_back(s[i]);
        int n=str.size();
        maxi=max(n,maxi);
    }
    return maxi;
    }
};