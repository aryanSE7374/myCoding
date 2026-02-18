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

    // vi a(n);
    // f(i,0,n) {
    //     cin >> a[i];
    // }

    // for ( int i=0 ; i <= (n/2)-1 ; i++ ) {
    //     if ( a[i] > a[2*i + 1] ) swap(a[i] , a[2*i+1] );
    // }

    // if ( is_sorted(a.begin(),a.end())) cout << "YES";
    // else cout << "NO";

    // cout<<'\n';

    // vi a(n);
    // f(i,0,n) {
    //     cin >> a[i];
    // }

    // for ( int i=(n/2)-1 ; i >= 0 ; i-- ) {
    //     if ( a[i] > a[2*i + 1] ) swap(a[i] , a[2*i+1] );
    // }

    // if ( is_sorted(a.begin(),a.end())) cout << "YES";
    // else cout << "NO";

    vi a(n+1); // 1-based
    f(i,1,n+1) cin >> a[i];

    vector<int> vis(n+1,0);
    bool flag = true;

    f(i,1,n+1){
        if(!vis[i]){
            multiset<int> idx;
            multiset<int> nodes;

            int j = i;
            while( j <= n ) {
                vis[j] = 1;
                idx.insert(j);
                nodes.insert(a[j]);
                j *= 2;
            }

            if( idx != nodes ){
                flag = false;
                break;
            }
        }
    }

    if ( flag ) cout << "YES";
    else cout << "NO";

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