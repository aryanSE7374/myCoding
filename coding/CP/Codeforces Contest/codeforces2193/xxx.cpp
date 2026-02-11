/*
code by - Aryan Shrivastav
*/

/*
observations : 
1. Iterating 'stt' inside recursion is O(N^2) -> TLE.
2. We must use precomputed divisors to make it O(N log N).
3. Base case for 1 needs specific handling in output.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

const int MAXN = 300005;
const int INF = 1e9;

// Global precomputed divisors to save time
vector<int> divisors[MAXN];

void precompute() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void SOLVE(){

    ll n ;
    cin >> n ;

    // 'has' array allows O(1) check if a number exists in input
    vector<bool> has(n + 1, false);

    f(i,0,n) {
        int x;
        cin >> x;
        if (x <= n) has[x] = true;
    }

    // dp[i] = min elements to get product 'i'
    vector<int> dp(n + 1, INF);

    // Base case: Product 1 conceptually needs 0 extra multiplications 
    // (We handle the "at least one element" requirement in the print loop)
    dp[1] = 0;

    // Iterative DP: Process numbers 1 to n
    f(i, 1, n + 1) {
        if (dp[i] == INF) continue;

        // Try to multiply 'i' by some 'd' present in the array
        // However, this is "Push DP". Let's do "Pull DP" (look at divisors of current)
        // Actually, looking at divisors of 'i' is better:
    }
    
    // Reset DP and re-run with correct Divisor Logic
    // dp[i] = min(dp[i/d] + 1) for all d that are divisors of i AND present in array
    
    fill(dp.begin(), dp.end(), INF);
    dp[1] = 0;
    
    f(i, 2, n + 1) {
        for (int d : divisors[i]) {
            // If the divisor 'd' is in our input array
            // AND we can form the number (i/d)
            if (d > 1 && has[d]) { 
                int prev = i / d;
                if (dp[prev] != INF) {
                    dp[i] = min(dp[i], dp[prev] + 1);
                }
            }
        }
    }

    f(i, 1, n + 1) {
        // Special Handling for 1
        if (i == 1) {
            if (has[1]) cout << 1 << " ";
            else cout << -1 << " ";
        }
        else {
            if (dp[i] == INF) cout << -1 << " ";
            else cout << dp[i] << " ";
        }
    }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Calculate divisors once for all test cases
    precompute();

    int t;
    cin>>t;
    while(t--){
        SOLVE();
    }

    return 0;
}