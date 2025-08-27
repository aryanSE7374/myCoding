#include<bits/stdc++.h>
using namespace std;



long long evenLarger(vector<long long> arr, int n) {
    long long evenSum = 0, oddSum = 0;
    long long res = 0;

    for(int i = 0; i < n; i++) {
        if((i+1) % 2 == 0) evenSum += arr[i]; // even index
        else oddSum += arr[i];                // odd index

        if(oddSum > evenSum) {
            res = max(res, oddSum - evenSum);
        }
    }

    return res;
}



int main(){
    int t;
    cin>>t;
    while (t-->0)
    {
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        cout<<evenLarger(arr , n)<<endl;    
    }
    
    return 0;
}