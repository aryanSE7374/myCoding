#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a ; i<b ; i++)

using namespace std;


void SOLVE(vector<int> vec , int n){

    sort(vec.begin() , vec.end());

    int max_diff = 0;

    for(int i=0 ; i<n ; i+=2){
        max_diff = max(max_diff , abs( vec[i+1]-vec[i] ) );
    }


    cout<<max_diff;
    
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