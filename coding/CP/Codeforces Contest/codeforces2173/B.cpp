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

    ll n;
    ll k = 0;

    cin>>n;

    vll a(n);
    vll b(n);

    f(i,0,n){
        cin >> a[i];
    }

    f(i,0,n){
        cin >> b[i];
    }

    // ll ans = 0;

    f(i,0,n){
        k = max ( k-a[i] , b[i]-k  );
    }

    cout << k;

    


    co_endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}