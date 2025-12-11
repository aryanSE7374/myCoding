#include<bits/stdc++.h>
using namespace std;



// 1. recursion

int f(int i , vector<int>& ht , int k ){

    if(i == 0) return 0;

    int ans = INT_MAX;

    for(int j=1 ; j<=k && (i-j >= 0) ; j++){

        ans = min ( ans , abs(ht[i]-ht[i-j]) + f(i-j , ht , k) );

    }

    return ans;

}

int frogJump(int n, vector<int> &heights , int k)
{
    return f(n-1 , heights , k);
}

// 2. memorization

int f(int i , vector<int>& ht , int k , vector<int>& memo ){

    if(i == 0) return 0;

    if(memo[i] != -1) return memo[i];

    int ans = INT_MAX;

    for(int j=1 ; j<=k && (i-j >= 0) ; j++){

        ans = min ( ans , abs(ht[i]-ht[i-j]) + f(i-j , ht , k , memo) );

    }

    return ans;

}

int frogJump(int n, vector<int> &heights , int k)
{

    vector<int> memo(n+1,-1);
    return f(n-1 , heights , k , memo);

}


// 3. tabulation

int frogJump(int n, vector<int> &heights , int k)
{

    vector<int> dp(n+1,-1);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for(int i=1 ; i<n ; i++){

        int ans = INT_MAX;
        
        for(int j=1 ; j<=k && (i-j >= 0) ; j++){

            ans = min ( ans , abs(heights[i]-heights[i-j]) + dp[i-j] );

        }

        dp[i] = ans;

    }

    return dp[n-1];

}