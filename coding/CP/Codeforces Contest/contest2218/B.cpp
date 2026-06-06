/*
code by - Aryan Shrivastav
*/

/*
observations : 

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

    vi a(7);
    int negSum = 0;
    f(i,0,7){
        cin >> a[i];
        negSum -= a[i];
    }

    int maxi = -1e9;

    for ( int i=0; i<7; i++ ) {
        maxi = max(maxi, negSum + 2*a[i] );
    }

    // for ( int i=0; i<7; i++ ) {
    //     int curr = 0;
    //     for (int j=0; j<7; j++ ) {
    //         if ( i==j ) {
    //             curr += a[i];
    //         }
    //         else {
    //             // curr += (-1*a[i]);
    //             curr -= a[i];
    //         }
    //     }
    //     maxi = max ( maxi, curr);
    //     cout << "maxi: " << maxi <<endl;
    // }


    cout << maxi;


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