#include<bits/stdc++.h>
using namespace std;

// try1 
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n<=k && m<=k ){return 0;}
        long long miniCost = LLONG_MAX;
        for (int len1 = 1; len1 <= k; ++len1) {
            int len2 = n - len1;
            if (len2 > 0 && len2 <= k) {
                miniCost = min(miniCost, 1LL*len1 *len2);
            }
        }
        for (int len1 = 1; len1 <= k; ++len1) {
            int len2 = m - len1;
            if (len2 > 0 && len2 <= k) {
                miniCost = min(miniCost, 1LL*len1 *len2);
            }
        }
        return miniCost;
    }
};

// try2

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;

        long long miniCost = LLONG_MAX;

        // Case 1: only n cutted and m not
        for (int len1 = 1; len1 <= k; ++len1) {
            int len2 = n - len1;
            if (len2 > 0 && len2 <= k && m <= k) {
                miniCost = min(miniCost, 1LL * len1 * len2);
            }
        }

        // Case 2: only m cutted and n not
        for (int len1 = 1; len1 <= k; ++len1) {
            int len2 = m - len1;
            if (len2 > 0 && len2 <= k && n <= k) {
                miniCost = min(miniCost, 1LL * len1 * len2);
            }
        }

        // Case 3: both n and m are to be cut
        for (int len1_n = 1; len1_n <= k; ++len1_n) {
            int len2_n = n - len1_n;
            if (len2_n > 0 && len2_n <= k) {
                for (int len1_m = 1; len1_m <= k; ++len1_m) {
                    int len2_m = m - len1_m;
                    if (len2_m > 0 && len2_m <= k) {
                        miniCost = min(miniCost, 1LL * len1_n * len2_n + 1LL * len1_m * len2_m);
                    }
                }
            }
        }

        return miniCost;
    }
};

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;

        long long miniCost = LLONG_MAX;

        // Case 1: Split n into two pieces, and m stays whole
        if (m <= k) {
            for (int len1 = 1; len1 <= k; ++len1) {
                int len2 = n - len1;
                if (len2 > 0 && len2 <= k) {
                    miniCost = min(miniCost, 1LL * len1 * len2);
                }
            }
        }

        // Case 2: Split m into two pieces, and n stays whole
        if (n <= k) {
            for (int len1 = 1; len1 <= k; ++len1) {
                int len2 = m - len1;
                if (len2 > 0 && len2 <= k) {
                    miniCost = min(miniCost, 1LL * len1 * len2);
                }
            }
        }

        // Case 3: Split both n and m into pieces
        for (int len1_n = 1; len1_n <= k; ++len1_n) {
            int len2_n = n - len1_n;
            if (len2_n > 0 && len2_n <= k) {
                for (int len1_m = 1; len1_m <= k; ++len1_m) {
                    int len2_m = m - len1_m;
                    if (len2_m > 0 && len2_m <= k) {
                        miniCost = min(miniCost, 1LL * len1_n * len2_n + 1LL * len1_m * len2_m);
                    }
                }
            }
        }

        return miniCost;
    }
};


// optimal GPT

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        auto getMinCost = [&](int log) -> long long {
            if (log <= k) return 0;
            long long minCost = LLONG_MAX;
            for (int len1 = 1; len1 <= k; ++len1) {
                int len2 = log - len1;
                if (len2 > 0 && len2 <= k) {
                    minCost = min(minCost, 1LL * len1 * len2);
                }
            }
            return minCost;
        };
        return getMinCost(n) + getMinCost(m);
    }
};

// simple
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long minCost = 0;

        for (int log : {n, m}) {
            if (log > k) {
                long long logCost = LLONG_MAX;
                for (int len1 = 1; len1 <= k; ++len1) {
                    int len2 = log - len1;
                    if (len2 > 0 && len2 <= k) {
                        logCost = min(logCost, 1LL * len1 * len2);
                    }
                }
                minCost += logCost;
            }
        }

        return minCost;
    }
};