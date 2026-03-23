// EXTRA

// https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/

#include<bits/stdc++.h>
using namespace std;

// greedy try 1 : 



class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        /*
        // modify the matrix on the basis of number of consecutive ones in each column
        // sort in descending order according to consectuive num of ones
        for each row : 
            iterate over each column and expand the area keeping track of maximal area
        */ 

        int m = matrix.size();
        int n = matrix[0].size();

        for ( int j=0; j<n; j++ ) {
            int maxi=0, cnt=0;
            for ( int i=0; i<m; i++ ) {
                while (i<m && matrix[i][j] == 1 ) {
                    cnt++;
                    matrix[i][j] = cnt;
                    // cout << "matrix[i][j] : "  << matrix[i][j] << "\n";
                    i++;
                }
                maxi = max (maxi, cnt);
                cnt = 0;
                if ( i<m ) {
                    matrix[i][j] = 0;
                    // cout << "matrix[i][j] : "  << matrix[i][j] << "\n";
                }
            }
            // colsMax[j] = matrix[m-1][j];
            // cout << "colsMax[j] : "  << colsMax[j] << "\n";
        }


        int ans = 0;

        for ( int i=0; i<m; i++ ) {
            sort ( matrix[i].rbegin(), matrix[i].rend() );

            int maxArea = 0;
            int minLen = 1e9;

            for ( int col = 0; col < n; col++ ) {
                minLen = min (minLen, matrix[i][col]);
                maxArea = max ( maxArea, (col+1) * minLen );
            }

            ans = max (ans, maxArea);
        }

        return ans;

    }
};


// cleaner implementation

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        /*
        // modify the matrix on the basis of number of consecutive ones in each column
        // sort in descending order according to consectuive num of ones
        for each row : 
            iterate over each column and expand the area keeping track of maximal area
        */ 

        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Build heights
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] && i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int ans = 0;

        // Step 2: For each row
        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());

            for (int j = 0; j < n; j++) {
                ans = max(ans, matrix[i][j] * (j + 1));
            }
        }

        return ans;

    }
};
