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

    ll n, k;
    cin >> n >> k;

    vll a(n);
    vll b(n);

    f(i,0,n){
        cin >> a[i];
    }

    f(i,0,n){
        cin >> b[i];
    }

    vector<pll> pairs(n);
    ll sum = 0;
    f(i,0,n){
        ll mini = (a[i]<b[i]) ? a[i] : b[i];
        ll maxi = (a[i]>b[i]) ? a[i] : b[i];
        pairs[i] = {mini, maxi};
        sum += llabs(a[i]-b[i]);
    }

    sort (pairs.begin(), pairs.end()); 

    ll minDiff = LLONG_MAX;
    ll delta = 0;

    f(i,0,n-1){

        ll w = pairs[i].first, x = pairs[i].second,
        y = pairs[i+1].first, z = pairs[i+1].second;

        ll value = abs(x-w) + abs(z-y);

        vll nums = {w, x, y, z};
        sort(nums.begin(), nums.end());

        ll diff = (nums[3]-nums[0]) + (nums[2]-nums[1]) ; // new value obtained

        // if ( diff < minDiff ) {
        //     minDiff = diff; // this line missing
        //     delta = diff-value; // difference made
        // }
        ll currDelta = diff - value;
        if ( currDelta < minDiff ) {
            minDiff = currDelta; 
        }

    }

    // cout << sum+delta <<'\n';
    cout << sum+minDiff <<'\n';

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