#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Function to compute MEX of a vector of 3 integers
int mex(int a, int b, int c) {
    set<int> s = {a, b, c};
    for (int i = 0; ; ++i) {
        if (s.find(i) == s.end()) return i;
    }
}

bool isGood(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i <= n - 3; ++i) {
        int x = a[i], y = a[i+1], z = a[i+2];
        int m = max({x, y, z}) - min({x, y, z});
        if (mex(x, y, z) != m) return false;
    }
    return true;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        bool possible = false;
        for (int rep = 0; rep <= 2; ++rep) {
            vector<int> temp = a;
            for (int& x : temp) {
                if (x == -1) x = rep;
            }
            if (isGood(temp)) {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}