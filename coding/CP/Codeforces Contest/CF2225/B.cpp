/*
code by - Aryan Shrivastav
*/

/*
observations : 


run a linear loop to check alternating 
violation of this rule is acceptable only once

if this violation is greater than one, return false;

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
    cin >> s;
    int n = s.size();
    
    int cnt = 0;

    // int l=0;

    // for ( int r=1; r<n; r++ ) {
    //     if ( (r>1) && (r<n-1) && s[r-1] == s[r] ) {
    //         cnt++;
    //         // r++;
    //     }
    // }

    for ( int r=2; r<n-1; r++ ) {
        // if ( s[r] == s[r-1] ) {
        //     int curr = 1;
        //     while ( r<n && s[r] == s[r-1] ) {
        //         curr++;
        //         r++;
        //     }
        //     if ( curr > 2 ) {
        //         cout << "NO\n";
        //         return;
        //     }
        //     cnt++;
        // }
        int curr = 0;
        while ( r<n-1 && s[r-1] == s[r] ) {
            curr++;
            r++;
        }
        if ( curr > 2 ) {
            cout << "NO\n";
            return;
        }
        if ( curr > 0 ) cnt++;
        
    }

    // frst last same edge case

    // cout << cnt << endl;

    if ( cnt > 1 ) {
        cout << "NO";
    }
    // else if ( (s[0] == s[1]) && (s[n-1] == s[n-2]) && cnt > 0 ) {
    //     cout << "NO";
    // }
    else cout << "YES";

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