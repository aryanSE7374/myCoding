#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i + 2 < n; ++i) {
        int x = a[i], y = a[i + 1], z = a[i + 2];
        if (x != -1 && y != -1 && z != -1) {
            int mex = 0;
            while (mex == x || mex == y || mex == z) mex++;
            int mn = min({x, y, z});
            int mx = max({x, y, z});
            if (mex != mn && mex != mx) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}