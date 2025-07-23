#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool signFlag = true; //sign : true => +ve , false => -ve (set to +ve intially)
        bool encountered = false; //character other than whitespace encountered
        int res = 0; // initial result
        for(auto &ch : s){
            int code = (int)ch; //ASCII code
            if(!encountered){ //if not encountered any character other than whitespace
                if(ch==' '){continue;} //ignoring
                else{ //firsst char other tha whitespace encountered
                    encountered = true; // flag changed
                    if((ch=='-'||ch=='+')){ //checking for signed characters
                        if(ch=='-'){signFlag = false; } //changing flag only for negative
                        continue; //ignore rest logic
                    }
                }
            }
            
            if((48<=code)&&(code<=57)){ //if decimal digit i.e. 0 to 9
                if(signFlag){ // if +ve
                    if((res>INT_MAX/10)||((res==INT_MAX/10)&&((code-48)>7))){ //checking for range
                        return INT_MAX; // rounding off to greatest +ve integer
                    }
                    else{
                        res = res*10 + (code-48); // (code-48) gives decimal integer corresponding to ASCII code
                    }
                }
                else{ // if !signFlag => negative
                    if((res<INT_MIN/10)||((res==INT_MIN/10)&&((code-48)>8))){ //checking for range
                        return INT_MIN; // rounding off to greatest -ve integer
                    }
                    else{
                        res = res*10 - (code-48); // - for negative integers
                    }
                }
            }

            else{
                break; // if any other char (other than decimal encountered again, then break)
            }
        }
        return res; //returning result
    }
};