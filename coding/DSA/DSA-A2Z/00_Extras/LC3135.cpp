#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size() ;
        vector<int> res(n,-1) ;

        for ( int i=0 ; i<n ; i++ ) {

            int curr = 1 , mini = nums[i] ;
            // cout << "i = " << i << " , nums[i]= " << nums[i] << endl ;
            for ( int d=0 ; ( curr <= nums[i] ) && d<32 ; d++ ) {
                // cout << "curr - " << curr << " , " ;
                int ans = nums[i] & ( ~curr ) ;
                // cout << "ans - "  << ans << "\n" ;
                if ( ( ans | (ans+1) ) == nums[i] ) mini = min ( mini , ans );
                curr = curr<< 1 ; 
            }
            // cout << endl ;

            if ( mini < nums[i] ) res[i] = mini ;

        }

        return res ;

    }
};