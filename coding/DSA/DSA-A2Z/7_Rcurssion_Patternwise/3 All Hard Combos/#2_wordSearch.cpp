#include<bits/stdc++.h>
using namespace std;


// brute solution

// TC: O(N * M * 4^L)
//      where N x M is board size, L = length of word
// SC: O(L) recursion stack

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                    dfs(board, word, i - 1, j, idx + 1) ||
                    dfs(board, word, i, j + 1, idx + 1) ||
                    dfs(board, word, i, j - 1, idx + 1);

        board[i][j] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
         // code here
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimized solution with pruning

class Solution {
public:
    // Step 1: Pruning using frequency count
    bool canFormWord(vector<vector<char>>& board, string& word) {
        unordered_map<char, int> boardFreq, wordFreq;

        for (auto& row : board)
            for (char c : row)
                boardFreq[c]++;

        for (char c : word)
            wordFreq[c]++;

        for (auto& [ch, count] : wordFreq)
            if (boardFreq[ch] < count)
                return false;

        return true;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;

        int m = board.size(), n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        board[i][j] = temp;  // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (!canFormWord(board, word)) return false;  // Early pruning

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;

        return false;
    }
};