#include <bits/stdc++.h>
using namespace std;



// TC : O( min(m*n)*log(max(m,n)) )
// TC  : O(Min(M,N)∗Log(Max(M,N)))

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();

            int maxi = max(m,n);
            int mini = min(m,n);

            for(int i=0 ; i<mini ; i++){
                int low = 0 , high = maxi - 1;
                while (low<=high)
                {
                    int mid = (low+high)/2;
                    if(n<m){
                        if(matrix[mid][i]==target){return true;}
                        else if(matrix[mid][i] < target){
                            low = mid+1;
                        }
                        else{// matrix[mid][i] > target
                            high = mid-1;    
                        }
                    }else{
                        if(matrix[i][mid]==target){return true;}
                        else if(matrix[i][mid] < target){
                            low = mid+1;
                        }
                        else{// matrix[i][mid] > target
                            high = mid-1;    
                        }
                    }
                }
            }
            return false;   
        }
    };



// optimal solution : O(m+n) -> linear 
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
            int row = 0; 
            int col = n-1;
            while(row<m && col >=0){
                if(matrix[row][col]==target){return true;}
                else if(matrix[row][col]<target){row++;}
                else{col--;}
            }
            return false;
        }
    };

