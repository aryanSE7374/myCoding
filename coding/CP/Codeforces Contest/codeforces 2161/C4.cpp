#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll n , ll X , vector<ll>& arr){

    ll S = accumulate(arr.begin() , arr.end() , 0 );
    ll C = S / X; 

    sort(arr.begin() , arr.end());

    ll ans = 0;

    for(int i = 0 ; i < C ; i++){
        ans += arr[n - i - 1];
    }

    cout << ans << endl;

    vector<ll> final; 
    ll k = n - C;

    if(k >= C){

        for(int i = 0 ; i < k - C ; i++){
            final.push_back(arr[i]);
        }

        for(int i = 0 ; i < C ; i++){
            final.push_back(arr[ i -C + k ]) ;
            final.push_back(arr[ i + k ]) ;
        }
    } 

    else {

        for(int i = 0 ; i < C - k ; i++){
            final.push_back( arr[n -(C - k) + i] );
        }

        for(int i = 0 ; i < k ; i++){
            final.push_back(arr[i]);   
            final.push_back(arr[k + i]);
        }

    }

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


/*
7
10 2
1 2 1 2 1 2 1 2 1 2
5 10
2 2 2 2 5
11 23
5 5 22 1 21 2 10 3 1 1 2
1 1
1
1 17
11
3 100
44 32 1
16 100500
42801 73112 95296 68791 42217 21871 29316 84405 24273 42894 63370 53473 57156 61369 80 27290
*/