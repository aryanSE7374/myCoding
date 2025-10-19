#include<bits/stdc++.h>
using namespace std;

void SOLVE(vector<int> b , int n){
    unordered_map<int , int> freq;
    for(int num : b){
        freq[num]++;
    }
    int size = freq.size();
    cout<<size;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> b(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }

        SOLVE( b , n);
        cout<<endl;

    }

    return 0;
}