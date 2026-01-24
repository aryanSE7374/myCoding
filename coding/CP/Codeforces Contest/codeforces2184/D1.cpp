#include <bits/stdc++.h>
using namespace std;
/*

7
4 1
4 2
4 3
4 4
4 5
16 5
16 1

---


3
2
0
0
0
4
15

*/

// Precompute Combinations nCr
long long C[35][35];

void precompute() {
    for (int i = 0; i <= 32; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

void solve() {
    long long n, k;
    cin >> n >> k;

    // Find d such that n = 2^d
    int d = 0;
    while ((1LL << (d + 1)) <= n) {
        d++;
    }
    // Note: If n is exactly 2^d, the loop finds that d correctly.
    // e.g., n=4 (100), d=2.
    
    long long ans = 0;

    // 1. Check n itself
    // n has MSB at index d. Popcount is 1. Moves = d + 1.
    if (d + 1 > k) ans++;

    // 2. Iterate through all MSB positions smaller than n's MSB
    // MSB position p ranges from 0 to d-1
    for (int p = 0; p < d; p++) {
        // We have p positions following the MSB (indices 0 to p-1)
        // Moves = p + (1 + set_bits_in_remaining)
        // We need: p + 1 + set_bits > k
        // set_bits > k - p - 1
        
        long long needed = k - p - 1;
        
        // Sum nCr(p, i) for all i > needed
        for (int i = 0; i <= p; i++) {
            if (i > needed) {
                ans += C[p][i];
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}