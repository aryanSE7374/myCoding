/*
code by - Aryan Shrivastav
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define co_endl cout<<'\n'

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


// Function to calculate nCr on the fly
// Since n is small (<= 30), we can just use the formula or a small loop
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; // Optimization: nCr(n, r) == nCr(n, n-r)
    
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void SOLVE(){
    ll n, k;
    cin >> n >> k;

    // 1. Find d such that n = 2^d
    // Example: if n = 16 (10000), d = 4.
    int d = 0;
    while ((1LL << (d + 1)) <= n) {
        d++;
    }

    ll ans = 0;

    // 2. Check the number n itself
    // n has 1 bit set at index d. Moves = d + 1.
    if (d + 1 > k) ans++;

    // 3. Check all numbers smaller than n
    // We iterate through possible MSB positions 'p' from 0 to d-1
    for (int p = 0; p < d; p++) {
        
        // Base moves just for having MSB at 'p' is (p + 1)
        // We need total moves > k
        // So: (p + 1) + (extra bits) > k
        // extra bits > k - p - 1
        
        ll threshold = k - p - 1;

        // We have 'p' spots remaining below the MSB.
        // We need to choose 'i' spots to be 1, where i > threshold.
        for (int i = 0; i <= p; i++) {
            if (i > threshold) {
                ans += nCr(p, i);
            }
        }
    }

    cout << ans;
    co_endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        SOLVE();
    }

    return 0;
}