#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        string str = "";
        int a  = numerator;
        int b = denominator;

        int q = a/b;
        str += to_string(q);
        int r = a%b;
        if(r==0){
            return str;
        }


        str += ".";
        int k = str.size();


        unordered_map<string , int> mpp;
        int start = 0;
        int end = 0;

        for(int i=k ; i<10000 ; i++){

            if(r==0){
                return str;
            }

            r*=10;
            q = r/b;
            if(mpp.find(to_string(q))!=mpp.end()){
                start = mpp[to_string(q)];
                end = i-1;
                break;
            }
            mpp[to_string(q)] = i;
            str += to_string(q);
            r = r%b;

        }

        string temp = str.substr(start , end);

        str = str.substr(0 , k);
        if(k<start-1){
            str += str.substr(k+1 , start-1);
        }
        str+=('('+temp+')');

        return str;




        


        // for(int i=k ; i<str.size() ; i++){
        //     return str;
        // }


        // return "";


    }
};

