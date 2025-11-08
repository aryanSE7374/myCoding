#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll n , ll X , vector<ll>& arr){

    sort(arr.begin() , arr.end()); 

    ll S = accumulate(arr.begin() , arr.end() , 0 );
    ll C = S / X;
    ll ans = 0;

    vector<ll> top , others;

    for(int i = n - 1 ; i >= 0 ; i--){

        S -= arr[i];

        if( ( S / X ) < C){

            top.push_back(arr[i]);
            ans += arr[i];
            C = S / X;

        } 
        else{
            others.push_back(arr[i]);
        }
    }

    reverse(others.begin(), others.end());
    reverse(top.begin(), top.end());

    cout << ans << "\n";
    for(auto x : others) cout << x << " ";
    for(auto x : top) cout << x << " ";
    cout << "\n";
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