#include<iostream>
#include<algorithm> // For std::max

// The only function you need
long long solve(long long a, long long b) {
    long long maxi = -1;

    for (long long k = 1; k * k <= b; ++k) {
        if (b % k == 0) {
            long long new_a1 = a * k;
            long long new_b1 = b / k;
            
            if ((new_a1 % 2) == (new_b1 % 2)) {
                long long current_sum1 = new_a1 + new_b1;
                if (maxi == -1) {
                    maxi = current_sum1;
                } else {
                    maxi = std::max(maxi, current_sum1);
                }
            }

            // The other corresponding divisor is b/k. Let's check it too.
            // We only need to do this if it's different from k.
            if (k * k != b) {
                long long k2 = b / k;
                long long new_a2 = a * k2;
                long long new_b2 = b / k2;

                if ((new_a2 % 2) == (new_b2 % 2)) {
                    long long current_sum2 = new_a2 + new_b2;
                     if (maxi == -1) {
                        maxi = current_sum2;
                    } else {
                        maxi = std::max(maxi, current_sum2);
                    }
                }
            }
        }
    }

    return maxi;
}