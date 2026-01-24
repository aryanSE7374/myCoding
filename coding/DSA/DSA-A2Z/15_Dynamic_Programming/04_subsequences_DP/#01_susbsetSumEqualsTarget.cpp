#include<bits/stdc++.h>
using namespace std;

// rec - brute

bool f(vector<int>& arr , int i , int k , int sum){
    if(sum == k) return true;
    if(i<0) return false;
    return ( f(arr,i-1,k,sum+arr[i]) || f(arr,i-1,k,sum) ) ;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(arr,n-1,k,0);
}


// memo - my sol 1 : submitted

vector<vector<int>> memo;

bool f(vector<int>& arr , int i , int k , int sum){
    if(sum == k) return true;
    if(i<0) return false;
    if( sum <= k && memo[i][sum] != -1){
        return memo[i][sum];
    } 
    
    if(sum <= k ){
        return memo[i][sum] = ( f(arr,i-1,k,sum+arr[i]) || f(arr,i-1,k,sum) ) ;
    }
    else return false;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    memo.assign(n+1 , vector<int>(k+1,-1));
    return f(arr,n-1,k,0);
}

// ------------------------------------------------------------------------------------------ //

// striver's solutions

// rec
bool f ( vector<int>& arr , int i , int k){

    if(k==0) return true;
    if ( i==0 ) return ( arr[0] == k ) ;

    bool notTake = f(arr , i-1 , k);
    bool take = false;

    if( k >= arr[i]) { // k - arr[i] >= 0
        take = f ( arr , i-1 , k - arr[i] ) ;
    }

    return take || notTake ;
    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(arr,n-1,k);
}

// ------------------------------------------------------------------------------------------ //

// memoization

vector<vector<int>> memo;

bool f ( vector<int>& arr , int i , int k){

    if(k==0) return true;
    if ( i==0 ) return ( arr[0] == k ) ;

    if( memo[i][k] != -1) return memo[i][k] ;

    bool notTake = f(arr , i-1 , k);
    bool take = false;

    if( k >= arr[i]) { // k - arr[i] >= 0
        take = f ( arr , i-1 , k - arr[i] ) ;
    }

    return memo[i][k] = take || notTake ;
    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    memo.assign( n+1 , vector<int>(k+1,-1)  );
    return f(arr,n-1,k);
}

// ------------------------------------------------------------------------------------------ //

// tabulate

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp( n+1 , vector<bool>(k+1,false)  );

    for(int i = 0 ; i < n ; i++ ) { 
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true ;

    // for (int j=0 ; j<=k ; j++){
    //     dp[0][j] = (arr[0] == j) ;
    // }

    for(int i = 1 ; i < n ; i++ ) { 
        for ( int j = 1 ; j <= k ; j++ ) {

            bool notTake = dp[i-1][j] ;
            bool take = false;

            if( j >= arr[i]) { // j - arr[i] >= 0
                take = dp[i-1][j-arr[i]];
            }

            dp[i][j] = take || notTake ;


        }
    }

    return dp[n-1][k] ;

}

// ------------------------------------------------------------------------------------------ //

// space optimization

// dp[i-1] -> prev
// dp[i] -> curr

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1 , false); // -- 0
    vector<bool> curr(k+1 , false); // -- 1

    prev[0] = curr[0] = true;

    prev[arr[0]] = true ;

    for(int i = 1 ; i < n ; i++ ) { 
        for ( int j = 1 ; j <= k ; j++ ) {

            bool notTake = prev[j] ;
            bool take = false;

            if( j >= arr[i]) { // j - arr[i] >= 0
                take = prev[j-arr[i]];
            }

            curr[j] = take || notTake ;

        }
        prev = curr;
    }

    return curr[k] ;

}

// ------------------------------------------------------------------------------------------ //