#include<bits/stdc++.h>
using namespace std;

// Function to find square root
// x: element to find square root
class Solution {
    public:
      int floorSqrt(int n) {
          // Your code goes here
          int i = 1;
          while(i*i<=n){
              i++;
          }
          return i-1;
      }
  };