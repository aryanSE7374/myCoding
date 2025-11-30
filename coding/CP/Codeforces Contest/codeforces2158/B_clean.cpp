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

    ll n;
    cin>>n;

    ll N = 2LL*n;
    vll a(N);

    unordered_map<ll , ll> freq;

    f(i,0,N){
        cin >> a[i];
        freq[a[i]]++;
    }

    ll oddf = 0;
    ll evenf = 0;
    ll split = 0;

    ll f = 0 , p = 0; 
    ll fp = 0 , fq = 0;

    for(auto &[num,cfrq] : freq){

        if(cfrq % 2 == 1) oddf++;
        else evenf++;

        split += (cfrq/2);

    }

    ll ans = oddf + (2*evenf);
    if(oddf == 0){
        if(evenf%2 != (n%2)) ans -= 2;
    }

    cout << ans << "\n";

    return;

    // -------------------------------------------------------- //

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




