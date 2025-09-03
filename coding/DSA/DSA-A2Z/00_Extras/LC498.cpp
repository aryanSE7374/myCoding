#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diagonal-traverse/

// my solution attempt : passed

class Solution {
public:

    // number of diagonals = m+n-1
    // NE move and SW move + how to switch between these moves 
    // valid indexing check
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int diagonals = m+n-1;
        vector<int> ans;

        int i=0 , j=0 ;
        for(int k=1 ; k<=diagonals ; k++){
            if( k&1 == 1 ) { // if k is odd -> NE move

                while(true){
                    if( 0<=i && i<m && 0<=j && j<n ){
                        ans.push_back(mat[i][j]);
                    }
                    // if( i-1 < 0 || j+1 > n-1 ) => out of bounds
                    if( i<1 || j>n-2 ){ // switch move
                        j++;
                        break;
                    }
                    else{
                        i--;
                        j++;
                    }
                }
                
            }
            else{ // k is even -> SW move

                while(true){
                    if( 0<=i && i<m && 0<=j && j<n ){
                        ans.push_back(mat[i][j]);
                    }
                    // if( j-1 < 0 || i+1 > m-1 ) => out of bounds
                    if( j<1 || i>m-2 ){ // switch move
                        i++;
                        break;
                    }
                    else{
                        i++;
                        j--;
                    }
                }

            }
        }

        return ans;

    }
};


// chatGPT's clean and optimal code

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d < m + n - 1; d++) {
            vector<int> diagonal;

            // starting row = max(0, d - (n - 1))
            // ending row   = min(m - 1, d)
            int rowStart = max(0, d - (n - 1));
            int rowEnd = min(m - 1, d);

            for (int i = rowStart; i <= rowEnd; i++) {
                int j = d - i;
                diagonal.push_back(mat[i][j]);
            }

            // even diagonal → reverse (NE)
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }

            ans.insert(ans.end(), diagonal.begin(), diagonal.end());
        }

        return ans;
    }
};