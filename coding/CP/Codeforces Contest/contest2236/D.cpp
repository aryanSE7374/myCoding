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

int n, k;

vi cnt;
vvi dp;

int win (int val, int rem) {

    if (dp[val][rem] != -1) return dp[val][rem];

    if (rem > 0) {
        if ( !win(val, rem-1) ) {
            return dp[val][rem] = 1;
        }
    }

    f(j,val+1,min(n,val+k)+1){
        if (cnt[j] == 0) continue;
        if ( !win(j, cnt[j]-1) ) {
            return dp[val][rem] = 1;
        }
    }

    return dp[val][rem] = 0;
}

void SOLVE(){

    int N, K;
    cin >> N >> K;

    n = N;
    k = K;

    cnt.assign(n+1, 0);

    f(i,0,n){
        int x;
        cin >> x;
        cnt[x]++;
    }

    dp.clear();
    dp.resize(n+1);

    f(i,1,n+1){
        dp[i].assign(cnt[i]+1, -1);
    }

    bool flag = false;

    f(val,1,n+1){
        if (cnt[val] != 0) {
            if ( win(val, cnt[val]-1) ) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    cout << '\n';
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