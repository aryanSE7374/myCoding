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

    int n , m , p , q;

    cin >> n >> m >> p >> q;

    int check = (n/p) * q;

    int modd = n % p;

    // if ( m == q ) {
    //     cout << "YES\n";
    //     return;
    // }

    if ( n % p == 0 ) {
        if ( m - check != 0 ) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES";



    // vi v(n);
    // int x = ceil(n*1.0/p*1.0);
    // if ( x * q == m ) cout << "YES";
    // else cout << "NO";
    // if ( m%n == 0 && p*m/n == q ) cout << "YES";
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