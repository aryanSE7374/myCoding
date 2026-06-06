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

ll gcd(ll a, ll b){ 
    return b ? gcd(b, a % b) : a ; 
}
ll lcm(ll a, ll b){ 
    return a / gcd(a,b) * b; 
}

void SOLVE(){

    int n;

    cin >> n;

    vi a(n), b(n);

    f(i,0,n){
        cin >> a[i];
    }
    f(i,0,n){
        cin >> b[i];
    }

    int ans = 0;

    vi GCD (n, 0);

    int allGCD = a[0];

    f(i,0,n-1) {
        GCD[i] = gcd(a[i], a[i+1]);
        allGCD = gcd ( GCD[i], allGCD );
    }

    // GCD[n-1] = GCD[n-2];

    f(i,0,n){

        if ( i == 0 ) {
            if( GCD[0] < a[0]) ans++;
        }

        else if ( i == n-1 ) {
            if ( GCD[n-2] < a[n-1] ) ans++;
        }

        else {
            ll LCM = lcm( GCD[i-1], GCD[i] );
            if ( LCM < a[i] ) ans++;
        }

        // if ( ( GCD[i]  < a[i] ) && (GCD[i-1] <= GCD[i]) && (GCD[i] >= allGCD) )  {
        //     ans++;
        // }
    }


    cout << ans;


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