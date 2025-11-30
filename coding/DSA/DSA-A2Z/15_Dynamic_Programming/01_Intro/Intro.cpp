#include<bits/stdc++.h>
using namespace std;

// WAP to find the F(n) = nth fibonacci number , 
// given : F(0) = 0 , F(1) = 1 , F(n) = F(n-1) + F(n-2)

// recursive code 
// TC : O(2^n)
// SC : O(n)

class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};


// memorization based code (top-down)
// TC : O(n)
// SC : O(n) + O(n) recursion stack ≈ O(n)

class Solution {

public:

    int fibo(int n , vector<int>& memo){
        if(n<=1){
            return n;
        }
        if(memo[n] != -1) return memo[n];
        return memo[n] = fibo(n-1 , memo)+fibo(n-2 , memo);
    }
    
    int fib(int n) {
        vector<int> memo(n+1 , -1);
        return fibo(n , memo);
    }
};


// tabulation based code (bottom-up)
// TC : O(n)
// SC : O(n)

class Solution {

public:
    
    int fib(int n) {
        
        if(n<=1){
            return n;
        }
        
        vector<int> dp(n+1 , -1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
    }
};


// space optimized DP code
// TC : O(n)
// SC : O(1)

class Solution {
public:
    int fib(int n) {

        if(n<=1){
            return n;
        }

        int prev2 = 0 , prev1 = 1 , curr = 1;

        for(int i=2 ; i<=n ; i++){

            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;

        }

        return curr;

    }
};