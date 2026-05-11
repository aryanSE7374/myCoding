#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> closest(n);
        closest[0] = 1;
        closest[n-1] = n-2;
        
        for ( int i=1; i<n-1; i++ ) {
            closest[i] = ( (nums[i] - nums[i-1]) <= (nums[i+1] - nums[i]) ) ? (i-1) : (i+1);
        }
        
        // DP state arrays
        vector<long long> prevMax(n, 0);
        vector<long long> nextMax(n, 0);
        
        // DP Transitions: dp[i] = dp[i-1] + cost(i-1 -> i)
        for ( int i=1; i<n; i++ ) {
            prevMax[i] = prevMax[i-1] + ((closest[i-1] == i) ? 1 : (nums[i] - nums[i-1]));
        }
        
        // DP Transitions: dp[i] = dp[i+1] + cost(i+1 -> i)
        for ( int i=n-2; i>=0; i-- ) {
            nextMax[i] = nextMax[i+1] + ((closest[i+1] == i) ? 1 : (nums[i+1] - nums[i]));
        }
        
        int qsize = queries.size();
        vector<long long> ans(qsize);
        
        // queries
        for ( int i=0; i<qsize; i++ ) {
            int l = queries[i][0], r = queries[i][1];
            
            if ( l < r ) { 
                ans[i] = prevMax[r] - prevMax[l];
            }
            else { 
                ans[i] = nextMax[r] - nextMax[l];
            }
        }
        return ans;
    }
};