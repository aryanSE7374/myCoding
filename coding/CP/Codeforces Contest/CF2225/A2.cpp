/*
code by - Aryan Shrivastav
*/

/*
observations : 
find prime factors of x => fx and factors od y => fy
if there exists an element in fx that is not in fy, then yes else no

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

ll BS (vll &a, ll x ) {
    int l = 0, r = a.size() - 1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] == x) return mid;

        else if (a[mid] < x) l = mid + 1;

        else r = mid - 1;

    }

    return -1;
}


vll fillPFs(ll n) {

    vll factors;

    for ( ll i=2; i*i <= n; i++) {

        if ( n%i == 0 ) {
            factors.push_back(i);
            while (n%i == 0) {
                n /= i;
            }
        }

    }

    if (n > 1) factors.push_back(n);
    return factors;

}


void SOLVE(){

    ll x, y;
    cin >> x >> y;

    // fill prime factors of x
    vll fx = fillPFs(x);
    
    // fill prime factors of y
    vll fy = fillPFs(y);

    sort(fx.begin(), fx.end());
    sort(fy.begin(), fy.end());

    int N1 = fx.size();
    int N2 = fy.size();

    if ( N1==0 ) {
        if ( y-x > 1 ) cout << "YES\n";
        else cout << "NO\n";
        return;
    }


    for ( int i=0; i<N1; i++ ) {
        if ( BS(fy, fx[i]) != -1 ) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO";

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
