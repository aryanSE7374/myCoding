#include<bits/stdc++.h>
using namespace std;


// optimal solution
// TC : O( log(N) )


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        // Edge case: overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;

        // long n = dividend;
        // n = abs(n);
        long n = labs((long)dividend); // Correct way
        long d = labs(divisor);
        divisor = labs(divisor);
        long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1 << cnt;
            n -= (d << cnt);
        }

        if (quotient >= (1L << 31) && sign) {
            return INT_MAX;
        }

        if (quotient >= (1L << 31) && !sign) {
            return INT_MIN;
        }

        return sign ? quotient : -quotient;
    }
};