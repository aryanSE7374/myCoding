#include<bits/stdc++.h>
using namespace std;


// try 1 using prev sol 

class Solution {
  public:
    void sieve() {}
    
    vector<int> primeFac(int n) {
        vector<int> ans;    
        while (n % 2 == 0) {
            ans.push_back(2);
            // cout << 2 << " ";
            n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                // cout << i << " ";
                ans.push_back(i);
                n /= i;
            }
        }
        if (n > 1){
            //  cout << n << " "; // n is prime now
            ans.push_back(n);
        }
        return ans;
    }

    vector<int> findPrimeFactors(int N) {
        return primeFac(N);
        
    }
};

// using sieve

class Solution {
  public:
    void sieve() {
        // Intentionally left empty as per instruction
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> spf(N + 1);  // Smallest Prime Factor array

        // Initialize spf[i] = i
        for (int i = 0; i <= N; ++i) {
            spf[i] = i;
        }

        // Sieve of Eratosthenes to fill spf[]
        for (int i = 2; i * i <= N; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        // Use spf[] to get prime factorization of N (including repetitions)
        vector<int> res;
        while (N > 1) {
            res.push_back(spf[N]);
            N /= spf[N];
        }

        return res;
    }
};



