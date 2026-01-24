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

    int n , m; 
    cin >> n >> m ;

    vi a(n) , b(m) ;

    f(i,0,n) {
        cin >> a[i] ;
    }

    f(i,0,m) { 
        cin >> b[i] ;
    }

    vi pref(n,0) ;

    sort ( a.begin() , a.end() ) ;
    sort ( b.begin() , b.end() ) ;

    int i = 0 , j = 0 ;

    while ( i<n && j<m ) {
        if ( a[i] <= b[j] ) {
            pref[i] = j;
            i++;
        }
        else {
            j++;
        }
    }

    while ( i<n ) {
        pref[i] = m ; // j
        i++;
    }

    int count = 0 ;

    f(i,0,n) count += pref[i] ;

    cout << count ;

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