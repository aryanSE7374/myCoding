#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for using vector to store dynamic arrays
#include <algorithm> // Required for utility functions like min, max (and others if needed)
#include <numeric>  // Required for functions like iota, accumulate (if needed)
#include <set>      // Required for set, useful for MEX calculation (if needed)
using namespace std;

// It's common practice in competitive programming to use a faster I/O setup
// This unties cin from cout and disables synchronization with C stdio
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Function to solve a single test case
void solve() {
    int n; // Declare variable for the length of the array
    cin >> n; // Read the value of n

    vector<int> a(n); // Declare a vector to store the array elements
    // Loop to read n integers into the vector a
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read each element
    }

    // TODO: Implement the core logic of the problem here.
    // Based on the problem statement, you'll need to determine if
    // it's possible to replace -1s such that the mex/max/min condition holds
    // for every triplet [a_i, a_{i+1}, a_{i+2}].

    // Example placeholder for output:
    cout << "YES\n"; // Or "NO\n" based on your logic
}

// Main function where the program execution begins
int main() {
    fast_io(); // Call the fast I/O setup function

    int t; // Declare variable for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program termination
}

