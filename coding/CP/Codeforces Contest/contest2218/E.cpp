/*
code by - Aryan Shrivastav
*/

/*
observations : 

can we dp.. 

but we have a diffrent array/state means the array is dynamic and chages values after every operation


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

    int n;
    cin >> n;

    vi a(n);

    int xrr = 0;
    f(i,0,n) {
        cin >> a[i];
        // xrr ^= a[i];
    }


    f(i,0,n){
        f(j,0,n) {
            // cout << (a[i] ^ a[j]) << " ";
            xrr = max ( xrr, a[i] ^ a[j]);
        }
        // cout << "\n";
    }

    cout << xrr;
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