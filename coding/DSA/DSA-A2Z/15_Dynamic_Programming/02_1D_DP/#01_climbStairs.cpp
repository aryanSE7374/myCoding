#include<bits/stdc++.h>
using namespace std;


// recursion based code

class Solution {
public:

    int climbStairs(int n) {

        if(n==0) return 0;

        if(n==1) return 1;

        if(n==2) return 2;

        return climbStairs(n-1) + climbStairs(n-2);

    }
};

// memorization

class Solution {
public:

    int helper(int n , vector<int>& memo){

        if(n==0) return 0;

        if(n==1) return 1;

        if(n==2) return 2;

        if ( memo[n] != -1 ) return memo[n];

        return memo[n] = helper(n-1 , memo) + helper(n-2 , memo);

    }

    int climbStairs(int n) {

        vector<int> memo(n+1,-1);
        return helper(n,memo);

    }
};


// tabulation

class Solution {
public:

    int climbStairs(int n) {

        if( n<=2 ) return n;

        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }
};

// space optimized

class Solution {
public:

    int climbStairs(int n) {

        if( n<=2 ) return n;

        int prev1 = 2;
        int prev2 = 1;
        int curr = 0;

        for(int i=3 ; i<=n ; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;

    }
};



// MOST OPTIMAL : log(N) -> matrix exponentiation
// https://www.naukri.com/code360/problem-details/count-ways-to-reach-nth-stairs_798650
// appraoch 4 of the above link


