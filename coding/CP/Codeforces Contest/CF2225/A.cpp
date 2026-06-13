/*
code by - Aryan Shrivastav
*/

/*
observations : 
find prime factors of x => fx and factors od y => fy
if there exists an element in fx that is not in fy, then yes else no

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

    ll x, y;
    cin >> x >> y;

    // fill prime factors of x
    // vll fx = fillPFs(x);
    
    // // fill prime factors of y
    // vll fy = fillPFs(y);

    // sort(fx.begin(), fx.end());
    // sort(fy.begin(), fy.end());

    // int N1 = fx.size();
    // int N2 = fy.size();

    // if ( N1==0 ) {
    //     if ( y-x > 1 ) cout << "YES\n";
    //     else cout << "NO\n";
    //     return;
    // }


    // for ( int i=0; i<N1; i++ ) {
    //     if ( BS(fy, fx[i]) != -1 ) {
    //         cout << "YES\n";
    //         return;
    //     }
    // }

    // check feasibility
    // int i=0;
    // while ( i<MAXN && spf[i]<=fx[N1-1] ) i++;

    // while ( i<MAXN && spf[i] < fy[N2-1] ) {
    //     if ( BS( fy, 1LL*spf[i]) == -1) {
    //         cout << "YES\n";
    //         return;
    //     }
    //     i++;
    // }

    
    if ( y == 2LL*x ) cout << "NO";
    // else if (isPrime(y/x)) {
    //     cout << "NO";
    // }
    else cout << "YES";

    // cout << "NO";

    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // fillSPF();
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}