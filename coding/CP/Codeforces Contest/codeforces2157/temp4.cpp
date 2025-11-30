/*
code by - Aryan Shrivastav
(Corrected Logic)
*/

#include <bits/stdc++.h>
using namespace std;

void SOLVE() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<tuple<int,int,int>> queries;
    queries.reserve(q);

    // Map to track which indices CANNOT hold 'k'
    // If a Type 2 query covers index i, then res[i] cannot be k.
    vector<bool> forbidden_for_k(n, false);

    for (int i = 0; i < q; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        l--, r--; // 0-based index
        queries.push_back({c, l, r});

        if (c == 2) {
            // This range must have MEX = k, so it CANNOT contain k.
            for(int j = l; j <= r; j++) {
                forbidden_for_k[j] = true;
            }
        }
    }

    // Initialize result with k+1
    vector<int> res(n, k + 1);

    // -----------------------------
    // STEP 1: Process TYPE-1 (min = k)
    // Place 'k' only in SAFE spots
    // -----------------------------
    for (auto &qry : queries) {
        int c = get<0>(qry);
        int l = get<1>(qry);
        int r = get<2>(qry);

        if (c == 1) {
            // Check if we already have a k in this range
            bool has_k = false;
            for (int i = l; i <= r; i++) {
                if (res[i] == k) {
                    has_k = true;
                    break;
                }
            }

            if (!has_k) {
                // Find a valid spot: Inside [l, r] AND not forbidden
                for (int i = l; i <= r; i++) {
                    if (!forbidden_for_k[i]) {
                        res[i] = k;
                        break; // We only need one k
                    }
                }
            }
        }
    }

    // -----------------------------
    // STEP 2: Process TYPE-2 (mex = k)
    // Fill 0..k-1 in empty spots
    // -----------------------------
    for (auto &qry : queries) {
        int c = get<0>(qry);
        int l = get<1>(qry);
        int r = get<2>(qry);

        if (c == 2) {
            // Check which small numbers exist
            vector<int> used(k, 0);
            for (int i = l; i <= r; i++) {
                if (res[i] >= 0 && res[i] < k) {
                    used[res[i]] = 1;
                }
            }

            int ptr = l;
            for (int v = 0; v < k; v++) {
                if (!used[v]) {
                    // Find an empty spot (k+1)
                    // Skip spots that are already taken by k or other small numbers
                    while (ptr <= r && res[ptr] <= k) {
                        ptr++;
                    }
                    if (ptr <= r) {
                        res[ptr] = v;
                        ptr++;
                    }
                }
            }
            // NO DELETION LOOP HERE! 
            // We respected the forbidden zones in Step 1, so no k exists here.
        }
    }

    // Output
    for (int i = 0; i < n; i++)
        cout << res[i] << (i + 1 == n ? "" : " ");
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        SOLVE();
    }

    return 0;
}