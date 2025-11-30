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

    if(n<2){
        cout<<0<<"\n";
        return;
    }

    int a = 0 ; int b = 0;
    int ans = 0;

    f(i,0,n){
        f(j,0,n){
            if(2*i + 4*j == n) ans++;
        }
    }

    cout<<ans;


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