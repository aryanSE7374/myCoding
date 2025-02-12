#include <bits/stdc++.h>
using namespace std;


// floor(lower bound) in a sorted array : log(N) approach
/*
The lower bound is the smallest index, ind, where arr[ind] >= x. 
But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; //if any such index is not found

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
  

// GFG find Floor
/*
https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
*/

class Solution {
    public:
  
      int findFloor(vector<int>& arr, int k) {
          int n = arr.size();
          if(k<arr[0]){return -1;}
          else if(arr[n-1]<=k){return n-1;}
          int low=0, high=n-1;
          int ans = n;
          int mid=(low+high)/2;
          while(low<=high){
              mid=(low+high)/2;
              if(arr[mid]<=k){
                  low=mid+1;
                  ans=mid;
              }
              else{ // arr[mid]>k
                  high=mid-1;
              }
          }
          return ans;
      }
  };
