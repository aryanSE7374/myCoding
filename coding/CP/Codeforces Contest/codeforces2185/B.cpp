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
#define nl cout << '\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int n;
    cin >> n;

    vi a(n);

    int maxi = 0;
    // int score = 0;

    f(i,0,n){
        cin >> a[i];
        maxi = max ( maxi , a[i] );
        // score += maxi;
    }

    cout << maxi*n ;


    nl;
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