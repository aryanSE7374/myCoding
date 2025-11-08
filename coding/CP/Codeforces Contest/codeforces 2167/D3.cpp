#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a , ll b){
    while(b){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void SOLVE(vector<ll> arr , int n){

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

    for(int p : primes){
        bool flag = true; 

        for(int i = 0; i < n; i++){
            if( ( arr[i]%p ) != 0 ){
                flag = false; 
                break;
            }
        }

        if(!flag){
            cout<<p;
            return;
        }
    }

    cout << -1 ;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        SOLVE(arr , n);
        cout<<endl;

    }

    return 0;
}