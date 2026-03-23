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

int n;
vll val;
vi take;
ll ans;

bool check ( int idx ) {
    // check prev 4 indices pls current idx
    // f(i,idx-4;idx+1){
    for(int i = idx - 4; i <= idx; i++){
        int cnt = 0;
        for ( int j = 0 ; j < 5 ; j++ ) {
            int k = (i+j)%n;
            if ( k<0 ) k += n;
            cnt += take[k];
        }
        if(cnt > 2) return false;
    }
    return true;
}

void func ( int idx , ll sum ) {

    if ( idx == n ) {
        ans = max( ans , sum );
        return;
    }

    // not take
    take[idx] = 0;
    func ( idx+1 , sum );

    // take
    take[idx] = 1;
    
    if ( check(idx) ) {
        func ( idx+1 , sum+val[idx] );
    }

    take[idx] = 0; // backtrack

}

void SOLVE(){

    cin >> n;

    val.resize(n);
    take.assign(n,0);

    f(i,0,n) cin >> val[i];

    ans = 0;
    func(0,0);

    cout << ans << '\n';
    
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