#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n,x;

        cin>>n;
        vector<int> vec(n);
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
            maxi = max(maxi , vec[i]);
            mini = min(mini , vec[i]);
        }

        cin>>x;

        bool ans = ( mini <= x ) && (x <= maxi) ;

        if(ans) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";

    }

    return 0;
}

