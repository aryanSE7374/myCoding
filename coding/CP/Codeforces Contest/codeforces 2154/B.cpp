#include<bits/stdc++.h>
using namespace std;


void SOLVE(vector<int> a , int n){

    vector<int> pref_max(n,0);


    // int maxi = a[0];
    pref_max[0] = a[0];

    for(int i=1 ; i<n ; i++){
        pref_max[i] = max(pref_max[i-1] , a[i] );
    }

    int cnt = 0;

    for(int i=0 ; i<n ; i++){
        if(i%2 == 1){ // even of 1 based indexing
            a[i] = pref_max[i];
        }
    }
    for(int i=0 ; i<n-1 ; i++){
        if(i%2 == 0){ // odd of 1 based indexing

            if(a[i]>=a[i+1]){ // violation
                int delta = a[i]-a[i+1];
                cnt += delta+1;
                a[i] = a[i]-delta-1;
                pref_max[i] = (i>0) ? max(pref_max[i-1] , a[i]) : a[i];
            }
        }
        else{ // even of 1 based indexing

            if(a[i]<=a[i+1]){ // violation
                int delta = a[i+1]-a[i];
                cnt += delta+1;
                a[i+1] = a[i+1]-delta-1;
                pref_max[i] = (i>0) ? max(pref_max[i-1] , a[i]) : a[i];
            }

        }
    }

    cout<<cnt;


}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        for(int i=0 ; i<n ;  i++){
            cin>>a[i];
        }
        SOLVE(a,n);
        cout<<endl;

    }

    return 0;
}