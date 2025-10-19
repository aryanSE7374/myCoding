#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> vec , int n){
    for(int i=1 ; i<n ; i++){
        if(vec[i-1]>vec[i]) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0 ; i<n ; i++ ){
            cin>>vec[i];
        }

        // code

        if(isSorted(vec,n)) cout<<"YES"<<endl;

        else if(k==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}