// https://leetcode.com/problems/minimum-total-distance-traveled/description/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// rec + memo : 1


class Solution {
public:
    const ll INF = 1e12 + 39;

    ll f ( vector<int>& robot, vector<int>& factories, 
        const int n, const int N, int i, int j, vector<vector<ll>>& memo 
    ) {
        if ( i==n ) return 0; // all robots processed
        if ( j==N ) return INF; // no factories left

        if ( memo[i][j] != -1 ) return memo[i][j];

        ll take = abs(robot[i] - factories[j]) + f(robot, factories, n, N, i+1, j+1, memo );
        ll notTake = f(robot, factories, n, N, i, j+1, memo );

        return memo[i][j] = min ( take, notTake );
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        // const ll INF = 1e12 + 39;

        vector<int> factories;

        for ( auto& fact : factory ) {
            int pos = fact[0], lim = fact[1];
            for ( int i=0; i<lim; i++) {
                factories.push_back(pos);
            }
        }

        int N = factories.size();

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        vector<vector<ll>> memo(n+1, vector<ll>(N+1, -1));

        return f( robot, factories, n, N, 0, 0, memo );

    }
};

// ------------------------------------------------------------------------------------------ //

// rec + memo : 2

class Solution {
public:
    const ll INF = 1e12 + 39;

    ll f ( vector<int>& robot, vector<int>& factories, 
        int i, int j, vector<vector<ll>>& memo 
    ) {

        if ( i==0 ) return 0;
        if ( j==0 ) return INF;

        if ( memo[i][j] != -1 ) return memo[i][j];

        ll take = abs(robot[i-1] - factories[j-1]) + f(robot, factories, i-1, j-1, memo );
        ll notTake = f(robot, factories, i, j-1, memo );

        return memo[i][j] = min ( take, notTake );
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        // const ll INF = 1e12 + 39;

        vector<int> factories;

        for ( auto& fact : factory ) {
            int pos = fact[0], lim = fact[1];
            for ( int i=0; i<lim; i++) {
                factories.push_back(pos);
            }
        }

        int N = factories.size();

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        vector<vector<ll>> memo(n+1, vector<ll>(N+1, -1));

        return f( robot, factories, n, N, memo );

    }
};

// ------------------------------------------------------------------------------------------ //

// tabulation

class Solution {
public:

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        const ll INF = 1e12 + 39;

        vector<int> factories;

        for ( auto& fact : factory ) {
            int pos = fact[0], lim = fact[1];
            for ( int i=0; i<lim; i++) {
                factories.push_back(pos);
            }
        }

        int N = factories.size();

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        vector<vector<ll>> dp(n+1, vector<ll>(N+1));

        // base cases
        dp[0][0] = 0;

        for ( int j=1; j<=N; j++ ) {
            dp[0][j] = 0;
        }

        for ( int i=1; i<=n; i++ ) {
            dp[i][0] = INF;
        }

        // tabulation
        for ( int i=1; i<=n; i++ ) {
            for ( int j=1; j<=N; j++ ) {
                ll take = abs(robot[i-1] - factories[j-1]) + dp[i-1][j-1];
                ll notTake = dp[i][j-1];
                dp[i][j] = min ( take, notTake );
            }
        }

        return dp[n][N];

    }
};

// ------------------------------------------------------------------------------------------ //

// space optimized tabulation

class Solution {
public:

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        const ll INF = 1e12 + 39;

        vector<int> factories;

        for ( auto& fact : factory ) {
            int pos = fact[0], lim = fact[1];
            for ( int i=0; i<lim; i++) {
                factories.push_back(pos);
            }
        }

        int N = factories.size();

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        vector<ll> prev(N+1, 0);
        vector<ll> curr(N+1, 0);

        // base cases - inherently fulfilled by vertor initialization with 0
        // prev[0] = 0;

        // for ( int j=1; j<=N; j++ ) {
        //     prev[j] = 0;
        // }

        // tabulation
        for ( int i=1; i<=n; i++ ) {
            // j=0 base case
            curr[0] = INF;

            for ( int j=1; j<=N; j++ ) {
                ll take = abs(robot[i-1] - factories[j-1]) + prev[j-1];
                ll notTake = curr[j-1];
                curr[j] = min ( take, notTake );
            }

            prev = curr;

        }

        return prev[N];

    }
};

// ------------------------------------------------------------------------------------------ //