#include<bits/stdc++.h>
using namespace std;



// try 1. : WRONG

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.size();
        int v2 = version2.size();

        vector<int> tokens1;
        vector<int> tokens2;

        // int temp = 0;
        // int d = 1;
        string temp = "";
        for(int i=0 ; i<v1 ; i++){
            if(version1[i]=='.'){
                tokens1.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp+=version1[i];
            }
        }
        tokens1.push_back(stoi(temp));

        temp = "";
        for(int i=0 ; i<v2 ; i++){
            if(version2[i]=='.'){
                tokens2.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp+=version2[i];
            }
        }
        tokens2.push_back(stoi(temp));

        int p1 = tokens1.size()-1;
        int p2 = tokens2.size()-1;

        bool nonZeroFlag1 = false;
        bool nonZeroFlag2 = false;

        while(p1>=0 && !nonZeroFlag1){
            p1--;
        }
        while(p2>=0 && !nonZeroFlag2){
            p2--;
        }

        if(p1<0 && p2>=0){
            return -1;
        }
        else if(p2<0 && p1>=0){
            return 1;
        }
        else if(p1<0 && p2<0){
            return 0;
        }

        int k = min(p1, p2);
        for(int i=0 ; i<k ; i++){
            if(tokens1[i]>tokens2[i]){
                return 1;
            }
            else if(tokens1[i]<tokens2[i]){
                return -1;
            }
        }

        if(p1>p2){
            return 1;
        }
        else if(p1<p2){
            return -1;
        }
        else{
            return 0;
        }
        
        // return 0;
    }
};

// ----------------------------------------------------------------- //

// try 1 (fixed with comments) : correct

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = version1.size();
        int v2 = version2.size();

        vector<int> tokens1;
        vector<int> tokens2;

        string temp = "";
        for(int i=0 ; i<v1 ; i++){
            if(version1[i]=='.'){
                tokens1.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp+=version1[i];
            }
        }
        tokens1.push_back(stoi(temp));

        temp = "";
        for(int i=0 ; i<v2 ; i++){
            if(version2[i]=='.'){
                tokens2.push_back(stoi(temp));
                temp = "";
            }
            else{
                temp+=version2[i];
            }
        }
        tokens2.push_back(stoi(temp));

        // CHANGE 1: remove trailing zeros properly
        while(!tokens1.empty() && tokens1.back() == 0) tokens1.pop_back();
        while(!tokens2.empty() && tokens2.back() == 0) tokens2.pop_back();

        // CHANGE 2: remove unused variables (p1, p2, flags)
        // int p1 = tokens1.size()-1;
        // int p2 = tokens2.size()-1;
        // bool nonZeroFlag1 = false;
        // bool nonZeroFlag2 = false;

        // CHANGE 3: compare using padded values
        int n = max(tokens1.size(), tokens2.size());
        for(int i=0 ; i<n ; i++){
            int a = (i < tokens1.size() ? tokens1[i] : 0);
            int b = (i < tokens2.size() ? tokens2[i] : 0);

            if(a > b) return 1;
            if(a < b) return -1;
        }

        // CHANGE 4: final result simplified
        return 0;
    }
};


// ----------------------------------------------------------------- //

// GPT

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> tokens1, tokens2;

        // Parse version1
        string temp = "";
        for (char c : version1) {
            if (c == '.') {
                tokens1.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        tokens1.push_back(stoi(temp));

        // Parse version2
        temp = "";
        for (char c : version2) {
            if (c == '.') {
                tokens2.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }
        tokens2.push_back(stoi(temp));

        // Make lengths equal by padding zeros
        int n1 = tokens1.size(), n2 = tokens2.size();
        if (n1 < n2) tokens1.resize(n2, 0);
        else if (n2 < n1) tokens2.resize(n1, 0);

        // Compare token by token
        for (int i = 0; i < tokens1.size(); i++) {
            if (tokens1[i] > tokens2[i]) return 1;
            else if (tokens1[i] < tokens2[i]) return -1;
        }

        return 0;
    }
};

// ----------------------------------------------------------------- //