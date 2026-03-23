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

    int n;
    cin >> n;

    vvi a(n, vi(n));

    vi freq(100001,0);

    f(i,0,n) {
        f(j,0,n){
            cin >> a[i][j];
            freq[a[i][j]]++;
        }
    }

    int maxi = n * (n-1);

    for ( int i=1; i<100001; i++ ) {
        if ( freq[i] > maxi ) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES";

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