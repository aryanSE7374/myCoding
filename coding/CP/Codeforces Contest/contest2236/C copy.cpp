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

    ll a, b, x;

    cin >> a >> b >> x;


    vll da;
    vll db;

    ll num = a;
    while (num > 0) {
        da.push_back(num);
        num /= x;
    }

    num = b;
    while (num > 0) {
        db.push_back(num);
        num /= x;
    }

    da.push_back(0);
    db.push_back(0);

    ll ans = LLONG_MAX;

    int n = da.size();
    int m = db.size();

    f(i,0,n){
        f(j,0,m){
            ans = min ( ans, i + j + abs(da[i] - db[j]));
        }
    }

    cout << ans;

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