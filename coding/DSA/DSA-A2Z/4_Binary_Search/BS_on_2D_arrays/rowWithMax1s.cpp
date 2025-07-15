#include <bits/stdc++.h>
using namespace std;

// brute force

/*
Time Complexity: O(n X m), where n = given row number, m = given column number.
Reason: We are using nested loops running for n and m times respectively.
Space Complexity: O(1) as we are not using any extra space.
*/

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        // count no. of ones in the row
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


/*
optimal approach :- find :
lowerBound(1) (ref: Implement Lower Bound)
upperBound(0) (ref: Implement Upper Bound)
firstOccurrence(1) (ref: First and Last Occurrences in Array)

TC : o(N*log(N))
*/ 


class Solution {
    public:   
    int lowerBound(vector<int> arr, int n, int x) {
          int low = 0, high = n - 1;
          int ans = n;
      
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
    int rowWithMax1s(vector < vector < int >> & mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt_max = 0;
        int index = -1;
        
        //traverse the rows:
        for (int i = 0; i < n; i++) {
            // get the number of 1's:
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
  };
