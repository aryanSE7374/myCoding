#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    
    void dfs ( vector<vector<int>>& image , int i, int j, int clr , int newClr ) {
        
        int n = image.size();
        int m = image[0].size();
        
        image[i][j] = newClr;
        
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        for ( int k=0 ; k<4 ; k++ ) {
            
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if ( 
                0<=ni && ni<n && 0<=nj && nj < m &&
                image[ni][nj] == clr && image[ni][nj] != newClr 
            ) {
                dfs ( image , ni , nj , clr , newClr );
            }
            
        }
        
    }
      
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        vector<vector<int>> cpy = image;
        
        dfs ( cpy , sr , sc , image[sr][sc] , newColor ); 
        
        return cpy;
        
    }
};