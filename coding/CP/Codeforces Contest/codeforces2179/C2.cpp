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

    int n;
    cin >> n;

    vll a(n+2);

    f(i,1,n+1){
        cin >> a[i];
    }

    vll pref(n+3,0);
    vll suf(n+3,0);

    f(i,1,n+1){
        pref[i] = pref[i-1] + a[i];
    }

    for(int i=n ; i>=0 ; i--){
        suf[i] = suf[i+1] + a[i];
    }

    ll ans = LLONG_MIN;
    ll curr = 0;


    // f(i,1,n+1){
    //     ll temp = pref[i-1] - suf[i+1];
    //     ans = max(ans , temp);
    // }

    f(i,1,n+1){
        ll temp = curr - suf[i+1];
        ans = max(ans , temp);

        if(i==1) curr += a[i];
        else curr += abs(a[i]);
        
        // curr += abs(a[i]);
        // if(curr<0){
        //     curr = -1LL*curr;
        // }
    }

    cout << ans;

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}