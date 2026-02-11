#include <bits/stdc++.h>
using namespace std;

void SOLVE() {
    int x,y,z;
    cin >> x >> y >> z;
    int xz = min ( x,z );
    int yy = y/2;
    // int xy = max ( 0 , min ( x-xz , y-(2*yy) ) ) ;
    
    cout << xz+yy<< "\n";
    
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    SOLVE();
	}
}
