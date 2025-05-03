#include<bits/stdc++.h>
using namespace std;

// O(n^2) solution

class Solution {
    public:
        string rev(string s){
            int n = s.length();
            int l=0 , h = n-1;
            while(l<h){
                // swap(s[l] , s[h]);
                char temp = s[l];
                s[l] = s[h];
                s[h] = temp;
                l++; h--;
            }
            return s;
        }
        string reverseWords(string s) {
            int n = s.length();
            string ans = "";
            for(int i = n-1 ; i>=0 ; i--){
                // if((int)s[i]!=32){}
                if(s[i]!=' '){
                    string temp = "";
                    while(i>=0 && s[i]!=' '){
                        // temp+=s[i--];
                        temp =  temp + s[i];
                        i--;
                    }
                    ans = ans+rev(temp);
                    // if(i>=0){ans += " ";}
                    ans += " ";
                }
            }
            int m = ans.length();
            ans.erase(m-1);
            return ans;
        }
};


/*
class Solution {
    public:
    
        string reverseString(string &s){
            int n = s.length();
            int l = 0 , h = n-1;
            while(l <= h){
                char temp = s[l];
                s[l] = s[h];
                s[h] = temp;
            }
            return s;
        }

        // void reverseString(string &s){
        //     int n = s.length();
        //     int l = 0 , h = n-1;
        //     while(l <= h){
        //         char temp = s[l];
        //         s[l] = s[h];
        //         s[h] = temp;
        //     }
        //     return s;
        // }


        string reverseWords(string s) {
            vector<string> vec;

            // int n = strlen(s);
            int n = s.length();
            for(int i = n-1 ; i>=0 ; i--){
                string word = "";
                while ((i>=0) && (s[i] != " "))
                {
                    i--;
                }
                
            }

        }
    };
*/

