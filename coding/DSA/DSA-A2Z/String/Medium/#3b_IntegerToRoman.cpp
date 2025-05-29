#include<bits/stdc++.h>
using namespace std;

// my solution : brute

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mpp;
        mpp[1] = "I";
        mpp[5] = "V";
        mpp[10] = "X";
        mpp[50] = "L";
        mpp[100] = "C";
        mpp[500] = "D";
        mpp[1000] = "M";
        mpp[4] = "IV";
        mpp[9] = "IX";
        mpp[40] = "XL";
        mpp[90] = "XC";
        mpp[400] = "CD";
        mpp[900] = "CM";

        int mod = 10;
        stack<string> st;
        int rem;
        while (num>0)
        {
            rem = num%mod;
            if(mpp.find(rem)!=mpp.end()){
                st.push(mpp[rem]);
            }
            else if(rem > (mod/2)){
                string temp2 = mpp[mod/2];

                int rem2 = rem%(mod/2);
                rem2/=(mod/10);
                string temp = "";
                for(int i=0 ; i<rem2 ; i++){
                    temp+=mpp[mod/10];
                }
                st.push(temp);
                st.push(temp2);
            }
            else{
                string temp = "";
                int rem2 = rem/(mod/10);
                // rem2/=(mod/10);
                for(int i=0 ; i<rem2 ; i++){
                    temp+=mpp[mod/10];
                }
                st.push(temp);
            }
            num -= rem;
            mod*=10;
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};

