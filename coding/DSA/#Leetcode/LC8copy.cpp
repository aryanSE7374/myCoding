#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool signFlag = true;
        bool encountered = false;
        int res = 0;
        for(auto &ch : s){
            int code = (int)ch;
            if(!encountered){
                if(ch==' '){continue;}
                else{
                    encountered = true;
                    if((ch=='-'||ch=='+')){
                        if(ch=='-'){signFlag = false;}
                        continue;
                    }
                }
            }

            if((48<=code)&&(code<=57)){
                if(signFlag){
                    if((res>INT_MAX/10)||((res==INT_MAX/10)&&((code-48)>7))){
                        return INT_MAX;
                    }
                    else{
                        res = res*10 + (code-48);
                    }
                }
                else{ // if !signFlag => negative
                    if((res<INT_MIN/10)||((res==INT_MIN/10)&&((code-48)>8))){
                        return INT_MIN;
                    }
                    else{
                        res = res*10 - (code-48); 
                    }
                }
            }

            else{
                break;
            }
        }
        return res;
    }
};