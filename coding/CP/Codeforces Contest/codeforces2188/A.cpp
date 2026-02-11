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

    // p[n-1] = n;
    
    // n , 1 , n-1 , 2 , n-2 , 3 , .... 

    if ( n%2 == 0 ) {
        int j=n;
        // for ( int i=0 ; i<n ; i+=2 ) {
        for ( int i=n-1 ; i>=0 ; i-=2 ) {
            p[i] = j ;
            // p[n-i-1] = j;
            j--;
        }
    
        j=1;
        for ( int i=n-2 ; i>=0 ; i-=2 ) {
            p[i] = j;
            j++;
        }
    
        for ( int i=0 ; i<n ; i++ ) {
            cout << p[i] << " " ;
        }
    }

    else { 

        int j=1;
        for ( int i=n-1 ; i>=0 ; i-=2 ) {
            p[i] = j;
            j++;
        }
        
        j=n;
        // for ( int i=0 ; i<n ; i+=2 ) {
        for ( int i=n-2 ; i>=0 ; i-=2 ) {
            p[i] = j ;
            // p[n-i-1] = j;
            j--;
        }

        for ( int i=0 ; i<n ; i++ ) {
            cout << p[i] << " " ;
        }
    
        
    }
    // for ( int i= n-2 ; i>=0 ; i-- ) {
    //     p[i] = i;
    // }

    // for ( int i=1 ; i<n ; i++ ) { 
    //     p[n-i-1] = i;
    //     p[n-i-2] = n-i;
    // }

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