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

    ll n , k ;

    cin >> n >> k ;

    // Check depths from t=0 to t=32 (since 2^30 > 10^9)
    for (int t = 0; t <= 32; t++) {
        ll p2 = 1LL << t; // 2^t

        // Calculate the two possible pile sizes at this depth
        ll option1 = n / p2;                // Floor division
        ll option2 = (n + p2 - 1) / p2;     // Ceil division

        if (option1 == k || option2 == k) {
            cout << t;
            co_endl;
            return;
        }

        // Optimization: If the largest possible pile at this depth is smaller than k,
        // dividing further will only make piles smaller. We can stop.
        if (option2 < k) break;
    }

    cout << -1;

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