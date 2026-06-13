#include<bits/stdc++.h>
using namespace std;

/*
algo

hash arr_val -> arr of indices : Brute

optimal

    instead of storing indices directly, use a prefix table instead
    
    say for a correspondig value, we have -> {j1, j2, j3, .... jk, ....jm} m indices

    val for i at k in indices = (2*k - m) + summation{i=k+1 to m}[ji] - summation{i=1 to k-1}[ji]

                              = (2*k - m) + pref[m] - pref[k] - pref[k-1]

    we can get rid of an extra space using a custom BS : search for pref[mid]-pref[mid-1] == target , pref[0] = 0 , use 1 based indexing

*/

typedef long long ll;

class Solution {
public:

    ll BS ( vector<ll>& pref, ll x ) {
        ll low = 0, high = 1LL*pref.size() - 1;
        ll mid;
        while ( low <= high ) {
            mid = low + (high-low)/2;
            if ( mid <= 0 ) return 0;
            ll value = (pref[mid] - pref[mid-1]);
            if ( value == x ) return mid;
            if ( value < x ) low = mid+1;
            else high = mid-1;
        }
        return 0;
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n);
        unordered_map<ll, vector<ll>> indexMap; // prefix

        // build indexMap prefix
        for ( int i=0; i<n; i++ ) {
            if ( indexMap.find(nums[i]) == indexMap.end() ) {
                indexMap[nums[i]].push_back(0);
            }
            indexMap[nums[i]].push_back( 1LL*indexMap[nums[i]].back() + i+1 );
            // else {
            // }
        }

        for ( auto& [it, vec] : indexMap ) {
            cout << it << " : [ ";
            for ( ll& num : vec ) {
                cout << num << ", ";
            }
            cout << " ]\n";
        }

        for ( int i=0; i<n; i++ ) {
            auto& pref = indexMap[nums[i]];
            ll k = BS ( pref, i+1 );
            if ( k==0 ) {
                ans[i] = -1;
                continue;
            }
            ll m = pref.size();
            ll val = (2*k - m) + pref[m-1] - pref[k] - pref[k-1];
            ans[i] = val;
        }

        return ans;

    }
};