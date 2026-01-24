#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

// -------------------------------------------------------------------------------- // 

// code 360 version : https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=SUBMISSION

// striver's solutions

// copied tabulate code from #01 subset sum equals k

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int k = 0;
	// int n = arr.size();
	for(int i=0 ; i<n ; i++){
        k += arr[i];
	}
    
	vector<vector<bool>> dp( n+1 , vector<bool>(k+1,false)  );
    
	for(int i = 0 ; i < n ; i++ ) { 
        dp[i][0] = true;
	}
    
	dp[0][arr[0]] = true ;
    
	for(int i = 1 ; i < n ; i++ ) { 
        for ( int j = 1 ; j <= k ; j++ ) { // for more optimization use loop till k/2 only as after half the sum , the pairs repeat
            
            bool notTake = dp[i-1][j] ;
			bool take = false;
            
			if( j >= arr[i]) { // j - arr[i] >= 0
				take = dp[i-1][j-arr[i]];
			}
            
			dp[i][j] = take || notTake ;
            
		}
	}
    
	int mini = INT_MAX ;
	for(int j=0 ; j<=k ; j++ ){
        if(dp[n-1][j]){
            mini = min ( mini , abs ( 2*j - k ) ) ;
		}
	}
    
	return mini;
	
}

// -------------------------------------------------------------------------------- // 

// leetcode version (HARD version ) try : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

// rec
class Solution {
public:
    int f ( vector<int>& A , int n , int S , int i , int len , int Sum ) {
        if( len == 0 ) return abs ( S - 2*Sum  );
        if ( i == 0 ) {
            int take = INF;
            int notTake = INF;
            take = ( len == 1 ) ? abs ( S - 2*(Sum+A[i]) ) : INF ;
            return min ( take , notTake ) ;
        }
        int take = f( A , n , S , i-1 , len-1 , Sum + A[i] ) ;
        int notTake = f( A , n , S , i-1 , len , Sum ) ;
        return min ( take , notTake ) ;
    }
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        int S = accumulate ( nums.begin() , nums.end() , 0 ) ;
        return f ( nums , n , S , N-1 , n , 0 ) ;
    }
};

// memo try

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int f ( vector<int>& A , int n , int S , int i , int len , int Sum ) {
        if( len == 0 ) return abs ( S - 2*Sum  );
        if ( i == 0 ) {
            int take = INF;
            int notTake = INF;
            take = ( len == 1 ) ? abs ( S - 2*(Sum+A[i]) ) : INF ;
            return min ( take , notTake ) ;
        }
        int take = f( A , n , S , i-1 , len-1 , Sum + A[i] ) ;
        int notTake = f( A , n , S , i-1 , len , Sum ) ;
        return min ( take , notTake ) ;
    }
    int minimumDifference(vector<int>& nums) {
        int x,y,z;
        int N = nums.size();
        int n = N/2;
        int S = accumulate ( nums.begin() , nums.end() , 0 ) ;
        memo.assign( z ,  vector<vector<int>>( y , vector<int>(x,-INF)) ) ;
        return f ( nums , n , S , N-1 , n , 0 ) ;
    }
};
