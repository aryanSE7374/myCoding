#include<bits/stdc++.h>
using namespace std;
#define ll long long

// We need to store (value, index) in the priority queue
// to find the minimum element
using pll = pair<ll, int>;

void SOLVE(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    // These arrays will act as our doubly linked list
    vector<int> prev_idx(n);
    vector<int> next_idx(n);
    // Stores if a node is still active (not merged)
    vector<bool> active(n, true); 

    // A min-priority-queue to get the smallest active element
    // We store {value, index}
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
        // Initialize linked list pointers
        prev_idx[i] = (i - 1 + n) % n;
        next_idx[i] = (i + 1) % n;
        // Push all elements into the priority queue
        pq.push({arr[i], i});
    }

    // Special case: n=1, no merges, cost=0
    // The problem statement guarantees n >= 2, but this is safe
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    // We need to perform exactly n-1 merges
    for(int k = 0; k < n - 1; k++){
        
        // 1. Find the smallest active element
        pll top = pq.top();
        pq.pop();
        
        ll val = top.first;
        int i = top.second;

        // If this element was already merged (stale entry in pq), skip it
        if (!active[i]) {
            k--; // This wasn't a valid merge, so retry
            continue;
        }

        // 2. Find its active neighbors
        int p = prev_idx[i];
        int n_ = next_idx[i];
        ll val_p = arr[p];
        ll val_n = arr[n_];

        // 3. Decide which neighbor to merge with (the one with min cost)
        ll cost_p = max(val, val_p);
        ll cost_n = max(val, val_n);

        if (cost_p <= cost_n) {
            // Merge 'i' into 'p'
            ans += cost_p;
            arr[p] = cost_p; // The new value of node p is the cost
            
            // Mark 'i' as inactive
            active[i] = false;
            
            // Update linked list: remove 'i', link 'p' and 'n_'
            next_idx[p] = n_;
            prev_idx[n_] = p;
            
            // The value of 'p' has changed, so its old pq entry
            // is stale. Add its new value to the pq.
            pq.push({arr[p], p});
        } else {
            // Merge 'i' into 'n_'
            ans += cost_n;
            arr[n_] = cost_n; // The new value of node n_ is the cost

            // Mark 'i' as inactive
            active[i] = false;

            // Update linked list: remove 'i', link 'p' and 'n_'
            next_idx[p] = n_;
            prev_idx[n_] = p;

            // The value of 'n_' has changed. Add its new value.
            pq.push({arr[n_], n_});
        }
    }

    cout << ans << "\n";
}


int main(){

    // Add fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){
      SOLVE();
    }

    return 0;
}