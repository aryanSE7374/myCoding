#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a , ll b){
    while(b){
        ll t = a%b;
        a = b;
        b = t;
    }
    return a;
}

void SOLVE(vector<ll> arr , int n) {

    vector<ll> pfs = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    unordered_set<ll> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

    int m = pfs.size();

    bool flag = true;

    for(int j = 0 ; j<m ; j++){
        for(int i=0 ; i<n ; i++){
            if((arr[i]%pfs[j])!=0){
                flag = false;
                break;
            }
            // arr[i]/=pfs[j];
        }
    }

    if(flag){
        cout << 53;
    }

    else{
        int j=2;
        bool flag2 = false;
        for( ; j<=53 ; j++ ){
            for(int i=0 ; i<n ; i++){
                if(gcd(arr[i],j)==1){
                    flag2 = true;
                    break;
                }
            }
            if(flag2){
                cout << j;
                break;
            }
        }
    }




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