#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n==1 || numRows<2 || n<=numRows) return s;
        string ans;
        for(int i=0;i<numRows;i++){
            int j=i;
            ans.push_back(s[i]);
            int down=2*(numRows-1-i);
            int up=2*(i);
            if(up==0 && down==0) return s;
            while(j<n){
                j+=down;
                if(j<n && down>0) ans.push_back(s[j]);
                j+=up;
                 if(j<n && up>0) ans.push_back(s[j]);
            }
        }
        return ans;
    }
};