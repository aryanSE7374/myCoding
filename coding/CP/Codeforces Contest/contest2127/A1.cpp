#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using std::vector to store the array
#include <algorithm> // For std::max (though not strictly needed in the final version)

// Function to solve a single test case
void solve() {
    int n; // Length of the array
    std::cin >> n; // Read n

    std::vector<int> a(n); // Declare a vector of size n
    bool contains_zero = false; // Flag to check if the array contains a 0

    // Read array elements and check for the presence of 0
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // Read element
        if (a[i] == 0) {
            contains_zero = true; // Set flag if 0 is found
        }
    }

    // If the array contains 0, it's impossible to make it good.
    // As per our intuition, any triplet containing 0 cannot satisfy the condition.
    if (contains_zero) {
        std::cout << "NO\n";
        return; // Exit the function for this test case
    }

    // Iterate through all possible triplets [a_i, a_{i+1}, a_{i+2}]
    // The loop runs up to n-3 to ensure i+2 does not go out of bounds.
    for (int i = 0; i <= n - 3; ++i) {
        // Check if all three elements in the current triplet are fixed (not -1)
        if (a[i] != -1 && a[i+1] != -1 && a[i+2] != -1) {
            // If they are fixed, they must all be equal for the condition to hold.
            // If they are not all equal, it's impossible to make the array good.
            if (!(a[i] == a[i+1] && a[i+1] == a[i+2])) {
                std::cout << "NO\n";
                return; // Exit the function for this test case
            }
        }
    }

    // If we reach this point, it means:
    // 1. No '0's were found in the initial array.
    // 2. All triplets with fixed elements (not -1) already satisfy the condition
    //    (i.e., all three elements are equal and positive).
    // In this case, we can always replace all '-1's with any positive integer (e.g., 1).
    // This will ensure that all triplets (whether originally fixed or now filled)
    // will consist of identical positive numbers, satisfying the derived condition.
    std::cout << "YES\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); // Untie cin from cout

    int t; // Number of test cases
    std::cin >> t; // Read number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}

