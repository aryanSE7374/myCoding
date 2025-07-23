#include<bits/stdc++.h>
using namespace std;


/*

// tried approach

// 10^9 +7 = 1000000007

class Solution {
    public:
        void countPerms(int n , vector<string> &arr){
            if(n==1){
                arr.push_back("a");
                arr.push_back("e");
                arr.push_back("i");
                arr.push_back("o");
                arr.push_back("u");
                // return arr;
            }
            
            // Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
            // Each vowel 'a' may only be followed by an 'e'.
            // Each vowel 'e' may only be followed by an 'a' or an 'i'.
            // Each vowel 'i' may not be followed by another 'i'.
            // Each vowel 'o' may only be followed by an 'i' or a 'u'.
            // Each vowel 'u' may only be followed by an 'a'.
            
           countPerms(n-1 , arr);
           for(int i=0 ; i<arr.size() ; i++){
               int len = arr[i].length();
               if(arr[i][len-1] == 'a'){
                   string str1 = arr[i];
                   str1+='e';
                   arr.push_back(str1);
               }
               if(arr[i][len-1] == 'e'){
                   string str1 = arr[i];
                   string str2 = str1;
                   str1+='a';
                   str2+='i';
                   arr.push_back(str1);
                   arr.push_back(str2);
               }
               if(arr[i][len-1] == 'i'){
                   string str1 = arr[i];
                   string str2 = str1;
                   string str3 = str1;
                   string str4 = str1;
                   str1+='a';
                   str2+='e';
                   str3+='o';
                   str4+='u';
                   arr.push_back(str1);
                   arr.push_back(str2);
                   arr.push_back(str3);
                   arr.push_back(str4);
               }
               if(arr[i][len-1] == 'o'){
                   string str1 = arr[i];
                   string str2 = str1;
                   str1+='i';
                   str2+='u';
                   arr.push_back(str1);
                   arr.push_back(str2);
               }
               if(arr[i][len-1] == 'u'){
                   string str1 = arr[i];
                   str1+='a';
                   arr.push_back(str1);
               }
           }
       }
       int countVowelPermutation(int n) {
           vector<string> arr ; 
           // countPerms(n , arr);
           if(n==1){return 5;}
           arr.push_back("a");
           arr.push_back("e");
           arr.push_back("i");
           arr.push_back("o");
           arr.push_back("u");
           for(int j = 0 ; j<n ; j++){
               for(int i=0 ; i<arr.size() ; i++){
                   int len = arr[i].length();
                   if(arr[i][len-1] == 'a'){
                       string str1 = arr[i];
                       str1+='e';
                       arr.push_back(str1);
                   }
                   if(arr[i][len-1] == 'e'){
                       string str1 = arr[i];
                       string str2 = str1;
                       str1+='a';
                       str2+='i';
                       arr.push_back(str1);
                       arr.push_back(str2);
                   }
                   if(arr[i][len-1] == 'i'){
                       string str1 = arr[i];
                       string str2 = str1;
                       string str3 = str1;
                       string str4 = str1;
                       str1+='a';
                       str2+='e';
                       str3+='o';
                       str4+='u';
                       arr.push_back(str1);
                       arr.push_back(str2);
                       arr.push_back(str3);
                       arr.push_back(str4);
                   }
                   if(arr[i][len-1] == 'o'){
                       string str1 = arr[i];
                       string str2 = str1;
                       str1+='i';
                       str2+='u';
                       arr.push_back(str1);
                       arr.push_back(str2);
                   }
                   if(arr[i][len-1] == 'u'){
                       string str1 = arr[i];
                       str1+='a';
                       arr.push_back(str1);
                   }
               }
           }
           return arr.size();
       }
   };
   

class Solution {
    public:
            int countVowelPermutation(int n) {
                vector<string> arr ; 
                // countPerms(n , arr);
                if(n==1){return 5;}
                arr.push_back("a");
                arr.push_back("e");
                arr.push_back("i");
                arr.push_back("o");
                arr.push_back("u");
                for(int j = 0 ; j<n ; j++){
                    for(int i=0 ; i<arr.size() ; i++){
                        int len = arr[i].length();
                        if(arr[i][len-1] == 'a'){
                            string str1 = arr[i];
                            str1+='e';
                            arr.push_back(str1);
                        }
                        if(arr[i][len-1] == 'e'){
                            string str1 = arr[i];
                            string str2 = str1;
                            str1+='a';
                            str2+='i';
                            arr.push_back(str1);
                            arr.push_back(str2);
                        }
                        if(arr[i][len-1] == 'i'){
                            string str1 = arr[i];
                            string str2 = str1;
                            string str3 = str1;
                            string str4 = str1;
                            str1+='a';
                            str2+='e';
                            str3+='o';
                            str4+='u';
                            arr.push_back(str1);
                            arr.push_back(str2);
                            arr.push_back(str3);
                            arr.push_back(str4);
                        }
                        if(arr[i][len-1] == 'o'){
                            string str1 = arr[i];
                            string str2 = str1;
                            str1+='i';
                            str2+='u';
                            arr.push_back(str1);
                            arr.push_back(str2);
                        }
                        if(arr[i][len-1] == 'u'){
                            string str1 = arr[i];
                            str1+='a';
                            arr.push_back(str1);
                        }
                    }
                }
                return arr.size();
            }
    };


*/

// accepted brute solution using hmap
class Solution {
    public:
        int countVowelPermutation(int n) {
            int mod = 1000000007;
            if(n==1){return 5;}
            unordered_map<char , int> h ;
            h['a']=1;
            h['e']=1;
            h['i']=1;
            h['o']=1;
            h['u']=1;
            for(int i = 1 ; i<n ;i++){
                unordered_map<char , int> h1 ;
                h1['a'] = ((h['e'] + h['i']) % mod + h['u']) % mod;
                h1['e'] = (h['a'] + h['i']) % mod;
                h1['i'] = (h['e'] + h['o']) % mod;
                h1['o'] = h['i'] % mod;
                h1['u'] = (h['i'] + h['o']) % mod;
                h = h1;
            }
            // long long longNum = (h['a'] + h['e'] + h['i'] + h['o'] + h['u']);
            // int ans = longNum%mod ;
            // return ans;
            int ans =  ((((( h['a'] + h['e'] )%mod + h['i'] )%mod + h['o'] )%mod + h['u'] )%mod) ;
            return ans;
        }
    };

// chatGPT optimized solution 
class Solution {
    public:
        int countVowelPermutation(int n) {
            int mod = 1000000007;
    
            // Initialize counts for each vowel
            long a = 1, e = 1, i = 1, o = 1, u = 1;
    
            for (int step = 1; step < n; step++) {
                long a_new = (e + i + u) % mod;
                long e_new = (a + i) % mod;
                long i_new = (e + o) % mod;
                long o_new = i % mod;
                long u_new = (i + o) % mod;
    
                // Update values for the next iteration
                a = a_new;
                e = e_new;
                i = i_new;
                o = o_new;
                u = u_new;
            }
    
            // Return the total permutations
            return (a + e + i + o + u) % mod;
        }
    };