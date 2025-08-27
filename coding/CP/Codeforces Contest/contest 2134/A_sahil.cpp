#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    if(n%2!=b%2){ 
        cout << "NO\n";
    }
    else if(a<=b){
        cout << "YES\n";
    }
    else if(n%2==a%2){
        cout << "YES\n";
    } 
    else{
        cout << "NO\n";

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int maharaja;
    cin >> maharaja;
    while (maharaja--) {
        solve();
    }
    return 0;
}