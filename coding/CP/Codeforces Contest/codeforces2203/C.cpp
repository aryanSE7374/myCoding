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

    ll s,m ;

    cin >> s >> m ;

    // if s is odd and m is even 
    if ( (s%2 == 1) && (m%2 == 0) ) {
        cout << -1 << "\n";
        return;
    }

    if ( m==1 ) {
        cout << s << "\n";
        return;
    }

    // int firstBit = 0;
    ll num = m;
    ll expo = 1;

    while ( num%2 == 0 ) {
        num = num>>1;
        expo = expo<<1;
    }

    // 18, 12 case
    if ( (s%expo) != 0 ) {
        cout << -1 << "\n";
        return;
    }

    // double val = s*1.0 / m*1.0 ;
    // cout << ll(val) + 1;
    // cout << ceil (val);
    s = s/expo ;
    m = m/expo ;

    /*
    ll val = (s+m-1)/m; // ceil
    // if ( ( ( s-m-( val*m) ) & m ) == ( s-m-(val*m) )  ) cout << val;
    // else cout << (val+1);
    cout << val;
    */

    ll val = 0;
    
    f(i,0,61) {

        ll bit = ( 1ll << (i+1)) - 1; 
        
        ll Mi = m & bit; 
        ll Si = s & bit; 
        
        if ( Mi > 0 ) {
            ll curr = ( Si + Mi - 1 ) / Mi;
            val = max( val , curr );
        }
    }
    
    cout << val;

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