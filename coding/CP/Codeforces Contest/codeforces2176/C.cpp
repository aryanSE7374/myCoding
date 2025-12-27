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
    cin>>n;

    vi a(n);

    f(i,0,n){
        cin >> a[i] ;
    }

    vi ans(n);

    // algo here

    


    f(i,0,n){
        cout << ans[i] << " ";
    }

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