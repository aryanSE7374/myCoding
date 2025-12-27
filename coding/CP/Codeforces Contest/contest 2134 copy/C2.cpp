#include<bits/stdc++.h>
using namespace std;

long long evenLarger(vector<long long> arr , int n){
    long long res = 0;
    
    // 1. Sliding window of size 3 (l, l+1, r=l+2)
    for (int l = 0; l + 2 < n; ++l) {
        int r = l + 2;
        
        // 2. Check the condition
        // Note: The problem's condition is more complex than this.
        // This check assumes the middle element is "odd" and neighbors are "even".
        if (arr[l+1] < arr[l] + arr[r]) {
            long long needed = (arr[l] + arr[r]) - arr[l+1];
            
            // This condition is arr[l+1] >= arr[l] + arr[r].
            // To satisfy it, we need to increase the LHS or decrease the RHS.
            // Operations only allow decreasing elements. So we decrease RHS.
            // Your logic: decrement arr[r] first, then arr[l].
            
            long long reduce_r = min(needed, arr[r]);
            res += reduce_r;
            arr[r] -= reduce_r;
            needed -= reduce_r;
            
            if (needed > 0) {
                long long reduce_l = min(needed, arr[l]);
                res += reduce_l;
                arr[l] -= reduce_l;
                needed -= reduce_l;
            }
        }
    }
    
    // 3. Handle edge cases (as mentioned in your description)
    // The loop handles most cases, but odd/even length might have unchecked pairs.
    // However, the core logic has issues, so a full edge case handling is complex.
    
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