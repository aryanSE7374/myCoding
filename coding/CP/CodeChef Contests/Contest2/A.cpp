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

 
    int R,B,G;

    cin >> R >> B >> G;

    int mini = min(R , min(B,G));

    int ans = mini * 10 + (R-mini)*3 + (B-mini)*3 + (G-mini)*3;

    cout << ans;

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