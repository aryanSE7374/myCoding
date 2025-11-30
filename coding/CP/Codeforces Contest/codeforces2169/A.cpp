#include<bits/stdc++.h>
using namespace std;


int SOLVE(vector<int>& vec , int n , int a , vector<int>& delta){

    int delta_min = INT_MAX;
    for(int i=0 ; i<n ; i++){
        delta[i] = abs(a-vec[i]);
        delta_min = min(delta_min , delta[i]);
    }

    int start = 0;
    int end = 0;
    for(int i=0 ; i<n ; i++){
        if(delta[i]==delta_min) start = i;
        while(i<n && delta[i]==delta_min){
            end = i;
            i++;
        }
    }

    if( (n-end-1) > start ){
        return a+1;
    }
    else if( (n-end-1) < start ){
        return a-1;
    }
    else return a;



}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n , a;
        cin>>n>>a;
        vector<int> vec(n,0);
        vector<int> delta(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }
        sort(vec.begin() , vec.end());

        cout<<SOLVE(vec , n , a , delta)<<"\n";

    }

    return 0;
}