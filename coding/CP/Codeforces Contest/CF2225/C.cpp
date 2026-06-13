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

bool isValid (int r, int c, int n){
    return (
        r>=0 && r<2 && c>=0 && c<n
    );
}

void SOLVE(){

    int n;
    cin >> n;

    // vvi dp(2, vi(n));;
    vi a(n), b(n);

    f(j,0,n) {
        char c;
        cin >> c;
        if ( c == 'R' ) a[j] = 0;
        else a[j] = 1;
    }

    f(j,0,n) {
        char c;
        cin >> c;
        if ( c == 'R' ) b[j] = 0;
        else b[j] = 1;
    }

    // int cnt = 0;

    // int di[] = {-1, 0, 1, 0};
    // int dj[] = {0, 1, 0, -1};

    // for ( int i=0; i<2; i++ ) {
    //     for ( int j=0; j<n; j++ ) {
    //         int mini = 1;
    //         int change = dp[i][j];
    //         for ( int k=0; k<4; k++ ) {
    //             int r = i + di[k], c = j + dj[k];
    //             if ( isValid(r, c, n) ) {
    //                 if ( dp[r][c] == dp[i][j] ) {
    //                     mini = min ( mini, 0 ); 
    //                     break;
    //                 }
    //                 else {
    //                     change = dp[r][c];
    //                 }
    //             }
    //         }
    //         if ( mini == 1 ) {
    //             // dp[i][j] = (dp[i][j] + 1)%2;
    //             dp[i][j] = change;
    //             cnt++;
    //         }
    //     }
    // }

    // cout << cnt;

    vi dp(n+1, 0);

    int di[] = {0, 0};
    int dj[] = {-1, 0};

    f(i,1,n+1){

        int take0 = 0; // make both 0
        if ( (a[i-1] == 1) ) take0++;
        if ( b[i-1] == 1 ) take0++;

        int take1 = 0; // make both 1
        if ( (a[i-1] == 0) ) take1++;
        if ( b[i-1] == 0 ) take1++;
        dp[i] = dp[i-1] + min(take0, take1);

        if ( i<2 ) continue;

        int U0 = 0, U1 = 0;
        int D0 = 0, D1 = 0;

        for ( int k = 0; k<2; k++ ) {
            int c = i - 1 + dj[k];
            U0 += (a[c] == 1);
            U1 += (a[c] == 0);
            D0 += (b[c] == 1);
            D1 += (b[c] == 0);
        }

        int costH = min ( U0, U1 ) + min ( D0, D1 );
        dp[i] = min (dp[i] , dp[i-2] + costH);

    }

    cout << dp[n] ;
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