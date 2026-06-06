/*
code by - Aryan Shrivastav
*/

/*
observations : 


1 , 1*2 , 1*2*3 , 2*3*4 , 3*4*5 , ..... (i-1) * i * (i+1) , ....

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)


ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }


void SOLVE(){

    ll n;
    cin >> n;

    vll ans(n);

    ans[0] = 1;
    for ( ll i=1; i<n; i++ ) {
        // ans[i] = 1LL * (i) * (i+1) * (i+2); // 1-based
        ans[i] = 1LL * (2*i + 1) * (2*i + 3);
        // int GCD = gcd(ans[i], ans[i-1]);
        // cout << "GCD[" << i << "] : " << GCD << "\n";
    }

    f(i,0,n) {
        cout << ans[i] << " ";
    }

    

    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}