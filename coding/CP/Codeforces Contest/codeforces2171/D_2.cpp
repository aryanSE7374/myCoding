/*
code by - Aryan Shrivastav

chatGPT solution

*/

/*
observations : 
    let 
        idx = idx_map : [a[i]->i]
        maxi_dp[k] = max(idx[a[1]] , idx[a[2]] , .... , idx[a[k]])
        mini_dp[k] = min(idx[a[1]] , idx[a[2]] , .... , idx[a[k]])
    

    condition for tree if and only if : 
        maxi_dp[i] - mini_dp[i] == i-1


*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n;
    cin>>n;

    vi a(n); // permutation
    
    
    f(i,0,n){
        cin >> a[i];
    }
    
    vi idx(n+1);
    f(i,0,n+1){
        idx[a[i]] = i;
    }

    vi maxi_dp(n+1);
    vi mini_dp(n+1);

    maxi_dp[1] = idx[1];
    mini_dp[1] = idx[1];

    f(i,2,n+1){
        maxi_dp[i] = max(maxi_dp[i-1] , idx[i]);
        mini_dp[i] = min(mini_dp[i-1] , idx[i]);
    }
    
    
    bool ans = true;
    
    int L = idx[1], R = idx[1];

    for(int x = 2; x <= n; x++){  

        if(idx[x] == R + 1){
            R++;       
        }
        else if(idx[x] == L - 1){
            L--;
        }
        else{
            ans = false;
            break;
        }
    }


    if(ans) cout<<"YES";
    else cout<<"NO";


    co_endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}