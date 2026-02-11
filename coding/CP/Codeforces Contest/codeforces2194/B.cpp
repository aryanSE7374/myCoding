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

    ll n , x, y;

    cin >> n >> x >> y;

    vll a(n);

    vll maxtransf(n);
    vll balance(n);

    ll sum1 = 0;

    f(i,0,n){
        cin >> a[i];
        maxtransf[i] = a[i]/x;
        balance[i] = a[i]%x;
        sum1 += maxtransf[i];
    }

    ll maxi = 0;

    f(i,0,n){
        ll curr = a[i] + ( sum1 - maxtransf[i] )*y;
        maxi = max (maxi , curr);
    }

    cout << maxi;
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