#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a ; i<b ; i++)

using namespace std;

void SOLVE(vector<int> vec , int n){
    int zeroes = 0;
    int minus_ones = 0;
    int res = 0;

    for(int num : vec){
        if(num == 0) zeroes++;
        else if (num == -1) minus_ones++;
    }

    res+=zeroes;
    if(minus_ones%2 == 1){
        res+=2;
    }

    cout<<res;
    
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> vec(n,0);
        f(i,0,n){
            cin>>vec[i];
        }
        SOLVE(vec , n);
        cout<<endl;
    }
    return 0;
}