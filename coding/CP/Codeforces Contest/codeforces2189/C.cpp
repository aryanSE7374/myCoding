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

    ll n ;
    cin >> n;

    vll p(n);
    p[n-1] = 1;

    ll sum = 1;

    for  ( ll i=2 ; i<n ; i++ ) {
        p[i-1] = p[n-1] ^ i ;
        sum += p[i-1];
    }

    ll one = n*(n+1)/2 - sum ;
    p[0] = one ;

    f(i,0,n) cout << p[i] << " " ;

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}