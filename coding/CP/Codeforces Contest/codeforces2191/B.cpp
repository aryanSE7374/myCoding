/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n ;
    cin >> n;

    vi a(n);
    vi freq(n+1,0);

    bool ans = true;

    f(i,0,n) {
        cin >> a[i];
        if (a[i] <= n) freq[a[i]]++;
    }

    // sort ( a.begin() , a.end() ) ;

    // if (n == 2) {
    //     if ( (a[0] == 0) && (a[1] == 0) ) cout << "NO\n";
    //     else cout << "YES\n";
    //     return;
    // }

    if ( freq[0] == 0 ) {
        cout << "NO\n";
        return ;
    }

    if ( freq[0] > 1 && freq[1] < 1 ) {
        cout << "NO\n";
        return ;
    }

    cout << "YES";

    // f(i,0,n+1){
    //     if ( freq[i] == 1 ){
    //         ans = false;
    //         break;
    //     }
    // }

    // if (ans) {
    //     cout << "YES";
    // }
    // else cout << "NO";

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}