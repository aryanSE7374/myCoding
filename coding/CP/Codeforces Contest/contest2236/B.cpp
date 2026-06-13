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

    string s;
    int n, k;

    cin >> n >> k;
    cin >> s;

    int cnt1 = 0;

    f(i,0,n-k){
        if(s[i] == '1') {
            s[i] = '0';
            s[i+k] = (s[i+k] == '0') ? '1' : '0';
        }
    }

    f(i,0,n){
        if (s[i] == '1') {
            cout << "NO\n";
            return;
        }
    }

    // f(i,0,n-k){
    //     // if(s[i] == '1') cnt1++;
    //     if ( s[i] != s[i+k] ) {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    cout << "YES";

    // f(i, n-k, n) {
        // if (s[i] == '1') {
        //     cout << "NO\n";
        //     return;
        // }
    // }

    // if ( cnt1 % 2 == 0 && s[n-1] == '0' ) {
    //     cout << "YES";
    // }
    // else if ( cnt1 % 2 == 1 && s[n-1] == '1' ) {
    //     cout << "YES";
    // }
    // else cout << "NO";

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