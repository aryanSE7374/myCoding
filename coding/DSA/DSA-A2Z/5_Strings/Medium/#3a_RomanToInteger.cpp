#include<bits/stdc++.h>
using namespace std;

// my solution
// Time Complexity: O(n)
// Space Complexity: O(1) (as map size is fixed).

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


// GPT brute solution
// Time Complexity: O(n)
// Space Complexity: O(1) (as map size is fixed).

class Solution {
public:
    int romanToInt(string s) {
    unordered_map<string, int> values = {
        {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
        {"C", 100}, {"D", 500}, {"M", 1000},
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
        {"CD", 400}, {"CM", 900}
    };

    int num = 0;
    for (int i = 0; i < s.length(); ) {
        if (i < s.length() - 1 && values.count(s.substr(i, 2))) {
            num += values[s.substr(i, 2)];
            i += 2;
        } else {
            num += values[string(1, s[i])];
            i++;
        }
    }
    return num;
    }
};

// GPT better solution : Optimal as no more optimizations can be made
// using one map only
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && values[s[i]] < values[s[i + 1]]) {
                num -= values[s[i]];
            } else {
                num += values[s[i]];
            }
        }
        return num;
    }
};

// alternative optimal solution
// mapping based on ASCII code in a vector as its index

class Solution {
 public:
  int romanToInt(string s) {
    int ans = 0;
    vector<int> roman(128);

    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (roman[s[i]] < roman[s[i + 1]])
        ans -= roman[s[i]];
      else
        ans += roman[s[i]];

    return ans + roman[s.back()];
  }
};