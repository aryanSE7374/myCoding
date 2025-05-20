#include<bits/stdc++.h>
using namespace std;

// my brute try

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char , int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        // Sort the vector by the second element (value) in ascending order
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second; // For ascending, use `a.second < b.second`
        });
        for(auto it : vec){
            for(int i=0 ; i<it.second ; i++){
                res+=it.first;
            }
        }
        return res;
    }
};