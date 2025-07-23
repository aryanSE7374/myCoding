#include<bits/stdc++.h>
using namespace std;


// striver's brute solution w/o hashing

// TC : O(N!) × O(N)
// SC : O(N²)

class Solution {
public:

    bool isSafe(int row , int col , vector<string>& board , int n){
        // you only need to check 3 of the 8 directions : N-W , W & S-W
        // N , S : eliminated because we can only place one queen in a column as per our assumptions
        // N-E , E & S-E : elmiminated because we haven't placed the queen in the succeding columns yet

        int dupRow = row;
        int dupCol = col;

        // check for N-W direction
        while (row>=0 && col>=0)
        {
            if(board[row][col] == 'Q'){return false;}
            row--;
            col--;
        }
        row = dupRow;
        col  = dupCol;

        // check for W direction
        while (col>=0)
        {
            if(board[row][col] == 'Q'){return false;}
            col--;
        }
        row = dupRow;
        col  = dupCol;

        // check for S-W direction
        while (row<n && col>=0)
        {
            if(board[row][col] == 'Q'){return false;}
            row++;
            col--;
        }

        return true;

    }

    void solve(int col , vector<string>& board , vector<vector<string>>& ans , int n ){

        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0 ; row<n ; row++){
            if(isSafe(row , col , board , n)){

                // place the queen at the safe place
                board[row][col] = 'Q';
                // call for the next col
                solve(col+1 , board , ans , n);

                // backtrack when returned : erase the Queen placed above
                board[row][col] = '.';

            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // board creation
        vector<string> board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++){
            board[i] = s;
        }

        solve(0 , board , ans , n);
        return ans;

    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 

// optimized solution using hashing

// TC : O(N!)
// SC : O(N)

class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {

        // base case

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            // silght optimization with hash table instead of isSafe
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {

                // place the queen at the safe place
                board[row][col] = 'Q';

                // maintain the hashtable
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // call for the next col
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // backtrack when returned : erase the Queen placed above
                board[row][col] = '.';

                // backtracked hashtable
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;

        // board creation
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        // hashtable creation
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

        return ans;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 