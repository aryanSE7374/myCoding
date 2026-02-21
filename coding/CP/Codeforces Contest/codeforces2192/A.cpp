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

    int n;
    cin >> n;
    string s;
    cin >> s;

    // vi freq(27,0);
    unordered_map<char,int> freq;

    f(i,0,n){
        // if ( freq[s[i]-'a'] == 0 ) cnt++;
        // freq[s[i]-'a']++;
        freq[s[i]]++;
    }
    
    int cnt = freq.size();

    // f(i,0,27){
    //     if ( freq[i] > 0 ) cnt++;
    // }

    // int i=1;
    // int blocks = 1;

    // while ( i<n ) {
    //     while ( i<n && (s[i-1] == s[i]) ) {
    //         i++;
    //     }
    //     i++;
    //     blocks++;
    // }

    int blocks = 1;
    f(i,1,n){
        if (s[i] != s[i-1]) blocks++;
    }

    // cout << min ( n , blocks+1 ) << " " << cnt << " " << blocks

    int ans = blocks;
    if ( s[0] != s[n-1 ] ) {
        cout << min ( n , blocks+1 ) ;
    }
    else {
        cout << min ( n , blocks ) ;
    }

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