#include<bits/stdc++.h>
using namespace std;

// Function to find square root
// x: element to find square root
// class Solution {
//     public:
//       int floorSqrt(int n) {
//           // Your code goes here
//           int i = 1;
//           while(i*i<=n){
//               i++;
//           }
//           return i-1;
//       }
//   };


// using binary search
class Solution {
    public:
      int floorSqrt(int n) {
          // Your code goes here
          int low = 1;
          int high = n;
          int ans;
          while(low<=high){
            int mid = (low + high)/2;
            if(mid*mid==n){return mid;}
            else if(mid*mid<n){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
          }
          return ans;
      }
  };
