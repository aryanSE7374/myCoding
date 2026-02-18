/*
code by - Aryan Shrivastav
*/

/*
observations : 


// alternating difference

for 1 <= k < n : 
    f(k) - f(k+1) = -1 * summation{i=1 to k}( a[i] ) + summation{i=k+1 to n }(a[i])


    // need a difference table here

    
    also 
    
    let S = sum of all { i=1 to n}  f(i) = a[1]*{ 1+2+3+...n-1} + a[2]*{ 1+1+2+3+...n-2} + ... a[i] * { i-1 + i-2 + ..... 1 + 1 + 2 + .... n-i } + .... a[n] * {n-1 + n-2 + ..... + 1}

    
NOTE ** f(i) -> coeff of i is zero

// symmetic about i => coeff(a[i]) in f(i-x) == coeff(a[i]) in f(i+x) for all x < i <= n/2

how to find individual i ??? 

** (f(1)-f(2)) - (f(2)-f(3)) = f1 - f3 = -2 * a[1] => a[1] = f3 - f1 / 2 // WRONG

--------

def : f(ij) = f(i)-f(j)

f12 - f23 = 2*a[2]

f12 + f23 = -2*a[1] + 2 * sum ( a[3] + .... a[n] )

f(ij) - f(jk) = 2*a[j] for all  i = j-1 and k = j+1 and 2<=j<=(n-1)

this way we can find a[2] ..... a[n-1]

now only a[1] and a[n] left ...

a[n] find using f(1) and a[1] find using a[n]


solved!!



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
// #define f(i,a,n) for(int i=a ; i<n ; i++)


void SOLVE(){

    ll n;
    cin >> n;

    vll f(n+1); // 1-based

    for ( int i=0 ; i<n ; i++ ) {
        cin >> f[i+1];
    }

    // ---- //

    vll ans(n+1);

    // f(ij) - f(jk) = 2*a[j] for all  i = j-1 and k = j+1 and 2<=j<=(n-1)

    for ( ll j = 2 ; j<n ; j++ ) {
        ll i = j-1 , k = j+1 ;
        // ans[j] = f[i] - f[j] - f[j] + f[k] ;
        ans[j] = ( f[i] - 2*f[j] + f[k] ) / 2 ;
    }

    // only 1 and n


    ll sum = 0;

    // for n
    for ( int i=2 ; i<= n-1 ; i++ ) {
        sum += (i-1)*ans[i];
    }

    ans[n] = ( f[1] - sum ) / (n-1) ;

    // for 1
    sum = 0;
    for ( int i=2 ; i<= n-1 ; i++ ) {
        sum += (n-i)*ans[i];
    }

    ans[1] = ( f[n] - sum ) / (n-1) ;

    // ---- //

    // output 

    for ( int i=0 ; i<n ; i++ ) {
        cout << ans[i+1] << " " ;
    }

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