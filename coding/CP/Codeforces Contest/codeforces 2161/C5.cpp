#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll n , ll X , vector<ll>& arr){

    sort(arr.begin() , arr.end());

    vector<ll> final;
    
    ll S = 0;
    ll ans = 0;
    ll ps = 0;
    ll pl = n - 1;

    for(int i = 0 ; i < n ; i++){

        ll Cb = S / X;
        ll rem = X - (S % X);

        if(rem == X) rem = 0;

        ll Cs = (S + arr[ps]) / X;

        if(Cs == Cb && ps <= pl){

            S += arr[ps];
            final.push_back(arr[ps]);
            ps++;

        } 
        else{

            S += arr[pl];
            final.push_back(arr[pl]);
            ans += arr[pl];
            pl--;

        }
    }

    cout << ans << endl;

    for(int i = 0 ; i < n ; i++){
        cout << final[i] <<" ";
    }
    
    cout << endl;
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