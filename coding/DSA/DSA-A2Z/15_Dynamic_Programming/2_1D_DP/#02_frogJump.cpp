#include<bits/stdc++.h>
using namespace std;

// code 360 version

// 1. recursion

int f(int i , vector<int>& ht ){

    if(i == 0) return 0;

    int one =  abs(ht[i]-ht[i-1]) + f(i-1 , ht); // left
    int two = (i>1) ? abs(ht[i]-ht[i-2]) + f(i-2 , ht) : INT_MAX; // right

    return min ( one , two );

}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1 , heights);
}

// 2.  memorization

int f(int i , vector<int>& ht , vector<int>& memo ){

    if(i == 0) return 0;

    if(memo[i] != -1) return memo[i];

    int one =  abs(ht[i]-ht[i-1]) + f(i-1 , ht , memo ); // left
    int two = (i>1) ? abs(ht[i]-ht[i-2]) + f(i-2 , ht , memo ) : INT_MAX; // right

    return memo[i] =  min ( one , two );

}
int frogJump(int n, vector<int> &heights)
{
    vector<int> memo(n+1 , -1);
    return f(n-1 , heights , memo );
}

// 3. tabulation -> No recursion   

int frogJump(int n, vector<int> &heights)
{
    if (n==1) return 0;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for(int i=2 ; i<n ; i++){
        dp[i] = min( abs(heights[i] - heights[i-1]) + dp[i-1] , abs(heights[i] - heights[i-2]) + dp[i-2]);
    }

    return dp[n-1];

}

// 4. space optimize DP

int frogJump(int n, vector<int> &heights)
{

    vector<int> dp(n+1);

    int two = 0;
    int one = abs(heights[1] - heights[0]);

    if (n==1) return two;
    if (n==2) return one;

    int curr;

    for(int i=2 ; i<n ; i++){
        curr = min( abs(heights[i] - heights[i-1]) + one , abs(heights[i] - heights[i-2]) + two);
        two = one;
        one = curr;
    }

    return curr;

}


// ------------------------------------------------------------------------------------------------ //

// GFG version
// space optimized DP

class Solution {
  public:
    int minCost(vector<int>& height) {

        int n = height.size();

        vector<int> dp(n+1);

        int two = 0;
        int one = abs(height[1] - height[0]);

        if (n==1) return two;
        if (n==2) return one;

        int curr;

        for(int i=2 ; i<n ; i++){
            
            curr = min( abs(height[i] - height[i-1]) + one , abs(height[i] - height[i-2]) + two);
            two = one;
            one = curr;

        }

        return curr;

    }
};