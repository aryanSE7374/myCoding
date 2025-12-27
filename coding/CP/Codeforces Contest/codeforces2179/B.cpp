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

    int n;
    cin >> n;
    vi a(n);


    f(i,0,n){
        cin >> a[i];
    }

    int del = 0;
    ll sum = 0;

    f(i,0,n-2){
        del = max( del , ( abs(a[i]-a[i+1]) + abs( a[i+1]-a[i+2] ) - abs( a[i]-a[i+2] ) )  ) ;
        sum += 1LL*abs(a[i]-a[i+1]);
    }
    sum += 1LL*abs(a[n-2]-a[n-1]);

    del = max( del, abs(a[0] - a[1]) ) ;
    del = max( del, abs(a[n-2] - a[n-1] ) );

    cout << sum - del;

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