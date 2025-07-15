#include<bits/stdc++.h>
using namespace std;


// brute

class Solution {
public:

    // condition that nums[i][j] != -1

    void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
        // set all non-zero elements as -1 in the row i:
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }


    void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
        // set all non-zero elements as -1 in the col j:
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }


    void setZeroes(vector<vector<int>>& matrix) {
        // Set -1 for rows and cols
        // that contains 0. Don't mark any 0 as -1:

        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        // Finally, mark all -1 as 0:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
 
    }
};

// better

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {


        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns

        // int row[n] = {0}; // row array
        // int col[m] = {0}; // col array

        vector<int> row(n, 0); // row vector
        vector<int> col(m, 0); // col vector

        // Traverse the matrix:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark ith index of row wih 1:
                    row[i] = 1;

                    // mark jth index of col wih 1:
                    col[j] = 1;
                }
            }
        }

        // Finally, mark all (i, j) as 0
        // if row[i] or col[j] is marked with 1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// optimal

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {


        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns


        // vector<int> row(n, 0); // row vector -> matrix[...][0]
        // vector<int> col(m, 0); // col vector -> matrix[0][...]

        int col0 = 1;
        // step 1: Traverse the matrix and
        // mark 1st row & col accordingly:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark i-th row:
                    matrix[i][0] = 0;

                    // mark j-th column:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        //step 3: Finally mark the 1st col & then 1st row:
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};





// GPT solution

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();    // Number of rows
//         int m = matrix[0].size(); // Number of columns

//         vector<bool> rowFlag(n, false); // Track rows to set to 0
//         vector<bool> colFlag(m, false); // Track columns to set to 0

//         // First pass: Identify rows and columns that need to be zeroed
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     rowFlag[i] = true;
//                     colFlag[j] = true;
//                 }
//             }
//         }

//         // Second pass: Set rows to 0
//         for (int i = 0; i < n; i++) {
//             if (rowFlag[i]) {
//                 for (int j = 0; j < m; j++) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//         // Third pass: Set columns to 0
//         for (int j = 0; j < m; j++) {
//             if (colFlag[j]) {
//                 for (int i = 0; i < n; i++) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };