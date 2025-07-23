#include<bits/stdc++.h>
using namespace std;

// returns -1 if x^m < m
// returns 0 if x^m = m
// returns 1 if x^m > m

int compare_nth_root(int n , int m , int x){
    long long ans = 1;
    for(int i=0 ; i<n ; i++){//loop to calculate x^n
        ans*=x;
        if(ans>m){return 1;}
    }
    if(ans==m){return 0;}
    return -1;
}

class Solution {
    public:
      // to find nth root of m
      int nthRoot(int n, int m) {
          // Your code goes here
          int low = 1;
          int high = m;
          while(low<=high){
            int mid = (low + high)/2;
            int compare_nth = compare_nth_root(n , m , mid);
            if(compare_nth==0){return mid;}
            else if(compare_nth<0){low = mid+1;}
            else{high = mid-1;}
          }
          return -1;
      }
  };