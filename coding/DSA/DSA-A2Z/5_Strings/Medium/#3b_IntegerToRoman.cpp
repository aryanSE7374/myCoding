#include<bits/stdc++.h>
using namespace std;

// my solution : brute , poorly implemented
/*
•	Time Complexity: O(\log_{10}(n)), since each digit is processed individually (there are at most 4 digits in the input n since the maximum input is 3999).
•	Space Complexity: O(\log_{10}(n)) for the stack storage.
*/ 

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

                int rem2 = rem%(mod/2); // rem2 = rem - (mod/2);
                rem2/=(mod/10); // count for number of repeating characters
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

// GPT : brute solution
// •	Time Complexity: O(n), where n is the input integer’s number of digits.
// •	Space Complexity: O(1).

class Solution{
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";
        for (auto &[value, symbol] : roman) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};

// GPT : better
// string intToRoman(int num) {
//     vector<pair<int, string>> roman = {
//         {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
//         {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
//         {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
//     };

//     string result = "";
//     for (const auto &[value, symbol] : roman) {
//         int count = num / value;
//         num %= value;
//         result.append(count, symbol[0]);
//         if (symbol.size() == 2) {
//             result.append(count, symbol[1]);
//         }
//     }
//     return result;
// }

// GPT better which is the best

/*
•	Time Complexity: O(1)
	The Roman numeral vector always has 13 pairs, and the loop processes each pair in constant time.
•	Space Complexity: O(1)
	The space used for the Roman numeral vector is constant, and the result string grows linearly with the output size.
*/

class Solution{
    public: 
    string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";
    for (const auto &[value, symbol] : roman) {
        int count = num / value;
        num %= value;
        while (count--) {
            result += symbol; // Append the entire symbol
        }
    }
    return result;
}
};