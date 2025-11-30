#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int m = g.size();
        int n = s.size();

        int i=0 ; 
        int j=0 ;

        int ans = 0;

        while(j<n && i<m){
            if(s[j]>=g[i]){
                i++;
                ans++;
            }
            j++;
        }

        return ans;

    }
};
