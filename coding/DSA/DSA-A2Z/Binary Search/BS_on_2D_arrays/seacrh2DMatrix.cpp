#include <bits/stdc++.h>
using namespace std;


// brute : TC =  O(m*n)

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<m ; j++){
                    if(matrix[i][j]==target) return true;
                }
            }
            return false;
        }
    };


// optimal try 1 : 

// TC : O(log(m)+log(n)) = O(log(m*n))

class Solution {
    public:
        bool binarySearch(vector<int>& arr , int target){
            int n = arr.size();
            int low=0 , high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                // if(matrix[mid][0]==target){return true;}
                if(arr[mid]==target){return true;}
                if(arr[mid]<target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return false;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();

            int low=0 , high = n-1;
            int mid = (low+high)/2;
            while(low<=high){
                mid = (low+high)/2;
                // if(matrix[mid][0]==target){return true;}
                if(matrix[mid][0]<=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            int curr_mid = (low+high)/2;
            if(mid>curr_mid){
                return binarySearch(matrix[curr_mid] , target);
            }
            else{
                return binarySearch(matrix[mid] , target);
            }
        }
    };

// striver's solution
// TC :  O(log(m*n))

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
            int low = 0 , high = m*n - 1;
            while (low<=high)
            {
                int mid = (low+high)/2;
                int row = mid/n;
                int col = mid%n;
                if(matrix[row][col]==target){return true;}
                else if(matrix[row][col] < target){
                    low = mid+1;
                }
                else{// matrix[row][col] > target
                    high = mid-1;    
                }
            }
            return false;   
        }
    };