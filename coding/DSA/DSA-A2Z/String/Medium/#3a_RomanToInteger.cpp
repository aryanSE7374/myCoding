#include<bits/stdc++.h>
using namespace std;

// my solution

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mpp1;
        mpp1['I'] = 1;
        mpp1['V'] = 5;
        mpp1['X'] = 10;
        mpp1['L'] = 50;
        mpp1['C'] = 100;
        mpp1['D'] = 500;
        mpp1['M'] = 1000;

        unordered_map<string, int> mpp2;
        mpp2["IV"] = 4;
        mpp2["IX"] = 9;
        mpp2["XL"] = 40;
        mpp2["XC"] = 90;
        mpp2["CD"] = 400;
        mpp2["CM"] = 900;


        int num=0;
        int i = 0;
        for( ; i < s.length()-1; i++)
        {
            if( mpp1[s[i]]>=mpp1[s[i+1]]  ){
                num+=mpp1[s[i]];
            }
            else{//mpp1[s[i]]< mpp1[s[i+1]]
                string auxStr = "";
                // auxStr.insert(auxStr.begin(),s[i]);
                // auxStr.insert(auxStr.begin()+1,s[i+1]);
                auxStr = auxStr + s[i] + s[i+1];
                num+=mpp2[auxStr];
                i++;
            }
        }
        if(i<s.length()){
            num+=mpp1[s[i]];
        }
        return num;
    }
};

