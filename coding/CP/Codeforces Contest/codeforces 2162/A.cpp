#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        // vector<int> A(n,0);
        int maxi = 1;
        int num;
        for(int i=0 ; i<n ; i++){
            cin>>num;
            maxi = max(maxi , num);
            // maxi = max(maxi , A[i]);
        }

        // SOLVE( A , n);
        cout<<maxi<<endl;

    }

    return 0;
}