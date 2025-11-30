// wrong

/*
code by - Aryan Shrivastav
*/

#include <bits/stdc++.h>
using namespace std;

void SOLVE() {
    int n, k, q;
    cin >> n >> k >> q;

    // Store queries as pairs
    vector<pair<int,int>> type1;
    vector<pair<int,int>> type2;

    type1.reserve(q);
    type2.reserve(q);

    for (int i = 0; i < q; i++) {
        int c,l,r;
        cin >> c >> l >> r;
        l--, r--;

        if (c == 1) type1.push_back({l,r});
        else        type2.push_back({l,r});
    }

    // Initialize result array with k+1
    vector<int> res(n, k+1);

    // -----------------------------
    // TYPE-1 (min = k)
    // -----------------------------
    sort(type1.begin(), type1.end(), 
        [&](auto &a, auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        }
    );

    for (auto &pr : type1) {
        int l = pr.first;
        int r = pr.second;

        bool has_k = false;
        for (int i = l; i <= r; i++){
            if (res[i] == k){
                has_k = true;
                break;
            }
        }

        if (!has_k){
            res[l] = k;   // place k at left endpoint
        }
    }

    // -----------------------------
    // TYPE-2 (mex = k)
    // -----------------------------
    sort(type2.begin(), type2.end(),
        [&](auto &a, auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        }
    );

    for (auto &pr : type2){
        int l = pr.first;
        int r = pr.second;

        // Track which 0..k-1 are present
        vector<int> used(k,0);
        for (int i = l; i <= r; i++){
            if (res[i] >= 0 && res[i] < k)
                used[res[i]] = 1;
        }

        // Fill missing values
        int ptr = l;
        for (int v = 0; v < k; v++){
            if (!used[v]){
                while (ptr <= r && res[ptr] < k) ptr++;
                res[ptr] = v;
                ptr++;
            }
        }

        // Remove all k inside this interval
        for (int i = l; i <= r; i++){
            if (res[i] == k)
                res[i] = k+1;
        }
    }

    // Output
    for (int i = 0; i < n; i++)
        cout << res[i] << (i+1==n ? "" : " ");
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        SOLVE();
    }

    return 0;
}