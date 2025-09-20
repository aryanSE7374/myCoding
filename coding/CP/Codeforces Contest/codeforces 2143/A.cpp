#include<bits/stdc++.h>
using namespace std;


bool SOLVE(vector<int> p , int n){
    if(n==1 || n==2){
        return true;
    }
    unordered_map<int , int> idx;
    for(int i=0 ; i<n ; i++){
        idx[p[i]]=i;
    }

    int l=idx[n];
    int r=idx[n];

    for(int k=n-1 ; k>=1 ; k--){
        int i = idx[k];
        if((l-i)==1){
            l=i;
        } 
        else if((i-r)==1){
            r=i;
        }
        else{
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
        vector<int> p(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }
        if(SOLVE(p , n)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }

        cout<<endl;
    }
    return 0;
}