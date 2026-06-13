/*
code by - Aryan Shrivastav
*/

/*
observations : 

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


void SOLVE(){

    ll n;
    cin >> n;

    vll a(n);

    f(i,0,n){
        cin >> a[i];
    }

    ll cnt = 0;
    ll prev = -2; // one before current 

    unordered_map<ll, ll> index; // stores latest seen index of an element
    index[0] = -1;

    ll l = 0;
    ll pref = 0;

    for ( ll r=0; r<n; r++ ) {
        pref += a[r];
        ll windowLen = r-l+1;
        if ( index.find(pref) != index.end() ) { // an index exists
            ll idx = index[pref];
            if ( idx >= prev ) {
                cnt += (r-idx-1);
                // cnt += (r-idx-1)*(r-idx)/2;
                l = idx + 2;
                prev = l-1; // or idx + 1
                index[pref] = r;
            }
            else{
                // lazy deletion
                cnt += windowLen;
                index[pref] = r;
            }
        }
        else{
            cnt += windowLen;
            index[pref] = r;
        }
    }

    cout << cnt;
    cout<<'\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}
