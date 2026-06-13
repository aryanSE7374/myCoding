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

    int n, m;
    cin >> n >> m;

    vi a(n);
    vi dist(n);
    vi diff(n);
    f(i,0,n){
        cin >> a[i];
        dist[i] = m-a[i];
        if ( i>0 ) diff[i] = abs (dist[i-1] - dist[i]);
    }

    // find max consecutive diff = 0 , that should be less than m

    int maxi = 0;
    int cnt = 0;
    int j=1;
    
    while ( j<n ) {
        while( j<n && (diff[j] == 0) ) {
            cnt++;
            j++;
        }
        maxi = max(maxi, cnt);
        cnt = 0;
        j++;
    }

    // f(i,1,n){
    //     cout << diff[i] << " ";
    // }

    // cout << endl;

    // int maxi = 1;
    // int cnt = 1;
    // int j=2;
    
    // while ( j<=n ) {
    //     while( j<=n && (diff[j-1] == diff[j]) ) {
    //         cnt++;
    //         j++;
    //     }
    //     maxi = max(maxi, cnt);
    //     cnt = 1;
    //     j++;
    // }

    if ( maxi >= 2 ) {
        cout << "NO\n";
        return;
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