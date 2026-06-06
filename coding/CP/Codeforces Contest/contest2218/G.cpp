/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)


void SOLVE(){

    const ll MOD = 676767677;

    int n, m;
    cin >> n>> m;

    vll b(n);
    vll freq(m,0); // 0 to m-1
    unordered_map<ll, vll> mpp;
    vll sit(n,0); // vis array

    f(i,0,n){
        cin >> b[i];
        mpp[b[i]].push_back(i);
        freq[b[i]]++;
        if ( b[i] == 0 ) sit = 1;
    }

    ll prev = 0;
    ll curr = freq[0];

    ll ans=0;

    for ( ll i=1; i<m; i++ ) {
        // if ( sit[i] ) continue;
        for ( auto it : mpp[b[i]] ) {
            sit[it] = 1;
        }
        ll mul = (curr-prev);
        ll cntCurr = freq[i];
        ll val = 1;
        for(ll j=0; j<cntCurr; j++ ) {
            val = (val*mul)%MOD;
        }
        ans = (ans+val)%MOD;
        prev = curr;
        curr += cntCurr;
    }


    cout << ans;

    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}



class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        
        // Helper lambda to get the cost of making nums[i] a peak
        auto get_cost = [&](int i) {
            long long max_neighbor = max(nums[i-1], nums[i+1]);
            return max(0LL, max_neighbor + 1LL - nums[i]);
        };

        // Case 1: Odd length - Only one fixed configuration is possible
        if (n % 2 != 0) {
            long long total_ops = 0;
            for (int i = 1; i < n - 1; i += 2) {
                total_ops += get_cost(i);
            }
            return total_ops;
        } 
        
        // Case 2: Even length - Prefix/Suffix optimization
        int m = (n - 2) / 2;
        vector<long long> odd_costs(m);
        vector<long long> even_costs(m);
        
        // Calculate costs for all valid odd and even candidates
        for (int i = 0; i < m; ++i) {
            odd_costs[i] = get_cost(1 + 2 * i);
            even_costs[i] = get_cost(2 + 2 * i);
        }

        // Initially, assume we pick ALL even indices (k = 0 odd indices)
        long long current_even_sum = 0;
        for (int i = 0; i < m; ++i) {
            current_even_sum += even_costs[i];
        }

        long long min_ops = current_even_sum;
        long long current_odd_sum = 0;

        // Slide the window: gradually pick one more odd index and drop one even index
        for (int i = 0; i < m; ++i) {
            current_odd_sum += odd_costs[i];
            current_even_sum -= even_costs[i];
            min_ops = min(min_ops, current_odd_sum + current_even_sum);
        }

        return min_ops;
    }
};