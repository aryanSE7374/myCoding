#include<bits/stdc++.h>
using namespace std;



// brtue : O(n^3) 

string minWindow(string S, string T) {
    int n = S.size(), m = T.size();
    int minLen = INT_MAX, start = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // check if S[i..j] contains T as subsequence
            int ti = 0;
            for (int k = i; k <= j; k++) {
                if (S[k] == T[ti]) ti++;
                if (ti == m) break;
            }
            if (ti == m && j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
        }
    }
    return start == -1 ? "" : S.substr(start, minLen);
}


// chatGPT better solution - 1 using 2 ptrs 

string minWindow(string S, string T) {
    int n = S.size(), m = T.size();
    int minLen = INT_MAX, start = -1;
    int r = 0, idx = 0; // r -> pointer in S, idx -> pointer in T

    while (r < n) {
        if (S[r] == T[idx]) {
            idx++;
            if (idx == m) { // found full subsequence T inside S
                int end = r;  // last position of subsequence
                idx--;        // move T pointer to last char
                int l = r;    // l moves backward to find smallest window
                while (idx >= 0) {
                    if (S[l] == T[idx]) idx--;
                    l--;
                }
                l++; // move to start of window

                if (end - l + 1 < minLen) {
                    minLen = end - l + 1;
                    start = l;
                }

                // restart search after the start of this window
                r = l;
                idx = 0;
            }
        }
        r++;
    }
    return start == -1 ? "" : S.substr(start, minLen);
}




/*
// try

string minWindow(string s, string t){
    int n = s.size() , m = t.size();
    int freq[256] = {0};
    for(char c : t){
        freq[c]++;
    }
    int l=0 , r=0 , minLen=INT_MAX  , sIndex = -1;
    int idx = 0;

    while(r<n){
        // if(freq[s[r]]>0){count++;}
        freq[s[r]]--;
        if(s[r]==t[idx]){
            idx++;
        }
        while(idx == m && freq[t[0]]<=0){
            if(r-l+1 < minLen ){
                minLen = r-l+1;
                sIndex = l;
            }
            freq[s[l]]++;
            if(freq[t[0]]>0){
                // count--;
                idx = 0;
                for(char c : t){
                    freq[c]=1;
                }
                l = l+(r-l+1); // l++ also wont work
                r=l-1;
                break;
            }
            l++;
        }
        r++;
    }
    return sIndex==-1 ? "" : s.substr(sIndex , minLen);
}


// corrected version of better - 2 : correct


string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    int minLen = INT_MAX, startIdx = -1;
    int r = 0; 

    while (r < n) {
        int idx = 0;

        // Step 1: expand forward until we match the whole subsequence t
        while (r < n && idx < m) {
            if (s[r] == t[idx]) idx++;
            r++;
        }

        // no full match -> stop
        if (idx < m) break;

        // Step 2: shrink from the end of match
        int end = r;       // one past subsequence end
        idx = m - 1;
        int l = r - 1;
        while (l >= 0 && idx >= 0) {
            if (s[l] == t[idx]) idx--;
            l--;
        }
        l++; // now l is the first char of this minimal subsequence

        // Step 3: update best answer
        if (end - l < minLen) {
            minLen = end - l;
            startIdx = l;
        }

        // Step 4: continue search *right after the start*
        r = l + 1;  // don't skip over possible overlapping subsequences
    }

    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
}


// more optimal solution uses DP
*/