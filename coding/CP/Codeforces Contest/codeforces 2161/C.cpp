#include<bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll n , ll X , vector<ll>& arr ){

    sort(arr.begin(), arr.end());

    ll S = 0 , C = 0 , ans = 0;

    // if(arr[0] < X){
    //     cout << 0;
    //     return;
    // }

    for(int i=0 ; i<n ; i++){
        S += arr[i];
        if((S/X)>C){
            ans += arr[i];
        }
        C = S/X;
    }

    cout<<ans<<endl;
    for (auto x : arr) cout << x << " ";


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