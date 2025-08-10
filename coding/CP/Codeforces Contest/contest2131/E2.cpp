#include<bits/stdc++.h>
using namespace std;


bool adjacentXOR(vector<long long> a , vector<long long> b , int n){
    for (int i=0; i<n-1; i++) {
        if (a[i]!=b[i]) {
            a[i]=a[i]^a[i+1];
        }
    }
    return a==b;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;

        vector<long long> a(n), b(n); 

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
        }

        if(adjacentXOR(a,b,n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}