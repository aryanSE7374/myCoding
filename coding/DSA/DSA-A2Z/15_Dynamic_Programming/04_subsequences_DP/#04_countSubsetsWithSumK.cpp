#include<bits/stdc++.h>
using namespace std;


// striver's solutions (old version of the problem , that did not considered array containg 0 edge cases)
// constraints : 
// 1 <= arr[i] <= 1000

// rec + memo

vector<vector<int>> memo;
int f(int i , int k , vector<int>& arr ){
	if ( k==0 ) return 1;
	if ( i==0 ) return ( k == arr[0] ) ? 1 : 0 ;
	if ( memo[i][k] != -1 ) return memo[i][k] ;
    int notTake = f ( i-1 , k , arr);
    int take = 0;
    if ( k >= arr[i] ) take = f ( i-1 , k-arr[i] , arr) ; // k-arr[i] >= 0
	return memo[i][k] = notTake + take ;
}


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	memo.assign(n+1 , vector<int>(k+1 , -1) );
	return f(n-1 , k , arr);
}

// tabulate

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n+1 , vector<int>(k+1 , 0) );
    for(int i=0 ; i<n ; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k) dp[0][arr[0]] = 1;
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<=k ; j++){
            int notTake = dp[i-1][j] ;
            int take = 0;
            if ( j >= arr[i] ) take = dp[i-1][j-arr[i]] ;
            dp[i][j] = notTake + take ;
        }
    }
	return dp[n-1][k] ;
}


// -------------------------------------------------------------------------------- //

// fixed , submitted solution (new version) - will get submitted on GFG too

// memo 

vector<vector<int>> memo;
int f(int i , int k , vector<int>& arr ){
	// if ( k==0 ) return 1;
	// if ( i==0 ) return ( k == arr[0] ) ? 1 : 0 ;
	if ( i == 0 ) {
        if ( k == 0 && arr[0] == 0) return 2; 
        if ( k == 0 || k == arr[0] ) return 1;
        return 0;
	} 
	if ( memo[i][k] != -1 ) return memo[i][k] ;
    int notTake = f ( i-1 , k , arr);
    int take = 0;
    if ( k >= arr[i] ) take = f ( i-1 , k-arr[i] , arr) ; // k-arr[i] >= 0
	return memo[i][k] = (notTake + take) % int(1e9 + 7) ;
}


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	memo.assign(n+1 , vector<int>(k+1 , -1) );
	return f(n-1 , k , arr);
}

// tabulate

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n+1 , vector<int>(k+1 , 0) );

    int MOD = 1e9 + 7;

    for(int j=0 ; j<=k ; j++){
        dp[0][j] = ( j==0 && arr[0] == 0 ) ? 2 : ( ( j==0 || j == arr[0] ) ? 1 : 0 ) ;
    }

    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<=k ; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if ( j >= arr[i] ) take = dp[i-1][j-arr[i]] ;
            dp[i][j] = (notTake + take) % MOD ;
        }
    }

	return dp[n-1][k];
}

// space optimize

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();

    vector<int> prev(k+1,0);
    vector<int> curr(k+1,0);

    // dp[i] = curr , dp[i-1] = prev

    int MOD = 1e9 + 7;

    for(int j=0 ; j<=k ; j++){
        prev[j] = ( j==0 && arr[0] == 0 ) ? 2 : ( ( j==0 || j == arr[0] ) ? 1 : 0 ) ;
    }

    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<=k ; j++){
            int notTake = prev[j];
            int take = 0;
            if ( j >= arr[i] ) take = prev[j-arr[i]] ;
            curr[j] = (notTake + take) % MOD ;
        }
        prev = curr;
    }

	return prev[k];
}

