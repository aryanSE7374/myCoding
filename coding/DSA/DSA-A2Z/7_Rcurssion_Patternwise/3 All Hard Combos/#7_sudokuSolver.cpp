#include <bits/stdc++.h>
using namespace std;


// striver's solution (Efficient backtracking)

//  Total TC: O(9^M × 9) = O(9^(M+1)), but dominated by exponential backtracking.
// SC: O(1) (excluding recursion stack)  
// Reason: No extra space apart from the board (in-place).  
// Recursion stack depth: O(M) where M = number of empty cells → so  
// **Total SC: O(M)** due to recursion.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// brute
// TC: O(9 ^ (NumberOfEmptyCells))

// TC: O(9^M × 81 × 9)
// 9^M = number of ways to fill M empty cells
// isBoardValid() runs in O(81 × 9) = O(729) each time you place a number

// Total SC: O(M)

class Solution {
public:
    // Check full board validity every time
    bool isBoardValid(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row, col, box;
            for (int j = 0; j < 9; ++j) {
                // Row check
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }

                // Column check
                if (board[j][i] != '.') {
                    if (col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }

                // 3x3 box check
                int rowStart = 3 * (i / 3), colStart = 3 * (i % 3);
                int r = rowStart + j / 3;
                int c = colStart + j % 3;
                if (board[r][c] != '.') {
                    if (box.count(board[r][c])) return false;
                    box.insert(board[r][c]);
                }
            }
        }
        return true;
    }

    bool bruteSolve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        board[i][j] = c;
                        if (isBoardValid(board) && bruteSolve(board)) return true;
                        board[i][j] = '.'; // backtrack
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bruteSolve(board);
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// chatGPT optimal solution

// TC: O(9^M) 
// SC: O(M)

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false; // check col
            if (board[row][i] == c) return false; // check row
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false; // check 3x3 box
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number fits
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 