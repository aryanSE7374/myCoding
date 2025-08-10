#include<bits/stdc++.h>
using namespace std;


bool adjacentXOR(vector<long long> a , vector<long long> b , int n){
    if(a[n-1]!=b[n-1]){
        return false;
    }
    int count = 0;
    while(count<n-1){
        bool flag=false;
        for(int i=0 ; i<n-1 ; i++){
            if((a[i]^a[i+1])==b[i]){
                a[i]=b[i]=0;
                count++;
                flag=true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    return true;
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