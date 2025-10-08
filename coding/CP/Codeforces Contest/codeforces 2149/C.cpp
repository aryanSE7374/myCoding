#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a ; i<b ; i++)

using namespace std;



// 1
// void SOLVE(vector<int> vec , int n , int k){

//     int count = 0;

//     for(int i=0 ; i<n ; i++){
//         if(vec[i]==k) count++;
//     }


//     cout<<count;
    
// }


// 2

void SOLVE(vector<int> vec , int n , int k){

    sort(vec.begin() , vec.end());

    int count = 0;
    unordered_map<int , int> mpp;

    for(int i=0 ; i<n ; i++){

        if(vec[i]<k) mpp[vec[i]]++;

        if(vec[i]==k){
            count++;
        }


    }

    int m = mpp.size();
    
    // if( (k-m) >= count ){
    //     cout<<k-m;
    // }
    // else{
    //     cout<<count;
    // }
    cout<<max(k-m , count);
    
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        int k;
        cin>>n;
        cin>>k;
        vector<int> vec(n,0);
        f(i,0,n){
            cin>>vec[i];
        }
        SOLVE(vec , n , k);
        cout<<endl;
    }
    return 0;
}