#include<bits/stdc++.h>
using namespace std;

// brute : 	TC : O(n * √n)

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i*i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

void printPrimeFactors(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            cout << i << " ";
        }
    }
}

// better : TC : O(N)

/*
Instead of checking if a divisor is prime separately, just try dividing n repeatedly by all numbers i from 2 to n.
•	Whenever i divides n, divide n by i until it no longer does.
•	This avoids the need for separate primality checks.
*/

void printPrimeFactors(int n) {
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
}

// optimal sol : TC : O(√n) , the log factor due to repeated division insde the while loop barely has any significant impact on algo time
// hence cosidered as O(1)


void printPrimeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n << " "; // n is prime now
}

// GFG prectice : https://www.geeksforgeeks.org/problems/prime-factors5052/1
class Solution {
  public:
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
};



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
};