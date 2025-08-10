#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    --x; // 0-based index

    string s;
    cin >> s;

    // empty cells to the left and right 
    int l_empty = 0; // This variable is not used in the updated logic for calculating days
    int r_empty = 0; // This variable is not used in the updated logic for calculating days

    // immediate escape 
    bool isLeftClear = true;
    for (int i = 0; i < x; ++i) {
        if (s[i] == '#') {
            isLeftClear = false;
            break;
        }
    }
    bool isRightClear = true;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            isRightClear = false;
            break;
        }
    }
    if (isLeftClear || isRightClear) {
        cout << 1 << endl;
        return;
    }

    // empty cells btw Hamid and nearest wall , both sides
    int nearestLeftWall = -1;
    for (int i = x - 1; i >= 0; --i) {
        if (s[i] == '#') {
            nearestLeftWall = i;
            break;
        }
    }

    int nearestRightWall = n;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == '#') {
            nearestRightWall = i;
            break;
        }
    }

    // l_empty = x - nearestLeftWall - 1;
    // r_empty = nearestRightWall - x - 1;
    
    int emptyCells = 0;
    for (int i = nearestLeftWall + 1; i < nearestRightWall; ++i) {
        if (s[i] == '.') {
            emptyCells++;
        }
    }
    cout << emptyCells + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}