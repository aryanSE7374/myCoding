#include<bits/stdc++.h>
using namespace std;

// 90 degrees clockwise -- for anti clockwise : step 1: same, step 2 : rotate every column
    void rotate(vector < vector < int >> & matrix) {
        int n = matrix.size();
        //transposing the matrix
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
        }
    }

class Solution {
public:

    
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // int l=x , h=x+k-1;
        // while(l<=h){
        //     for(int j=y ; j<y+k ; j++){
        //         swap(grid[l][j] , grid[h][j]);
        //     }
        // }
        vector<vector<int>> res(k, vector<int>(k));
        for(int i=x+k-1 ; i>=x ; i--){
            for(int j=y ; j<y+k ; j++){
                res[x-k+1-i][j-y] = grid[i][j];
        }
        
    }
    return res;
}};

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> res(k, vector<int>(k));

        for (int i = x + k - 1; i >= x; i--) {
            for (int j = y; j < y + k; j++) {
                res[(x + k - 1) - i][j - y] = grid[i][j];
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int t = x, b = x + k - 1;

        // swap rows 
        
        while (t < b) {
            for (int col = y; col < y + k; col++) {
                swap(grid[t][col], grid[b][col]);
            }
            t++;
            b--;
        }

        return grid;
    }
};