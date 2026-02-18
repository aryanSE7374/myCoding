/*
code by - Aryan
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

    ll p,q;
    cin >> p >> q;

    if ( p<2 || q<3 ) {
        cout << "Alice\n";
        return;
    }

    // cerr<<"p: "<<p<<"\nq:"<<q<<"\n";

    // ll MOD = 1e5;
    // p = p%MOD ;
    // q = q&MOD ;
    // p = min (p , MOD );
    // q = min ( q,MOD);

    // cerr<<"p: "<<p<<"\nq:"<<q<<"\n";

    ll dem = q - (q%3);
    // cerr<<"dem: "<<dem<<"\n"<<"loop start:\n";
    ll num = (dem*2)/3;

    if ( num > p ) {
        num = p;
        dem = num*3/2;
    }

    if ( (p-num) == (q-dem) ) cout << "Bob\n";
    else cout << "Alice\n";

    // while ( dem >= 3 ) {
    //     ll num = (dem*2)/3;
    //     // cerr<<"num: "<<num<<"\ndem:"<<dem<<"\n";
    //     if ( (p-num) == (q-dem) ) {
    //         // cerr << "condition true\n";
    //         cout << "Bob\n";
    //         return;
    //     }
    //     dem -= 3;
    // }

    // cout << "Alice\n";
    // cout<<'\n';

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