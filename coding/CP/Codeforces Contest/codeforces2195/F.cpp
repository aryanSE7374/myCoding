/*
code by - Gemini
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


bool is_above(ll a1 , ll b1 , ll c1 , ll a2 , ll b2 , ll c2){

    ll da = a1 - a2 ;
    ll db = b1 - b2 ;
    ll dc = c1 - c2 ;

    if ( da < 0 ) return false ;

    if ( da == 0 ){
        if ( db != 0 ) return false ;
        return dc > 0 ;
    }

    return ( db * db - 4 * da * dc ) < 0 ;
}


void SOLVE(){

    int n;
    cin >> n;

    vll A(n) , B(n) , C(n);
    vi id(n);

    f(i,0,n){
        cin >> A[i] >> B[i] >> C[i];
        id[i] = i;
    }

    // sort by a, then c, then b
    vector<int> ord(n);
    f(i,0,n) ord[i] = i;

    sort(ord.begin(), ord.end(), [&](int i , int j){
        if ( A[i] != A[j] ) return A[i] < A[j];
        if ( C[i] != C[j] ) return C[i] < C[j];
        return B[i] < B[j];
    });

    vi L(n , 1) , R(n , 1);

    // forward dp
    f(ii,0,n){
        int i = ord[ii];
        f(jj,0,ii){
            int j = ord[jj];
            if ( is_above(A[i],B[i],C[i], A[j],B[j],C[j]) ){
                L[ii] = max( L[ii] , L[jj] + 1 );
            }
        }
    }

    // backward dp
    for ( int ii = n-1 ; ii >= 0 ; ii-- ){
        int i = ord[ii];
        for ( int jj = n-1 ; jj > ii ; jj-- ){
            int j = ord[jj];
            if ( is_above(A[j],B[j],C[j], A[i],B[i],C[i]) ){
                R[ii] = max( R[ii] , R[jj] + 1 );
            }
        }
    }

    vi ans(n);

    f(ii,0,n){
        ans[ id[ ord[ii] ] ] = L[ii] + R[ii] - 1 ;
    }

    f(i,0,n){
        cout << ans[i] << ( i==n-1 ? "" : " " );
    }
    cout << '\n';
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