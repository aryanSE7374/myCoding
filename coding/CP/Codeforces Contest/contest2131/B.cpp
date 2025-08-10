#include<bits/stdc++.h>
using namespace std;

// try 1

vector<int> alternatingSeries(int n){
    vector<int> res(n,0);
    res[0]=-1;
    res[1]=2;
    for(int i=2 ; i<n ; i++){
        if(i%2==0){ // even indices
            res[i]--;
            res[i-1]++;
        }
        else{ // odd indices
            res[i]+=2;
        }
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> res = alternatingSeries(n);
        for(int num : res){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}