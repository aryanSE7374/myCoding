// brute

// class Solution {
// public:

//     // condition that nums[i][j] != -1

//     void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//         // set all non-zero elements as -1 in the row i:
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }


//     void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//         // set all non-zero elements as -1 in the col j:
//         for (int i = 0; i < n; i++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }


//     void setZeroes(vector<vector<int>>& matrix) {
//         // Set -1 for rows and cols
//         // that contains 0. Don't mark any 0 as -1:

//         int n = matrix.size();    // Number of rows
//         int m = matrix[0].size(); // Number of columns

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     markRow(matrix, n, m, i);
//                     markCol(matrix, n, m, j);
//                 }
//             }
//         }

//         // Finally, mark all -1 as 0:
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == -1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
 
//     }
// };