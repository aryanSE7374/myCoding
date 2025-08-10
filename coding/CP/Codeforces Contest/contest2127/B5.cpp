#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    --x; // Convert to 0-based index

    string s;
    cin >> s;

    // Case 1: Immediate escape to left
    bool leftClear = true;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '#') {
            leftClear = false;
            break;
        }
    }

    // Case 2: Immediate escape to right
    bool rightClear = true;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            rightClear = false;
            break;
        }
    }

    if (leftClear || rightClear) {
        cout << 1 << '\n';
        return;
    }

    // Case 3: Both sides blocked, count walls
    int leftWalls = 0;
    for (int i = x - 1; i >= 0; --i) {
        if (s[i] == '#') leftWalls++;
    }

    int rightWalls = 0;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') rightWalls++;
    }

    int days = min(leftWalls, rightWalls) + 1;
    cout << days << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}