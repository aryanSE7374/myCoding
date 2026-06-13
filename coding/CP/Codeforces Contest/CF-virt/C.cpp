/*
code by - Aryan Shrivastav
*/

/*
observations : 


total no. of unit segments in an m*n grid = 2*m*n + m+n

if there exists no integers m,n s.t. c = (p + 2*q) = 2*m*n + m+n 

we want ot find such integer paris



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


bool check ( ll p, ll q, ll m, ll n ) {
    return ( p >= abs(m-n) );
}


void SOLVE(){

    ll p, q;

    cin >> p >> q;


    ll c = p + 2*q;

    ll Nr = 2*c + 1; // always odd

    // find a divisor (Nr>d>1) of Nr

    ll d = -1;

    for ( int i=2; i*i <= Nr; i++ ) {
        if ( Nr%i == 0 ) {
            d = i;

            ll m = (d-1) / 2;
            ll n = ( (Nr/d) - 1 ) / 2;

            if ( check(p, q, m, n) ) {
                cout << m << " " << n << endl;
                return;
            }

        }
    }

    if ( d== -1 ) {
        cout << -1 << endl;
        return;
    }

    // ll m = (d-1) / 2;
    // ll n = ( (Nr/d) - 1 ) / 2;

    // cout << m << " " << n;

    // cout<<'\n';
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