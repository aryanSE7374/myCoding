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

    f(i,0,n) {
        cin >> a[i] ;
    }

    sort( a.begin() , a.end() ) ;

    vi a2;
    a2.push_back(a[0]);

    f(i,1,n){
        if ( a[i] != a2.back() ) {
            a2.push_back(a[i]);
        }
    }

    int m = a2.size() ;

    int maxlen = 1 ;

    int cnt = 1;

    f(i,1,m){
        if ( a2[i-1]+1 == a2[i] ) {
            cnt++;
            maxlen = max ( maxlen , cnt ) ;
        }
        else{
            cnt = 1;
        }
    }

    cout << maxlen ;


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