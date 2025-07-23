#include<bits/stdc++.h>
using namespace std;


// 1

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char , int> frequency;
        for(char c : s){
            frequency[c]++;
        }
        for(char c : t){
            frequency[c]--;
        }
        for(auto it : frequency){
            if(it.second > 0) return it.first;
        }
        return ' ';

    }
};

// 2 : better with early pruning

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char , int> frequency;
        for(char c : s){
            frequency[c]++;
        }
        for(char c : t){
            if(--frequency[c] < 0){return c;}
            // frequency[c]--;
        }
        return ' ';
    }
};

// optimal solution using bit maniulation

// TC: O(n), SC: O(1)
char findTheDifference(string s, string t) {
    char result = 0;
    for (char c : s) result ^= c;
    for (char c : t) result ^= c;
    return result;
}