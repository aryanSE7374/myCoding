#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll n, ll X, vector<ll>& arr){

    ll S = accumulate(arr.begin(), arr.end(), 0);
    ll C = S / X;

    sort(arr.begin(), arr.end());

    vector<ll> top(arr.end() - C , arr.end());
    vector<ll> others(arr.begin() , arr.end() - C);

    vector<ll> final;
    for (auto x : others) final.push_back(x);
    for (auto x : top) final.push_back(x);

    ll ans = accumulate(top.begin() , top.end() , 0);

    cout << ans << endl;
    for (auto x : final) cout << x << " ";

}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        ll n , X ;
        cin>>n>>X;
        vector<ll> arr(n);

        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        SOLVE( n , X , arr );
        cout<<endl;

    }

    return 0;
}