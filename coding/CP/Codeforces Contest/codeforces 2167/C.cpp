#include<bits/stdc++.h>
using namespace std;


bool SOLVE(int n , vector<int>& vec){

    bool ans = false;

    int r = vec[0] % 2;

    for(int i=1 ; i<n ; i++){
        if(r != (vec[i]%2) ){
            ans = true;
            break;
        }
    }

    return ans;

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

        if(ans){
            sort(arr.begin() , arr.end());
        }

        for(int num : arr){
            cout<<num<<" ";
        }

        cout<<endl;

    }

    return 0;
}