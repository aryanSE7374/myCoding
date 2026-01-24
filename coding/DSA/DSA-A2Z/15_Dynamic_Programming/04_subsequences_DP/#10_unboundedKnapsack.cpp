#include<bits/stdc++.h>
using namespace std;

// code 360 : https://www.naukri.com/code360/problems/unbounded-knapsack_1215029
// GFG :  https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


// this prob is not completely same as the coin change 2 , here's a difference
/*
// try test case : 
1
7
10
3
*/

// rec
int f ( vector<int> &pf , vector<int> &wt , int i, int W ) {

    if ( i==0 ) { 
        // if ( W % wt[i] == 0 ) {
        //     return W/wt[i] * pf[i] ;
        // } 
        // return 0 ;
        return W/wt[i] * pf[i] ;
    }

    int notTake = f ( pf ,wt , i-1 , W ) ;
    int take = ( wt[i] <= W ) ? pf[i] + f ( pf ,wt , i , W-wt[i] ) : 0 ;

    return max ( notTake , take ) ;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return f ( profit , weight , n-1 , w ) ;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// memo : submitted
vector<vector<int>> dp;

int f ( vector<int> &pf , vector<int> &wt , int i, int W ) {

    if ( i==0 ) { 
        // if ( W % wt[i] == 0 ) {
        //     return W/wt[i] * pf[i] ;
        // } 
        // return 0 ;
        return W/wt[i] * pf[i] ;
    }

    if ( dp[i][W] != -1 ) return dp[i][W] ;

    int notTake = f ( pf ,wt , i-1 , W ) ;
    int take = ( wt[i] <= W ) ? pf[i] + f ( pf ,wt , i , W-wt[i] ) : 0 ;

    return dp[i][W] = max ( notTake , take ) ;
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    dp.assign( n , vector<int>(w+1 , -1 )) ;
    return f ( profit , weight , n-1 , w ) ;
}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// tabulate
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>> dp( n , vector<int>(w+1 , 0 )) ;

    // base case : i==0 
    for ( int W = 0 ; W <= w ; W++ ) {
        // if ( W%weight[0] == 0 ) dp[0][W] = W/weight[0] * profit[0] ;
        dp[0][W] = W/weight[0] * profit[0] ;
    }

    // recurrance
    for ( int i=1 ; i<n ; i++ ) {
        for ( int W = 0 ; W <= w ; W++ ) {

            int notTake = dp[i-1][W] ;
            int take = ( weight[i] <= W ) ? profit[i] + dp[i][W-weight[i]] : 0 ;

            dp[i][W] = max ( notTake , take ) ;

        }
    }

    return dp[n-1][w] ;

}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prev(w+1 , 0);
    vector<int> curr(w+1 , 0);

    // base case : i==0 , fill the ith row i.e. initial prev row filling
    for ( int W = 0 ; W <= w ; W++ ) {
        // if ( W%weight[0] == 0 ) prev[W] = W/weight[0] * profit[0] ;
        prev[W] = W/weight[0] * profit[0] ;
    }

    // recurrance
    for ( int i=1 ; i<n ; i++ ) {
        for ( int W = 0 ; W <= w ; W++ ) {

            int notTake = prev[W] ;
            int take = ( weight[i] <= W ) ? profit[i] + curr[W-weight[i]] : 0 ;

            curr[W] = max ( notTake , take ) ;

        }
        prev = curr;
    }

    return prev[w] ;

}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

// 1 array - space optimization (most optimal)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<int> prev(w+1 , 0);

    // base case : i==0 , fill the ith row i.e. initial prev row filling
    for ( int W = 0 ; W <= w ; W++ ) {
        prev[W] = W/weight[0] * profit[0] ;
    }

    // recurrance
    for ( int i=1 ; i<n ; i++ ) {
        for ( int W = 0 ; W <= w ; W++ ) {

            int notTake = prev[W] ;
            int take = ( weight[i] <= W ) ? profit[i] + prev[W-weight[i]] : 0 ;

            prev[W] = max ( notTake , take ) ;

        }
    }

    return prev[w] ;

}

// ------------------------------------------------------------------------------------------------------------------------------------ // 

int main ( ) {
    int t;
    cin >> t;
    while (t--)
    {
        int n , w;
        cin >> n >> w;
        vector<int> pf ( n) ;
        vector<int> wt ( n) ;
        for ( int i=0 ; i<n ; i++ ) cin >> pf[i] ;
        for ( int i=0 ; i<n ; i++ ) cin >> wt[i] ;
        cout << unboundedKnapsack(n,w,pf,wt) << endl;
    }
    
    return 0;
}