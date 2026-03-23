/*
code by - Aryan Shrivastav
*/


/*
observations : 

ans = {ca,cb,cc} // cnt a, b, c

abc = LCM (a,b,c) 
ab = LCM (a,b) 
bc = LCM (b,c) 
ac = LCM (a,c) 


ca += (m/abc)*2
cb += (m/abc)*2
cc += (m/abc)*2

ca += ( (m/ab) - (m/abc) ) * 3 // max (this, 0)
cb += ( (m/ab) - (m/abc) ) * 3 // max (this, 0)

cb += ( (m/bc) - (m/abc) ) * 3 // max (this, 0)
cc += ( (m/bc) - (m/abc) ) * 3 // max (this, 0)

ca += ( (m/ac) - (m/abc) ) * 3 // max (this, 0)
cc += ( (m/ac) - (m/abc) ) * 3 // max (this, 0)

ca += ( (m/a) - (m/ab) - (m/ac) - (m/abc) ) * 6
cb += ( (m/b) - (m/ab) - (m/bc) - (m/abc) ) * 6
cc += ( (m/c) - (m/ac) - (m/bc) - (m/abc) ) * 6





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

ll gcd ( ll a, ll b ) {
    if ( b==0 ) return a;
    return gcd ( b, a%b );
}

ll LCM (ll a, ll b) {
    return a*b/gcd(a,b);
}


void SOLVE(){

    ll a, b , c, m;

    cin >> a >> b >> c >> m;

    ll ca = 0;
    ll cb = 0;
    ll cc = 0;

    ll abc = LCM ( LCM(a, b), c ); // LCM (a,b,c) 

    ll ab = LCM (a,b) ;
    ll bc = LCM (b,c) ;
    ll ac = LCM (a,c) ;


    ll ma = m/a;
    ll mb = m/b;
    ll mc = m/c;

    ll mab = m/ab;
    ll mbc = m/bc;
    ll mac = m/ac;

    ll mabc = m/abc;
    
    // ca += (mabc)*2LL;
    // cb += (mabc)*2LL;
    // cc += (mabc)*2LL;

    // ca += max ( 0LL, ( (mab) - (mabc) ) * 3LL ); // max (this, 0)
    // cb += max ( 0LL, ( (mab) - (mabc) ) * 3LL ); // max (this, 0)

    // cb += max ( 0LL, ( (mbc) - (mabc) ) * 3LL );  // max (this, 0)
    // cc += max ( 0LL, ( (mbc) - (mabc) ) * 3LL );  // max (this, 0)

    // ca += max (0LL, ( (mac) - (mabc) ) * 3LL); // max (this, 0)
    // cc += max (0LL, ( (mac) - (mabc) ) * 3LL); // max (this, 0)

    // ca += max ( 0LL, ( (ma) - (mab) - (mac) - (mabc) ) * 6LL);
    // cb += max ( 0LL, ( (mb) - (mab) - (mbc) - (mabc) ) * 6LL);
    // cc += max ( 0LL, ( (mc) - (mac) - (mbc) - (mabc) ) * 6LL);


    // ca = max ( 0LL , (ma - mab - mac - mabc)*6LL ) + max ( 0LL , ( ma - mab )*3LL ) ;

    // ca = ma*6LL - mab*3LL - mabc*1LL;
    // cb = mb*6LL - mab*3LL - mabc*1LL;
    // ca = ma*6LL - mab*3LL - mabc*1LL;


    cout << ca << " " << cb << " " << cc << " ";

    

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