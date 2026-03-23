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

    ll n, c, k;

    cin >> n >> c >> k;

    vi a(n);

    f(i,0,n) {
        cin >> a[i];
    }

    sort ( a.begin(), a.end() ) ;

    ll i=0;
    while ( (i<n) && (a[i] <= c) ) {
        ll maxDiff = c-a[i];
        ll left = min ( k, maxDiff );
        c += (a[i] + left);
        k -= left;
        i++;
    }

    cout << c;

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