#include<bits/stdc++.h>
using namespace std;


// The check function is now corrected.
bool check(long long x, int k) {
    // FIX 1: Safely calculate y to prevent integer overflow.
    long long y = 1LL * k * x;

    // The problem requires y to be a positive integer less than 10^9.
    if (y <= 0 || y >= 1e9) {
        return false;
    }

    // FIX 2: Safely get the number of digits to avoid floating-point errors from log10().
    string y_str = to_string(y);
    int d = y_str.length();

    // FIX 3: Safely calculate 10^d to avoid precision errors from pow().
    long long power_of_10 = 1;
    for (int i = 0; i < d; ++i) {
        power_of_10 *= 10;
    }

    // FIX 4: Use the CORRECT mathematical formula for concatenation.
    long long concatenation = 1LL * x * power_of_10 + y;
    long long divisor = x + y;

    return concatenation % divisor == 0;
}

// The SOLVE function now uses a clear and correct loop.
long long SOLVE(long long x) {
    // FIX 5: Use a clear loop to search for the multiplier k, starting from 1.
    for (int k = 1; ; ++k) {
        // Call the corrected check function.
        if (check(x, k)) {
            // If it's a valid solution, return it.
            return 1LL * x * k;
        }
    }
    // This part is unreachable because a solution is always guaranteed to be found.
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long x;
        cin>>x;

        cout<<SOLVE(x);

        cout<<endl;


    }
    return 0;
}