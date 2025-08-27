#include<bits/stdc++.h>
using namespace std;

int evenLarger(vector<int> arr, int n) {
    long long res = 0;

    for(int l = 0; l + 2 < n; l++) {
        int r = l + 2;
        while(arr[l+1] < arr[l] + arr[r]) {
            if(arr[r] > 0) {
                arr[r]--;
            } else if(arr[l] > 0) {
                arr[l]--;
            } else {
                break; // not reduce further
            }
            res++;
        }
    }

    if(n % 2 == 1 && n > 1) {
        int lastIdx = n-1;
        int secondLastIdx = n-2;
        while(arr[lastIdx] < arr[secondLastIdx]) {
            if(arr[secondLastIdx] > 0) {
                arr[secondLastIdx]--;
            } else {
                break;
            }
            res++;
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
        vector<int> arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        cout<<evenLarger(arr , n)<<endl;    
    }
    
    return 0;
}