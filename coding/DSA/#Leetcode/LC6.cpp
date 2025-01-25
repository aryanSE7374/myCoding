#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string str="";
        int len = s.length();
        for (int i = 0; i < numRows; i++)
        {
            int j=i;
            str+=s[j];
            if((numRows==1)||(numRows>=len)){
                return s;
            }
            if(i==0){
                while (j<len)
                {
                    j+=(2*(numRows-i-1));
                    if(j<len){
                        str+=s[j];  
                    }
                }
            }
            else if(i==(numRows-1)){
                while (j<len)
                {
                    j+=(2*i); 
                    if(j<len){
                        str+=s[j];
                    }
                }
            }
            else{
                while (j<len)
                {
                    j+=(2*(numRows-i-1));
                    if(j<len){
                        str+=s[j];
                        j+=(2*i);  
                    }
                    if(j<len){
                        str+=s[j];
                    }
                }
            }
        }
        return str; 
    }
};