#include<bits/stdc++.h>
using namespace std;

// Sol 1 : O(2^N)
// SC : O(N) => recursion depth only


class Solution {
  public:
    bool f(int idx , int sum , int n, vector<int>& arr, int k){
      // optimization
      if(sum>k){return false;}
      
      // base case
      if(idx == n){
          if(sum == k){return true;}
          else return false;
      }

      // left case : include element
      sum+=arr[idx];
      if(f(idx+1 , sum , n , arr , k)){return true;}
      //right case : exclude element
      sum-=arr[idx];
      if(f(idx+1 , sum , n , arr , k)){return true;}

      // finally return false i.e. no sub seq found in that particular branch
      return false;

    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return f( 0 , 0 , n , arr , k);
    }
};

// expected TC : O(N*K) -> DP track
// solution passed on GFG

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<char> dp(k + 1, 0);  // dp[s] = 1 means sum s is achievable
        dp[0] = 1;  // sum 0 is always achievable (empty subset)

        for (int x : arr) {
            for (int s = k; s >= x; --s) {
                dp[s] |= dp[s - x];
            }
        }

        return dp[k];  // return true if sum k is possible
    }
};