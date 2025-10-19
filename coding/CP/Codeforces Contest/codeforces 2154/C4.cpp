#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    while(b != 0){
        int t = b;
        b = a % b; 
        a = t;
    }
    return a;
}

void SOLVE(vector<int>& a , vector<int>& b ,  int n){

    int minOps = 2;

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){

            int gcd1 = gcd(a[i] , a[j]);
            int gcd2 = gcd(a[i]+1 , a[j]);
            int gcd3 = gcd(a[i] , a[j]+1 );
            int gcd4 = gcd(a[i]+1 , a[j]+1 );

            if(gcd1>1){
                cout<<0;
                return;
            }
            else if(gcd2>1 || gcd3>1){
                minOps = 1;
            }
            else if(gcd4>1){
                minOps = 2;
            }
        }
    }

    cout<<minOps;
}


int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }

        SOLVE(a,b,n);
        cout<<endl;

    }

    return 0;
}