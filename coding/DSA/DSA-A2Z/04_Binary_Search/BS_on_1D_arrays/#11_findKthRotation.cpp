#include<bits/stdc++.h>
using namespace std;



// solution submitted by a GFG user
// User function template for C++
/*
class Solution {
    public:
    
      int findKRotation(vector<int> &arr) {
          int n = arr.size();
          int low = 0, high = n - 1, minPos = INT_MAX, ans = INT_MAX;
          
          while(low <= high) {
              int mid = (low + high) / 2;
              
              if(arr[low] <= arr[high]) {
                  
                  if(arr[low] <= ans)
                      minPos = low;
                  
                  break;
              }
              
              if(arr[low] <= arr[mid]) {
                  if(arr[low] < ans) {
                      ans = arr[low];
                      minPos = low; 
                  }
                  low = mid + 1;
              }
              else {
                  if(arr[mid] < ans) {
                      ans = arr[mid];
                      minPos = mid;
                  }
                  high = mid - 1;
              }
          }
          
          return minPos;
      }
  };
  
*/



// User function template for C++
class Solution {
    public:
    int findMinIndex(vector<int>& nums , int n) {
      int low=0; int high = n-1; int mid = 0;
      int mini = INT_MAX;
      int ans = n;
      while(low<=high){
          mid = (low+high)/2;
          if(nums[low]<=nums[high] && (nums[low]<=mini)){//if sorted part from low to high i.e. both left and right part sorted
                  ans=low;
          }
          else if(nums[mid]<=nums[high]){ // right sorted
              mini = min(mini,nums[mid]);
              if(nums[mid]<mini){ans=mid;}
              //search in left
              high = mid-1;
          }
          else{// left sorted
              mini = min(mini,nums[low]);
              if(nums[low]<mini){ans=mid;}
              // search in right
              low = mid+1;
          }
      }
      return ans;
  }
      int findKRotation(vector<int> &arr) {
          int n = arr.size();
          return findMinIndex(arr,n);
      }
  };



// I tried writing findMinInd
int findMinInd(vector<int>& nums) {
    int low=0; int high = nums.size()-1; int mid = 0;
    int mini = INT_MAX;
    int minInd;
    while(low<=high){
        mid = (low+high)/2;
        if(nums[low]<=nums[high]){//if sorted part from low to high i.e. both left and right part sorted
            // mini = min(mini,nums[low]); // min should be called here as well to handle edge case
            if(nums[low]<mini){
                // mini = nums[low];
                // minInd = low;
                // return minInd;
                return low;
            }
        }
        else if(nums[mid]<=nums[high]){ // right sorted
            if(nums[mid]<mini){
                mini = nums[mid];
                minInd = mid;
            }
            // mini = min(mini,nums[mid]);
            //search in left
            high = mid-1;
        }
        else{// left sorted
            if(nums[low]<mini){
                mini = nums[low];
                minInd = low;
            }
            // mini = min(mini,nums[low]);
            // search in right
            low = mid+1;
        }
    }
    return minInd;
}

// striver's soln 


int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}