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

vector<double> dp;

double fun ( int i, int n,  vi& c, vi& p ) {

    if ( i == n ) return 0.0;

    if ( dp[i] != -1.0 ) return dp[i];

    double notTake = fun (i+1, n, c, p);
    double take = c[i] + (1.0 - p[i] / 100.0) * fun (i+1, n, c, p);

    return dp[i] = max(notTake, take);
}

void SOLVE(){
    int n;
    cin >> n;
    
    vi c(n), p(n);
    f(i, 0, n) {
        cin >> c[i] >> p[i];
    }

    dp.assign(n, -1.0);

    double ans = fun(0, n, c, p);

    // cout << ans;
    printf("%.10f\n", ans);

    // cout << "\n";
    
    
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