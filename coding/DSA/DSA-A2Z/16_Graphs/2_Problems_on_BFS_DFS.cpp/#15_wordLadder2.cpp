#include<bits/stdc++.h>
using namespace std;

// GFG version - my brute force try passed on GFG , TLE on LC

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList , unordered_set<string> st) {

        int w = beginWord.size();
        queue<pair<string,int>> q;
        q.push( {beginWord,1} );
        st.erase(beginWord);
        
        while( !q.empty() ) {
            
            auto [curr,lvl] = q.front();
            q.pop();
            if ( curr == endWord ) {
                return lvl;
            }
            
            for ( int i=0 ; i<w ; i++ ) {
                for ( int j=0 ; j<26 ; j++ ) {
                    string temp = curr;
                    temp[i] = 'a'+j;
                    if ( st.find(temp) != st.end() ) {
                        st.erase(temp);
                        q.push({temp,lvl+1});
                    }
                }
            }
            
        }
        return 0;
    }
    
    void f ( string start , string& end , int& w , unordered_set<string> st, int lvl , int& minLen , vector<string> path, vector<vector<string>>& ans ) {
        
        if ( lvl >= minLen ) {
            if ( start == end ) {
                ans.push_back(path);
            }
            return;
        }
        
        for ( int i=0 ; i<w ; i++ ) {
            for ( char c = 'a' ; c<= 'z' ; c++ ) {
                string temp = start;
                temp[i] = c;
                if ( st.find(temp) != st.end() ) {
                    path.push_back(temp);
                    st.erase(temp);
                    // recurse
                    f( temp , end , w , st , lvl+1 , minLen , path , ans );
                    // backtrack
                    st.insert(temp);
                    path.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        
        
        int w = beginWord.size();
        unordered_set<string> st(wordList.begin() , wordList.end() );
        int minLen = ladderLength(beginWord , endWord , wordList , st);
        vector<vector<string>> ans;
        vector<string> path = {beginWord};
        st.erase(beginWord);
        
        f ( beginWord , endWord , w , st , 1 , minLen , path , ans );
        
        return ans;
        
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------- //


// striver's better solution : pass on GFG, MLE on leetcode

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        
        // If endWord is not present, no transformation possible
        if(st.find(endWord) == st.end()) return ans;
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<string> usedOnLevel; // mark used on current level to be deleted on reaching the next level
        usedOnLevel.push_back(beginWord);
        
        int level = 0;
        
        while(!q.empty()) {
            
            vector<string> vec = q.front();
            q.pop();
            
            // If we moved to next level
            if(vec.size() > level) {
                level++;
                
                // Erase all words used in previous level
                for(auto &word : usedOnLevel) {
                    st.erase(word);
                }
                usedOnLevel.clear();
            }
            
            string word = vec.back(); // curr word to be transformed
            
            // If we reached endWord
            if(word == endWord) {
                if(ans.size() == 0) {
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            
            // Try all possible transformations
            for(int i = 0; i < word.size(); i++) {
                
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                
                word[i] = original;
            }
        }
        
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------- //

// optimized solution for leetcode : BFS + DFS (reversed & optimal)

class Solution{
    
    unordered_map<string , int> mpp;   // stores level (distance from beginWord)
    vector<vector<string>> ans;       // stores final sequences
    string b;                         // beginWord

private:
    
    void dfs(string word, vector<string> &seq) {
        
        // If we reached beginWord
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = mpp[word];
        int sz = word.size();
        
        for(int i = 0; i < sz; i++) {
            char original = word[i];
            
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // Check if this word exists in map
                // and is exactly one level before
                if(mpp.find(word) != mpp.end() 
                   && mpp[word] + 1 == steps) {
                    
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            
            word[i] = original;
        }
    }

public:
    
    vector<vector<string>> findLadders(string beginWord, 
                                       string endWord, 
                                       vector<string> &wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        
        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        
        int sizee = beginWord.size();
        st.erase(beginWord);
        
        // ---------------- BFS ----------------
        while(!q.empty()) {
            
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            if(word == endWord) break;
            
            for(int i = 0; i < sizee; i++) {
                
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    
                    word[i] = ch;
                    
                    if(st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                
                word[i] = original;
            }
        }
        
        // ---------------- DFS ----------------
        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};


// -------------------------------------------------------------------------------------------------------------------------------------------------------------- //