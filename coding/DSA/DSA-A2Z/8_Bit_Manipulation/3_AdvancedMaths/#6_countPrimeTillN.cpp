#include<bits/stdc++.h>
using namespace std;

// brute
// TC : O(n^2)
//  SC : O(1)

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// better
// TC : O( n * √n )
//  SC : O(1)

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) count++;
    }
    return count;
}




// The Sieve of Eratosthenes 
// is a classic and efficient algorithm to generate all prime numbers up to a given number n.

// TC : O(n log log n)
// SC : O(n)


int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return count(isPrime.begin(), isPrime.end(), true);
}

// leetcode 204

class Solution {
public: 
    int countPrimes(int n) {
        // edge case that will produce errors
        if(n==0 || n==1){return 0;}
        vector<bool> isPrime(n , true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};