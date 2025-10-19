#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(long long n) {
    return n && ((n & (n - 1)) == 0);
}

void SOLVE(long long n) {
    if (n == 0 || !isPowerOfTwo(n))
            cout<<"YES";
            
            
        else
            cout<<"NO";
}
int main(){

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        // vector<int> arr(n);
        // for(int i=0 ; i<n ; i++){
        //     cin>>arr[i];
        // }
        SOLVE(n);
        cout<<endl;

    }

    return 0;
}