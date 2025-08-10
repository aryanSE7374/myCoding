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
    bool has_zero = false;
    set<int> posVals;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            has_zero = true;
        } else if (a[i] > 0) {
            posVals.insert(a[i]);
        }
    }

    if (has_zero) {
        cout << "NO\n";
        return;
    }

    if (posVals.size() > 1) {
        cout << "NO\n";
        return;
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