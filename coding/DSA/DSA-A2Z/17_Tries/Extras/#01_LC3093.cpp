#include <bits/stdc++.h>
using namespace std;

// class Node {
// public:

//     Node* links[26];

//     // stores best answer index
//     int bestIndex;

//     Node() {

//         for(int i=0; i<26; i++) {
//             links[i] = NULL;
//         }

//         bestIndex = -1;
//     }

//     bool containsKey(char ch) {
//         return links[ch - 'a'] != NULL;
//     }

//     Node* get(char ch) {
//         return links[ch - 'a'];
//     }

//     void put(char ch, Node* node) {
//         links[ch - 'a'] = node;
//     }
// };

// class Trie {

// private:
//     Node* root;

// public:

//     vector<string>* words;

//     Trie(vector<string>& wordsContainer) {

//         root = new Node();

//         words = &wordsContainer;
//     }

//     // checks whether new word is better
//     bool isBetter(int newIdx, int oldIdx) {

//         if(oldIdx == -1) {
//             return true;
//         }

//         string& newWord = (*words)[newIdx];
//         string& oldWord = (*words)[oldIdx];

//         // smaller length preferred
//         if(newWord.size() < oldWord.size()) {
//             return true;
//         }

//         // earlier index preferred
//         if(newWord.size() == oldWord.size()
//             && newIdx < oldIdx) {
//             return true;
//         }

//         return false;
//     }

//     void insert(string word, int idx) {

//         reverse(word.begin(), word.end());

//         Node* node = root;

//         // update root also
//         if(isBetter(idx, root->bestIndex)) {
//             root->bestIndex = idx;
//         }

//         for(char ch : word) {

//             if(!node->containsKey(ch)) {
//                 node->put(ch, new Node());
//             }

//             node = node->get(ch);

//             // update best index
//             if(isBetter(idx, node->bestIndex)) {
//                 node->bestIndex = idx;
//             }
//         }
//     }

//     int search(string query) {

//         reverse(query.begin(), query.end());

//         Node* node = root;

//         for(char ch : query) {

//             if(!node->containsKey(ch)) {
//                 break;
//             }

//             node = node->get(ch);
//         }

//         return node->bestIndex;
//     }
// };

// class Solution {
// public:

//     vector<int> stringIndices(
//         vector<string>& wordsContainer,
//         vector<string>& wordsQuery
//     ) {

//         Trie trie(wordsContainer);

//         // insert all words
//         for(int i=0; i<wordsContainer.size(); i++) {
//             trie.insert(wordsContainer[i], i);
//         }

//         vector<int> ans;

//         for(string& query : wordsQuery) {
//             ans.push_back(
//                 trie.search(query)
//             );
//         }

//         return ans;
//     }
// };


class Node {
public:
    // Store indices instead of pointers to save memory
    int links[26];
    int bestIndex;

    Node() {
        for(int i=0; i<26; i++) {
            links[i] = -1; // -1 represents NULL / no child
        }
        bestIndex = -1;
    }
};

class Trie {
private:
    vector<Node> trie;

public:
    vector<string>* words;

    Trie(vector<string>& wordsContainer) {
        // Initialize the vector with the root node at index 0
        trie.push_back(Node()); 
        words = &wordsContainer;
    }

    bool isBetter(int newIdx, int oldIdx) {
        // Your logic here remains exactly the same!
        if(oldIdx == -1) {
            return true;
        }

        string& newWord = (*words)[newIdx];
        string& oldWord = (*words)[oldIdx];

        if(newWord.size() < oldWord.size()) {
            return true;
        }

        if(newWord.size() == oldWord.size() && newIdx < oldIdx) {
            return true;
        }

        return false;
    }

    void insert(string word, int idx) {
        reverse(word.begin(), word.end());
        int curr = 0; // Start at root (index 0)

        // update root also
        if(isBetter(idx, trie[curr].bestIndex)) {
            trie[curr].bestIndex = idx;
        }

        for(char ch : word) {
            if(trie[curr].links[ch - 'a'] == -1) {
                // Point to the next available index in the vector
                int nextIdx = trie.size();
                trie[curr].links[ch - 'a'] = nextIdx;
                trie.push_back(Node());
            }

            curr = trie[curr].links[ch - 'a'];

            // update best index
            if(isBetter(idx, trie[curr].bestIndex)) {
                trie[curr].bestIndex = idx;
            }
        }
    }

    int search(string query) {
        reverse(query.begin(), query.end());
        int curr = 0; // Start at root

        for(char ch : query) {
            if(trie[curr].links[ch - 'a'] == -1) {
                break; // Stop if child doesn't exist
            }
            curr = trie[curr].links[ch - 'a'];
        }

        return trie[curr].bestIndex;
    }
};

class Solution {
public:

    vector<int> stringIndices(
        vector<string>& wordsContainer,
        vector<string>& wordsQuery
    ) {

        Trie trie(wordsContainer);

        // insert all words
        for(int i=0; i<wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(string& query : wordsQuery) {
            ans.push_back(
                trie.search(query)
            );
        }

        return ans;
    }
};