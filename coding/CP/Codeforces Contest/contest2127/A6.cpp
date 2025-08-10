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
    bool hasZeroes = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            hasZeroes = true;
        }
    }

    if (hasZeroes) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i <= n - 3; ++i) {
        if (a[i] != -1 && a[i+1] != -1 && a[i+2] != -1) {
            if (!(a[i] == a[i+1] && a[i+1] == a[i+2])) {
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

