#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Compute popcount-depth of x
    int getDepth(long long x) {
        int depth = 0;
        while (x != 1) {
            x = __builtin_popcountll(x);
            depth++;
        }
        return depth;
    }

    long long popcountDepth(long long n, int k) {
        long long count = 0;
        for (long long i = 1; i <= n; ++i) {
            if (getDepth(i) == k)
                count++;
        }
        return count;
    }
};