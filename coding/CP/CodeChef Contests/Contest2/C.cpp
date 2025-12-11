/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/ 

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n,k;
    cin >> n >> k;

    string S;
    cin >> S;

    bool ans = true;

    int cnt0 = 0; 
    int cnt1 = 0;

    f(i,0,n){
        if(S[i] == '0') cnt0++;
        else cnt1++;
    }

    vector<int> grp(k, 0);

    f(i,0,n){
        grp[i%k]++;
    }

    int r0 = 0;
    int r1 = 0;

    f(i,0,k){
        // r0 += (grp[i]) / 2;
        r0 += (grp[i] + 1) / 2;
        r1 += (grp[i]) / 2;
    }

    // if(cnt0 > r0 ) ans = false;
    // else if(cnt1 > r0) ans = false;
    
    if( (cnt0 > r0) || (cnt1 > r0) ) ans = false;
   

    cout << ( (ans) ? "YES" : "NO") ;

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