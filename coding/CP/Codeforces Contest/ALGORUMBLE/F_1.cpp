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

bool check( vector<bool> &v1 ,  vector<bool> &v2 ){
    for (int k = 0 ;  k < 26 ; k++){
        if ( v1[k] && v2[k] ) return true; 
    }
    return false;
}

void SOLVE() {

    int n;
    cin >> n;

    vector<string> S(n);
    
    vector<vector<bool>> freq( n , vector<bool>(26 , false));

    f(i,0,n){
        cin >> S[i];
        for ( char c : S[i] ) {
            freq[i][c - 'a'] = true;
        }
    }

    ll ans = 0;

    f(i,0,n){

        for ( int j=i+1 ; j<n ; j++ ){
            
            if ( !check( freq[i] , freq[j] ) ){
                ll prod = 1LL * S[i].size() * S[j].size();
                ans = max( ans , prod ) ;
            }

        }
    }
    
    cout << ans ;

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