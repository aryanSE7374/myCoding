#include<bits/stdc++.h>
using namespace std;


bool SOLVE(int n , vector<int>& vec){

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        bool ans = SOLVE(n,arr);


        cout<<endl;

    }

    return 0;
}