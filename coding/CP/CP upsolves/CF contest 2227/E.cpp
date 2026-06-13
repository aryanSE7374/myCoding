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


// int fun (vi &a, int j, int k ) {
//     int cnt = 0;
//     int sum = 0;
//     for (int i=j; i>=0; i-- ) {
//         if ( a[i] > k ) {
//             sum += a[i];
//             cnt++;
//         }
//     }
//     return sum - k*cnt - 1;
// }

// void SOLVE(){

//     int n;
//     cin >> n;

//     vi a(n);
//     cin >> a[0];

//     // vi pref(n,0);
//     // pref[0] = a[0];

//     f(i,1,n){
//         cin >> a[i];
//         // pref[i] = pref[i-1] + a[i];
//     }

//     int k = -1;
//     int j = n;

//     int maxi = 0;

//     for ( int i=n-1; i>0; i-- ) {
//         if ( a[i-1] >= a[i] ) {
//             k = a[i]-1;
//             j=i;
//             maxi = max( maxi, fun(a, j, k) );
//         }
//     }

//     if ( j==n ) {
//         cout << 0;
//     }
//     else {
//         cout << maxi;
//     }

//     cout<<'\n';
// }


void SOLVE() {

    int n;
    cin >> n;

    vi a(n);

    f(i,0,n) {
        cin >> a[i];
    }

    int cnt=0;
    int rmin = a[n-1];
    for ( int i=n-2; i>=0; i-- ) {
        cnt += max (0, a[i] - rmin );
        rmin = min ( rmin, a[i] );
    }

    // decrement 1 part
    

    cout << cnt;

    cout << "\n";
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