#include<bits/stdc++.h>
using namespace std;


// GFG vaiation

// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1


// my sol : submitted
// •	Time Complexity: O(Q * N) (for each query, scan the suffix of array)
// •	Space Complexity: O(Q) (to store results)

class Solution {
  public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> res(queries , 0);
        for(int i=0 ; i<queries ; i++){
          int count = 0;
          for(int j = indices[i] ; j< n ; j++){
            if(arr[j]>arr[indices[i]]){count++;}
          }
          res[i] = count;
        }
        return res;
    }
};

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// better

// Time: O(N^2) for precomputation + O(Q)
// Space: O(N) for NGE counts + O(Q) for results

class Solution {
  public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> ngeCount(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    ngeCount[i]++;
                }
            }
        }
        
        vector<int> res(queries);
        for (int i = 0; i < queries; i++) {
            res[i] = ngeCount[indices[i]];
        }
        return res;
    }
};


// ------------------------------------------------------------------------------------------------------------------------------------ // 


//Optimal Approach (Using Monotonic Stack)

/*
Idea:
	•	Traverse array from right to left using a monotonic stack to maintain greater elements.
	•	For each index, count how many elements in the stack are greater than the current one.
	•	Store those counts in a precomputed array.
	•	Finally, answer each query in O(1).
*/

// Time: O(N + Q)
// Space: O(N + Q)

// ** WRONG SOLUTION ** // 

// No more optimizations


// ------------------------------------------------------------------------------------------------------------------------------------ // 
