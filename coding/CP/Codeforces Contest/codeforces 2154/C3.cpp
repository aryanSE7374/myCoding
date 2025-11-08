#include<bits/stdc++.h>
using namespace std;

vector<int> spf(200006);

// Precomputing smallest prime factors
void ff() {
    for (int i = 0; i <= 200005; i++) spf[i] = i;
    for (int i = 2; i * i <= 200005; i++) {
        if (spf[i] == i) {
            for (int j = i; j * i <= 200005; j++) {
                if (spf[i * j] == i * j) spf[i * j] = i;
            }
        }
    }
}

void solve_block(int n, vector<int>& a, vector<int>& b) {
    map<int, int> count;
    vector<map<int, int>> cnt(n);

    for (int i = 0; i < n; i++) {
        int val = a[i];
        while (val > 1) {
            int p = spf[val];
            count[p]++;
            cnt[i][p]++;
            val /= p;
        }
    }

    long long ans = 2;
    for (int i = 0; i < n && ans > 0; i++) {
        for (auto [x, y] : cnt[i]) {
            if (count[x] > y) {
                ans = 0;
                break;
            }
        }
        int val = a[i] + 1;
        while (val > 1) {
            int p = spf[val];
            if (count[p] - cnt[i][p] > 0) ans = min(ans, 1LL);
            while (val % p == 0) val /= p;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ff(); 

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        solve_block(n, a, b);
    }

    return 0;
}