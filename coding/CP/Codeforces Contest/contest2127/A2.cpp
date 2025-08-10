#include <iostream>
#include <vector>
#include <numeric>
#include <set>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    bool has_zero = false;
    std::set<int> positive_values;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            has_zero = true;
        } else if (a[i] > 0) {
            positive_values.insert(a[i]);
        }
    }

    // A 'good' array cannot contain 0.
    if (has_zero) {
        std::cout << "NO\n";
        return;
    }

    // All elements of a 'good' array must be the same positive number.
    // So, if we see more than one distinct positive number, it's impossible.
    if (positive_values.size() > 1) {
        std::cout << "NO\n";
        return;
    }

    // Otherwise, it's possible. We can fill all -1s with 1 (if there are no other numbers)
    // or with the single positive value that's already present.
    std::cout << "YES\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}