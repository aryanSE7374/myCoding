#include<bits/stdc++.h>
using namespace std;

//  try 1

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        // for (int i = 5; i <= sqrt(num); i += 6) {
        for (int i = 5; i*i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long res = 0;
        vector<int> maxPrimes;
        int n = s.length();

        for(int i=0 ; i<n ; i++){
            for(int len=1 ; len< n-i ; len++){
                long long num = stoll(s.substr(i,len));
                if(isPrime(num)){
                    maxPrimes.push_back(num);
                    // int min = num;
                    // for(int i=0 ; i<3 ; i++ ){
                    //     if(maxPrimes[i]<min){
                    //         // int temp = min;
                    //         // min = maxPrimes[i];
                    //         // maxPrimes[i] = temp;
                    //     }
                    // }
                }
            }
        }
        // finding 3 largest primes
        sort(maxPrimes.begin(), maxPrimes.end(), greater<int>());
        for (int i = 0; i < 3 && i < maxPrimes.size(); i++) {
            res += maxPrimes[i];
        }
        return res;
    }
};


// try 2

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        // for (int i = 5; i <= sqrt(num); i += 6) {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long res = 0;
        vector<int> maxPrimes;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) { // Changed to include valid substrings
                long long num = stoll(s.substr(i, len)); // Changed to long long to prevent overflow
                if (isPrime(num)) {
                    maxPrimes.push_back(num);
                    // int min = num;
                    // for (int i = 0; i < 3; i++) {
                    //     if (maxPrimes[i] < min) {
                    //         // int temp = min;
                    //         // min = maxPrimes[i];
                    //         // maxPrimes[i] = temp;
                    //     }
                    // }
                }
            }
        }
        // finding 3 largest primes
        sort(maxPrimes.begin(), maxPrimes.end(), greater<int>());
        for (int i = 0; i < 3 && i < maxPrimes.size(); i++) {
            res += maxPrimes[i];
        }
        return res;
    }
};


// try 3
class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        // for (int i = 5; i <= sqrt(num); i += 6) {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long res = 0;
        set<int> uniquePrimes; // Set to store unique prime numbers
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) { 
                long long num = stoll(s.substr(i, len)); 
                if (isPrime(num)) {
                    uniquePrimes.insert(num); // inserting unique prime numbers into the set
                    // int min = num;
                    // for (int i = 0; i < 3; i++) {
                    //     if (maxPrimes[i] < min) {
                    //         // int temp = min;
                    //         // min = maxPrimes[i];
                    //         // maxPrimes[i] = temp;
                    //     }
                    // }
                }
            }
        }
        // finding 3 largest primes
        vector<int> sortedPrimes(uniquePrimes.begin(), uniquePrimes.end());
        sort(sortedPrimes.begin(), sortedPrimes.end(), greater<int>());
        for (int i = 0; i < 3 && i < sortedPrimes.size(); i++) {
            res += sortedPrimes[i];
        }
        return res;
    }
};

// try 4
class Solution {
public:
    bool isPrime(long long num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        // for (int i = 5; i <= sqrt(num); i += 6) {
        for (long long i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long res = 0;
        set<long long> uniquePrimes; // Set to store unique prime numbers
        int n = s.length();

        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) { 
                long long num = stoll(s.substr(i, len)); 
                if (isPrime(num)) {
                    uniquePrimes.insert(num); 
                }
            }
        }
        // finding 3 largest primes
        vector<long long> sortedPrimes(uniquePrimes.begin(), uniquePrimes.end());
        sort(sortedPrimes.begin(), sortedPrimes.end(), greater<long long>());
        for (int i = 0; i < 3 && i < sortedPrimes.size(); i++) {
            res += sortedPrimes[i];
        }
        return res;
    }
};