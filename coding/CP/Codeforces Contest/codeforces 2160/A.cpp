#include<bits/stdc++.h>
using namespace std;

void SOLVE(vector<int> A , int n ){
    int mex = 0;
    // sort(A.begin() , A.end());
    vector<int> mexVec(101,0); // 0 to 100
    for(int num : A){
        mexVec[num]++;
    }
    for(int i=0 ; i<101 ; i++){
        if(mexVec[i]==0){
            cout<<i;
            return;
        }
    }
    cout<<101;

}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> A(n,0);
        // int maxi = 0;
        for(int i=0 ; i<n ; i++){
            cin>>A[i];
            // maxi = max(maxi , A[i]);
        }

        SOLVE( A , n);
        cout<<endl;

    }

    return 0;
}