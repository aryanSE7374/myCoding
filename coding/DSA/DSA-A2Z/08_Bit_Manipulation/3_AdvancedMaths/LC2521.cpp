#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/submissions/1705935194/


// my sol. :


// 	•	Time: O(n * √(maxElement) )
// 	•	Space: O(k) (set of distinct primes, where k is small)

class Solution {
public:

    vector<int> primeFac(int n) {
        vector<int> ans;    
        if(n%2 == 0){
            ans.push_back(2);
            while (n % 2 == 0) {
                // cout << 2 << " ";
                n /= 2;
            }
        }
        for (int i = 3; i * i <= n; i += 2) {
            if(n % i == 0){
                ans.push_back(i);
                while (n % i == 0) {
                    // cout << i << " ";
                    n /= i;
                }
            }
        }
        if (n > 1){
            //  cout << n << " "; // n is prime now
            ans.push_back(n);
        }
        return ans;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        for(int num : nums){
            vector<int> temp = primeFac(num);
            for(int n : temp){ans.insert(n);}
        }
        return ans.size();
    }
};

// optimal

// •	Time: O(N log log N + ∑ log num)
// •	Space: O(N) for SPF array


class Solution {
public:
    // Precompute SPF (Smallest Prime Factor) up to maxN
    vector<int> computeSPF(int maxN) {
        vector<int> spf(maxN + 1);
        for (int i = 0; i <= maxN; i++) spf[i] = i;

        for (int i = 2; i * i <= maxN; ++i) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= maxN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i; // mark the smallest prime factor
                    }
                }
            }
        }
        return spf;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf = computeSPF(maxVal);

        unordered_set<int> primes;

        for (int num : nums) {
            while (num > 1) {
                int prime = spf[num];
                primes.insert(prime);
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }

        return primes.size();
    }
};