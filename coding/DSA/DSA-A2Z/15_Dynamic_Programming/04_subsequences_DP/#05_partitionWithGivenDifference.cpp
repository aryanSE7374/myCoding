#include <bits/stdc++.h> 
using namespace std; 

// space optimize - 4 count subsets with sum K 

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

int countPartitions(int n, int d, vector<int> &arr) {
    int S = 0;
    for(int i=0 ; i<n ; i++){
        S += arr[i];
    }
    if ( S-d < 0 || (S-d)%2 == 1 ) return 0;
    int k = (S-d)/2 ;
    return findWays(arr , k );
}


