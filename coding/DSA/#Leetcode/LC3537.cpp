// my solution TC : O(n*m)

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> specialGrid(int n) {
            int r = 1<<n ; // power(2,n)
            int c = r;
            vector<vector<int>> mat(r , vector<int>(c));
            if(n==0){
                mat[0][0]=0;
                return mat;
            }
            
            int i=0 , j=c-1 , num = 0;
            fillquad(mat , i , j , num , n);
            return mat;
            
        }
        void fillquad(vector<vector<int>> &mat , int i , int j , int &num , int qn ){
            // base case 
            if(qn==1){
                mat[i][j] = num;
                i++;
                mat[i][j] = num+1;
                j--;
                mat[i][j] = num+2;
                i--;
                mat[i][j] = num+3;
                
                num += 4; // add &num in parameters
    
                return;
            }
            fillquad(mat , i , j , num , qn-1);
            i = i + (1<<(qn-1));
            fillquad(mat , i , j , num , qn-1);
            j = j - (1<<(qn-1));
            fillquad(mat , i , j , num , qn-1);
            i = i - (1<<(qn-1));
            fillquad(mat , i , j , num , qn-1);
        }
    };