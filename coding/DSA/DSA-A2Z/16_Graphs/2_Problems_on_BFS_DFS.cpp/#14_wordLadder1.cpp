#include<bits/stdc++.h>
using namespace std;

// my code - accepted
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st;
        int w = beginWord.size();
        
        for ( string word : wordList ) {
            st.insert(word);
        }
        
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
};

// ------------------------------------------------------------------------------------------------------- //

// striver's better code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present, transformation is impossible
        if (st.find(endWord) == st.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Remove beginWord if present (to prevent revisiting)
        st.erase(beginWord);

        while (!q.empty()) {

            auto [curr, level] = q.front();
            q.pop();

            // If target reached, return level
            if (curr == endWord)
                return level;

            // Try all possible one-letter transformations
            for (int i = 0; i < curr.size(); i++) {

                string temp = curr;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (st.find(temp) != st.end()) {
                        q.push({temp, level + 1});
                        st.erase(temp);  // mark visited
                    }
                }
            }
        }

        return 0;  // No transformation sequence found
    }
};


// ------------------------------------------------------------------------------------------------------- //
