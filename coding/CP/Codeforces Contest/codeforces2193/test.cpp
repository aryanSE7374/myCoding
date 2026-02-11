#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// tuple< int,int,int > max3 (int w , int l , int h ) {
//     int a,b,c;
//     a = max { w , l, h };
    
//     if ( w!=a ) {
//         b=w;
//     }
//     if ( l!=a ){
//         b=max ( b,l );
//     }
//     if ( h!=a ) {
//         b=max(b,h);
//     }
    
//     c = w+l+h-a-b;
    
//     return {a,b,c};
// } 

void SOLVE() {
    
    int n,m;
    // string ans(m,'.');
    cin >> n >> m ;
    
    vector<vector<int>> boxes(m,vector<int>(3));
    
    for ( int i=0 ; i<m ; i++ ) {
        int wi,li,hi;
        cin >> wi >> li >> hi ;
        // boxes[i] = { wi , li , hi };
        boxes[i][0] = wi;
        boxes[i][1] = li;
        boxes[i][2] = hi;
    }
    
    vector<int> fib(n);
    fib[0] = 1;
    fib[1] = 2;
    
    for ( int i=2; i<n ; i++ ) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    for ( int i=0 ; i<m ; i++ ) {
        
        int w=boxes[i][0];
        int l=boxes[i][1];
        int h=boxes[i][2];
        
        int a,b,c;
        a = max ( { w , l, h } );
        b = a;

        if ( w!=a ) {
            b=w;
        }
        else if ( l!=a ){
            b=max ( b,l );
        }
        // if ( h!=a ) {
        else{
            b=max(b,h);
        }

        c = w+l+h-a-b;
        
        bool ans = true;
        
        if ( n==2 ) {
            if ( a < fib[n-1]+fib[n-2] ) ans = false;
            if ( b<fib[n-2] || c<fib[n-2] ) ans = false;
        }
        else if ( n==3 ) {
            if ( a < fib[n-1]+fib[n-2] ) ans = false;
            if ( b < fib[n-2]+fib[n-3] ) ans = false;
            if ( c<fib[n-3] ) ans = false;
        }
        else {
            if ( a < fib[n-1]+fib[n-2] ) ans = false;
            if ( b < fib[n-2]+fib[n-3] ) ans = false;
            if ( c < fib[n-3]+fib[n-4] ) ans = false;
        }
        
        if ( ans ) cout << '1';
        else cout << '0';
        
    }

    cout << "\n";
    
    
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while ( t-- ) {
        SOLVE();
    }
    return 0;
}