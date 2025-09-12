#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Corrected function with clearer variable names
void fill_q(vector<int> &p, vector<int> &q, int n) {
    // --- Step 1: Create buckets for indices based on p[i]'s value ---
    vector<int> mod0_indices; // Indices where p[i] % 3 == 0
    vector<int> mod1_indices; // Indices where p[i] % 3 == 1
    vector<int> mod2_indices; // Indices where p[i] % 3 == 2

    for (int i = 0; i < n; i++) {
        if (p[i] % 3 == 0) {
            mod0_indices.push_back(i);
        } else if (p[i] % 3 == 1) {
            mod1_indices.push_back(i);
        } else {
            mod2_indices.push_back(i);
        }
    }

    // --- Step 2: Create buckets for available q values ---
    vector<int> mod0_available; // Values k from 1..n where k % 3 == 0
    vector<int> mod1_available; // Values k from 1..n where k % 3 == 1
    vector<int> mod2_available; // Values k from 1..n where k % 3 == 2

    for (int k = 1; k <= n; k++) {
        if (k % 3 == 0) {
            mod0_available.push_back(k);
        } else if (k % 3 == 1) {
            mod1_available.push_back(k);
        } else {
            mod2_available.push_back(k);
        }
    }

    // --- Step 3: Perform the correct matching ---
    
    // Pair p[i]%3==0 with q[i]%3==0

    for (int i = 0; i < mod0_indices.size(); ++i) {
        int index = mod0_indices[i];
        int val = mod0_available[i];
        q[index] = val;
    }
    
    // Pair p[i]%3==1 with q[i]%3==2
    for (int i = 0; i < mod1_indices.size(); ++i) {
        int index = mod1_indices[i];
        int val = mod2_available[i];
        q[index] = val;
    }
    
    // Pair p[i]%3==2 with q[i]%3==1
    for (int i = 0; i < mod2_indices.size(); ++i) {
        int index = mod2_indices[i];
        int val = mod1_available[i];
        q[index] = val;
    }
}

// Your main function can remain the same
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> q(n);
        fill_q(p, q, n);

        for (int i = 0; i < n; i++) {
            cout << q[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}