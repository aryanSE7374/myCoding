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
        
        // prevMax[i] = cost to travel from 0 to i
        vector<long long> prevMax(n, 0); 
        // nextMax[i] = cost to travel from i down to 0
        vector<long long> nextMax(n, 0); 
        
        for ( int i=1; i<n; i++ ) {
            long long costNext = (closest[i-1] == i) ? 1 : (nums[i] - nums[i-1]);
            prevMax[i] = prevMax[i-1] + costNext;
            
            long long costPrev = (closest[i] == i-1) ? 1 : (nums[i] - nums[i-1]);
            nextMax[i] = nextMax[i-1] + costPrev;
        }
        
        int qsize = queries.size();
        vector<long long> ans(qsize);
        
        // queries
        for ( int i=0; i<qsize; i++ ) {
            int l = queries[i][0], r = queries[i][1];
            
            if ( l < r ) { // go forward
                ans[i] = prevMax[r] - prevMax[l];
            }
            else { // go backward
                ans[i] = nextMax[l] - nextMax[r];
            }
        }
        return ans;
    }
};