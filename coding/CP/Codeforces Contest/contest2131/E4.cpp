#include <bits/stdc++.h>
using namespace std;

bool adjacentXOR(const vector<long long>& a, const vector<long long>& b, int n) {
    // Check last element equality first
    if (b.back() != a.back()) return false;

    // Check second last element condition
    if (!(a[n - 2] == b[n - 2] || (a[n - 1] ^ a[n - 2]) == b[n - 2])) return false;

    // Check the rest from n-3 down to 0
    for (int i = n - 3; i >= 0; i--) {
        if (a[i] == b[i] || (a[i] ^ a[i + 1]) == b[i] || (a[i] ^ b[i + 1]) == b[i]) continue;
        else return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        if (adjacentXOR(a, b, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}