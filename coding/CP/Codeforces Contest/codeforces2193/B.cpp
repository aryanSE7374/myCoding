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

    int n;

    cin >> n;

    vi p(n);
    // vi a(n);

    f(i,0,n){
        cin >> p[i] ;
    }

    int i = 0;
    while ( i<n ) {
        if ( p[i] != n-i ) {
            break;
        }
        i++;
    }

    if ( i==n ) {

        f(j,0,n){
            cout << p[j] << " ";
        }

        co_endl;
        return;
    }
    int find = n-i;
    int idx = i;

    f(j,i,n){
        if( p[j] == find ) {
            idx = j;
            break;
        }
    }

    reverse( p.begin() + i , p.begin() + idx + 1 ) ;

    f(j,0,n){
        cout << p[j] << " ";
    }

    co_endl;
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