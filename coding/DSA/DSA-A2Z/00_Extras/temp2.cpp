#include<bits/stdc++.h>
using namespace std;

/*

oncwe we processed the minimal 1 cost jumpt, we have to use dp to find the optimal jump ?? 

*/

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        
        // processing
        // difference table - prev and next both

        const int INF = 2e9;
        int n = nums.size();

        // vector<int> prev(n);
        // vector<int> next(n);
        vector<int> closest(n);
        vector<int> prevMax(n); // maxiumum i can go in backward with cost 1
        vector<int> nextMax(n); // maxiumum i can go in foward with cost 1

        closest[0] = 1;
        closest[n-1] = n-2;

        for ( int i=1; i<n-1; i++ ) {
            closest[i] = ( (nums[i] - nums[i-1]) <= (nums[i+1] - nums[i]) ) ? (i-1) : (i+1);
        }

        prevMax[0] = 0;
        nextMax[n-1] = n-1;

        for ( int i=1; i<n; i++ ) {
            prevMax[i] = min (i, closest[i]);
            prevMax[i] = prevMax[prevMax[i]];
        }
        
        for ( int i=n-2; i>=0; i-- ) {
            nextMax[i] = max (i, closest[i]);
            nextMax[i] = nextMax[nextMax[i]];
        }

        // cout << "closest: ";
        // for ( int i=0; i<n; i++ ) {
        //     cout << closest[i] << " ";
        // }
        // cout << endl;
        // cout << "prevMax: ";
        // for ( int i=0; i<n; i++ ) {
        //     cout << prevMax[i] << " ";
        // }
        // cout << endl;
        // cout << "nextMax: ";
        // for ( int i=0; i<n; i++ ) {
        //     cout << nextMax[i] << " ";
        // }
        // cout << endl;

        int qsize = queries.size();
        vector<int> ans(qsize);
        
        // queries
        for ( int i=0; i<qsize; i++ ) {
            int l = queries[i][0], r = queries[i][1];
            int sum = 0;

            if ( l < r ) { // go forward
                int l1 = min(r, nextMax[l]);
                int delta = l1 - l;
                // cout << "delta : " << delta << endl;
                sum += delta; // 1 cost
                // cout << "rem : " << nums[r] - nums[l1] << endl;
                sum += nums[r] - nums[l1];
            }

            else { // go backward
                int l1 = max(r, prevMax[l]);
                int delta = l - l1;
                // cout << "delta : " << delta << endl;
                sum += delta; // 1 cost
                // cout << "rem : " << nums[l1] - nums[r] << endl;
                sum += nums[l1] - nums[r];
            }
            
            ans[i] = sum; // ans here
        }

        return ans;
    }
};