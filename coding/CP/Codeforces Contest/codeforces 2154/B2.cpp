#include<bits/stdc++.h>
using namespace std;


void SOLVE(vector<long long> b , int n){

    vector<long long> a(n,0);
    vector<long long> delta(n,0);
    delta[0] = 1;
    // delta[0] = b[0];

    for(int i=1 ; i<n ; i++){
        delta[i] = b[i]-b[i-1];
    }

    long long cnt = 1;
    a[0] = 1;

    for(int i=1 ; i<n ; i++){
        if(delta[i]==1){
            a[i] = a[i-1];
        }
        else if(delta[i]<i+1){ // delta <= i   =>    i-delta >= 0
            // a[i] = cnt-1;
            a[i] = a[i-delta[i]];
        }
        else{  // delta[i] == i+1 or delta[i] > i   =>   i-delta < 0
            cnt++;
            a[i] = cnt;
        }
    }

    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> b(n,0);
        for(int i=0 ; i<n ;  i++){
            cin>>b[i];
        }
        SOLVE(b,n);
        cout<<endl;

    }

    return 0;
}