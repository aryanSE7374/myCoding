#include<bits/stdc++.h>
using namespace std;


// void SOLVE(vector<int>& arr , int n , unordered_map<int , int> mpp){
void SOLVE(vector<int>& arr , int n ){
    // vector<int> revNums(n-mpp.size() , 0);
    vector<int> revNums;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==0){
            revNums.push_back(i+1);
        }
        // if(mpp.find(i+1)==mpp.end()){
        //     revNums.push_back(i+1);
        // }
    }
    sort(revNums.begin(), revNums.end(), greater<int>());

    int k = revNums.size()-1;

    for(int i=0 ; k>=0 && i<n ; i++){
        if(arr[i]==0){
            arr[i] = revNums[k];
            k--;            
        }
    }


    for(int s : arr){
        cout<<s<<" ";
    }

}


int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        
        vector<int> arr(n,0);

        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        SOLVE(arr , n );

        cout<<endl;

    }

    return 0;
}