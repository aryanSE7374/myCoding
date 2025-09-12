#include<bits/stdc++.h>
using namespace std;


void SOLVE(int n , int m , vector<int>& ovens){
    
    sort(ovens.begin() , ovens.end());

    long long maxCakes = 0;

    // for(int i=n-1 ; i>=0 ; i--){
    // for(int i=0 ; i<n && ((m-i)>=1) ; i++){
    for(int i=0 ; i<n && (i<=(m-1)) ; i++){
        
        int idx = n-i-1;

        maxCakes += 1LL*ovens[idx]*(m-i);

        // if(m-i == 1){
        //     break;
        // }

    }

    cout<<maxCakes<<" ";

}

int main(){
    
    int t;
    cin>>t;
    while (t-->0)
    {

        int n,m;
        cin>>n;
        cin>>m;

        vector<int> ovens(n);

        for(int i=0 ; i<n ; i++){
            cin>>ovens[i];
        }

        SOLVE(n,m,ovens);

        cout<<endl;

    }

    return 0;
    
}