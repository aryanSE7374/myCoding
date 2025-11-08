// https://leetcode.com/problems/reorganize-string/

#include<bits/stdc++.h>
using namespace std;


// brute try : TLE

// TC : O(n! * n)         // generating all permutations (n!) and checking each (O(n))
// SC : O(n)              // storing one permutation at a time + recursion/next_permutation overhead

class Solution {
public:

    bool checkAlternative(string& s , int n){
        for(int i=0 ; i<n-1 ; i++){
            if(s[i]==s[i+1]) return false;
        }
        return true;
    }

    string reorganizeString(string s) {

        int n = s.size();
        string temp = s;

        // string res(n,'a');
        // int maxf = 0;
        // vector<int> freq(26);
        // for(char c : s){
        //     freq[c - 'a']++;
        //     maxf = max(maxf , freq[c-'a']);
        // }

        // optimization for not possible edge case
        // if( n < (2*maxf - 1) ){
        //     return "";
        // }

        // generate first permutation

        // method 1
        // int i=0;
        // for(int j=0 ; j<26 ; j++){
        //     for(int k=0 ; k<freq[j] ; k++){
        //         temp[i++] = 'a'+j;
        //     }
        // }

        // method 2

        sort(temp.begin() , temp.end());

        do {
            if(checkAlternative(temp , n)) return temp;
        } while (next_permutation(temp.begin(), temp.end()));

        return "";

    }
};

// ---------------------------------------------------------------- //

// my better try 1 : passed

// TC : O(n + 26 * log(26)) ≈ O(n)   // single pass for frequency + sorted placement (constant 26 letters)
// SC : O(26) ≈ O(1)                 // frequency array + result string of size n (output not counted)

class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();

        string res(n,'a');

        int maxf = 0;
        int maxfidx = 0;

        vector<int> freq(26);

        for(int i=0 ; i<n ; i++){

            freq[s[i] - 'a']++;

            if(freq[s[i]-'a'] > maxf){

                maxf = max(maxf , freq[s[i]-'a']);
                maxfidx = s[i]-'a';

            }

        }
        
        if( n < (2*maxf - 1) ){

            return "";

        }
        else{

            int p=0;
            bool oddFlag = true;

            for(int j=0 ; j<maxf ; j++){

                res[p] = 'a'+maxfidx;
                p+=2;

                if(oddFlag){

                    if(p>=n){

                        oddFlag = false;
                        p=1;

                    }

                }

            }

            freq[maxfidx] = 0;

            for(int i=0 ; i<26 ; i++){

                if(i==maxfidx) continue;

                for(int j=0 ; j<freq[i] ; j++){

                    res[p] = 'a'+i;
                    p+=2;

                    if(oddFlag){

                        if(p>=n){

                            oddFlag = false;
                            p=1;

                        }
                    }
                }    
            }   
        }

        return res;
    }
};

// ---------------------------------------------------------------- //

// chatGPT refined better version 

// TC : O(n + 26 * log(26)) ≈ O(n)   // single pass for frequency + sorted placement (constant 26 letters)
// SC : O(26) ≈ O(1)                 // frequency array + result string of size n (output not counted)

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string res(n, 'a');
        vector<int> freq(26, 0);

        // ✅ Count frequencies and track the most frequent character
        int maxf = 0, maxfidx = 0;
        for (char c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > maxf) {
                maxf = freq[c - 'a'];
                maxfidx = c - 'a';
            }
        }

        // ⚠️ CHANGED: Corrected feasibility condition
        // Old: if (n < (2 * maxf - 1))
        // New: if (maxf > (n + 1) / 2)
        if (maxf > (n + 1) / 2) return "";

        // ✅ Simplified index placement logic (removed oddFlag & manual checks)
        int idx = 0;

        // First, place the most frequent char at even indices
        while (freq[maxfidx] > 0) {
            if (idx >= n) idx = 1;  // wrap to odd indices when even are full
            res[idx] = 'a' + maxfidx;
            idx += 2;
            freq[maxfidx]--;
        }

        // ✅ Fill the rest of the characters
        for (int i = 0; i < 26; ++i) {
            while (freq[i] > 0) {
                if (idx >= n) idx = 1;  // wrap around again if needed
                res[idx] = 'a' + i;
                idx += 2;
                freq[i]--;
            }
        }

        return res;
    }
};


// ---------------------------------------------------------------- //

// my optimal try

// TC : O(n*  log( 26 ) ) ≈ O(n)
// SC : O(26) ≈ O(1)

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        string res(n,'a');

        int maxf = 0;
        // int maxfidx = 0;

        vector<int> freq(26);

        for(int i=0 ; i<n ; i++){

            freq[s[i] - 'a']++;

            if(freq[s[i]-'a'] > maxf){

                maxf = max(maxf , freq[s[i]-'a']);
                // maxfidx = s[i]-'a';

            }

        }

        if (maxf > (n + 1) / 2) return "";

        priority_queue< pair < int , char > > maxHeap;

        for(int i=0 ; i<26 ; i++){
            maxHeap.push( {freq[i] , 'a'+i} );
        }

        int idx = 0;

        while (!maxHeap.empty()){

            char c2 = '@';

            auto top1 = maxHeap.top();
            maxHeap.pop();

            auto top2 = top1;

            if(!maxHeap.empty()){
                top2 = maxHeap.top();
                maxHeap.pop();
                c2 = top2.first;
            }

            // if( (c2=='@') && (top1.first > n-idx) ){
            //     return "";
            // }

            res[idx++] = top1.second;

            if(c2 != '@'){
                res[idx++] = top2.second;
            }

            top1.first--;
            if(top1.first > 0){
                maxHeap.push(top1);
            }
            if(c2!='@'){
                top2.first--;
                if(top2.first > 0){
                    maxHeap.push(top2);
                }
            }

        }

        return res;

    }
};


// ---------------------------------------------------------------- //

// my optimal try

// TC : O(n*  log( 26 ) ) ≈ O(n)
// SC : O(26) ≈ O(1)

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        priority_queue<pair<int, char>> maxHeap;

        // ✅ Only push non-zero frequencies
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0)
                maxHeap.push({freq[i], 'a' + i});
        }

        string res = "";

        while (maxHeap.size() > 1) {
            // ✅ Pop two most frequent characters
            auto top1 = maxHeap.top(); maxHeap.pop();
            auto top2 = maxHeap.top(); maxHeap.pop();

            // ✅ Append them alternately
            res += top1.second;
            res += top2.second;

            // ✅ Decrement frequencies and reinsert if still left
            if (--top1.first > 0) maxHeap.push(top1);
            if (--top2.first > 0) maxHeap.push(top2);
        }

        // ✅ Handle remaining last character
        if (!maxHeap.empty()) {
            if (maxHeap.top().first > 1) return "";
            res += maxHeap.top().second;
        }

        return res;
    }
};

// ---------------------------------------------------------------- //