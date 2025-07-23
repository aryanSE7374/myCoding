#include <iostream>
#include <cmath>

class toCheckPrime {
public:
    // Function check whether a number is prime or not

    // Usual code
    static bool CheckPrime2(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    // More optimized code for CP
    static bool isPrime(int n) {
        if (n <= 1)
            return false;

        // Check if n=2 or n=3
        if (n == 2 || n == 3)
            return true;

        // Check whether n is divisible by 2 or 3
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        // Check from 5 to square root of n
        // Iterate i by (i+6)
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }
};

// Driver Code
int main() {
    if (toCheckPrime::isPrime(67)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
