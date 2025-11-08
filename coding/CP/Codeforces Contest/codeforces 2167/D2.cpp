#include <iostream>
#include <vector>
#include <numeric>

// Using long long for large numbers
#define ll long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // A sufficient list of initial prime numbers.
    // The product of primes up to 59 exceeds 10^18, guaranteeing an answer is in this list.
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

    // Iterate through the primes to find the smallest candidate for x
    for (int p : primes) {
        bool is_p_bad = true; // Assume p is a "bad" prime (divides all elements)

        // Check if p divides every element in the array
        for (int i = 0; i < n; ++i) {
            if (a[i] % p == 0) {
                // p divides this element, continue checking
            } else {
                // Found an element that p does NOT divide.
                // This means gcd(a[i], p) = 1.
                // So, p is not a bad prime. It's a valid answer.
                is_p_bad = false;
                break; // No need to check other elements for this prime
            }
        }

        // If after checking all elements, p was not bad, it's our answer.
        // Since we check primes in increasing order, this is the smallest answer.
        if (!is_p_bad) {
            std::cout << p << std::endl;
            return; // Exit the function for this test case
        }
    }

    // According to the problem constraints, we should always find an answer
    // in the list above, so we technically shouldn't reach here.
    // The problem statement implies a solution in the range [2, 10^18] always exists.
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}