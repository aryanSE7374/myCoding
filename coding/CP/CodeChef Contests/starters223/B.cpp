#include <bits/stdc++.h>
using namespace std;

void SOLVE () { 
    
    int n , x , k;
    cin >> n >> x >> k;
    int rem = x%k;

    int add = ( x+k-rem <= n ) ? k-rem : INT_MAX ;
    
    cout << min ( rem , add );
    cout << "\n";
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while ( t-- ) {
	    SOLVE();
	}

}
