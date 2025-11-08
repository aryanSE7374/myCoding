#include<bits/stdc++.h>
using namespace std;
#define ll long long



void SOLVE(int n , vector<ll> arr , bool hasOne , int e_count , int o_count , int last_even){

    if(hasOne){
        ll x;
        int ones = 0;
        for(int i=0 ; i<n ; i++){
            if( ones<1 && arr[i]==1) ones++;
            else{
                x=arr[i];
                break;
            }
        }
        cout<<1<<" "<<x;
    }

    else if(e_count >= 2){

        ll x , y;
        int evens = 0;
        for(int i=0 ; i<n && evens<2 ; i++){
            if(arr[i]%2 == 0){
                evens ++;
                if(evens == 1){
                    x = arr[i];
                }
                else{
                    y = arr[i];
                }
            }
        }

        cout<<x<<" "<<y;

    }

    else if(e_count == 1){

        ll e = last_even;
        ll y = e;
        ll x = -1;

        for(int i=0 ; i<n ; i++){
            ll tempx = arr[i];
            if( (arr[i]%2 == 1) && ( (e/3) < arr[i]) && (arr[i] <= (e/2) ) ){
                x = arr[i];
                break;
            }
        }

        if(x == -1){
            cout << -1 ;
        }
        else{
            cout<<x<<" "<<y;
        }

    }

    else if(e_count == 0){
        ll x;
        ll y = -1;
        for(int i=0 ; i<n-1 ; i++){
            ll tempx = arr[i];
            if(arr[i+1] < 2*tempx){
                x = tempx;
                y = arr[i+1];
                break;
            }
        }

        if(y == -1){
            cout << -1 ;
        }
        else{
            cout<<x<<" "<<y;
        }
        // cout<<x<<" "<<y;

    }

    else{
        cout<< -1 ;
    }

    cout<<"\n";
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<ll> arr(n);


        bool hasOne = false;

        int e_count = 0;
        int o_count = 0;
        int last_even;

        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(arr[i] == 1){
                hasOne = true;
            }
            if((arr[i]%2) == 0){
                e_count++;
                last_even = arr[i];
            }
            else o_count++;
        }

        
       SOLVE( n , arr , hasOne , e_count , o_count , last_even );

    }

    return 0;
}