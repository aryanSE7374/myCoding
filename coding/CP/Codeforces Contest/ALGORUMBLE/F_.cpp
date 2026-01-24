// chatGPT solution

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

bool updateMap( int maskA , int maskB ) {
    return ( maskA & maskB );
}

void SOLVE() {

    int n;
    cin >> n;

    vector<string> S(n);
    vector<int> mask ( n , 0 ) ;

    f(i,0,n){
        cin >> S[i];

        for (char c : S[i]) {
            mask[i] = mask[i] | (1 << (c - 'a'));
        }
    }

    ll ans = 0;

    f(i,0,n){
        for (int j = i + 1; j < n; j++) {

            if ( !updateMap( mask[i], mask[j] ) ) {
                ll prod = 1LL * S[i].size() * S[j].size();
                ans = max(ans, prod);
            }

        }
    }

    cout << ans;
    co_endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t-- > 0) {
        SOLVE();
    }

    return 0;
}