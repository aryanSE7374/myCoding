#include<bits/stdc++.h>
using namespace std;

// code 360 : https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003

// alternative - GFG : https://www.geeksforgeeks.org/problems/geeks-training/1

// my solutions

// rec code : 

int fr(int n , vector<vector<int>> &pts , int i){

    // i -> activity num 
    // for i : rec call for (i+1)%3 and (i+2)%3

    if( n == 0 ) return pts[n][i];

    return ( pts[n][i] + max ( fr(n-1,pts,(i+1)%3) , fr(n-1,pts,(i+2)%3) ) ) ;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return max ( fr(n-1,points,0) , max ( fr(n-1,points,1) , fr(n-1,points,2) ) );
}


// memo

int f(int n , vector<vector<int>> &pts , int i , vector<vector<int>>& memo ){

    // i -> activity num 
    // for i : rec call for (i+1)%3 and (i+2)%3

    if( n == 0 ) return pts[n][i];

    if ( memo[n][i] != -1 ) return memo[n][i] ;

    return memo[n][i] = ( pts[n][i] + max ( f(n-1,pts,(i+1)%3,memo) , f(n-1,pts,(i+2)%3,memo) ) ) ;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector< vector<int> > memo(n,vector<int>(3,-1));

    return max ( f(n-1,points,0,memo) , max ( f(n-1,points,1,memo) , f(n-1,points,2,memo) ) );

}


// tabulate

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector< vector<int> > dp(n,vector<int>(3,-1));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    for(int j=1 ; j<n ; j++){

        for(int i=0 ; i<3 ; i++){
            dp[j][i] = ( points[j][i] + max ( dp[j-1][(i+1)%3] , dp[j-1][(i+2)%3] ) ) ;
        }
        
    }

    return max ( dp[n-1][0] , max ( dp[n-1][1] , dp[n-1][2] ) ) ;

}


// memory optimization - passed

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<int> curr = { points[0][0] , points[0][1] , points[0][2] } ;
    vector<int> prev = { points[0][0] , points[0][1] , points[0][2] } ;

    for(int j=1 ; j<n ; j++){

        for(int i=0 ; i<3 ; i++){

            curr[i] =  ( points[j][i] + max ( prev[(i+1)%3] , prev[(i+2)%3] ) ) ;
            
        }
        prev = curr;
        
    }

    return max ( curr[0] , max ( curr[1] , curr[2] ) ) ;

}


// ------------------------------------------------------------------------------------------ //

// striver's solutions

// rec

int f(int day, int last, vector<vector<int>> &points) {
    // Base case: Day 0
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    // Try all possible tasks except the last one
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + f(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    return f(n - 1, 3, points);
}

// memo - by striver

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>>& dp) {
    // Base case: Day 0
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if ( dp[day][last] != -1 ) return dp[day][last] ;

    int maxi = 0;

    // Try all possible tasks except the last one
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp( n , vector<int>(4,-1) );
    return f(n - 1, 3, points,dp);
}


// tabulate - by striver

int ninjaTraining(int n, vector<vector<int>> &points) {

    vector<vector<int>> dp( n , vector<int>(4,-1) );

    dp[0][0] = max ( points[0][1] , points[0][2] );
    dp[0][1] = max ( points[0][0] , points[0][2] );
    dp[0][2] = max ( points[0][0] , points[0][1] );
    dp[0][3] = max ( points[0][0] , max ( points[0][1] , points[0][2] ) );

    for( int day=1 ; day<n ; day++ ){
        for(int last = 0 ; last<4 ; last++){
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi , point);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n-1][3];

}


// space optimization - by striver

int ninjaTraining(int n, vector<vector<int>> &points) {

    vector<int> prev(4,0);

    prev[0] = max ( points[0][1] , points[0][2] );
    prev[1] = max ( points[0][0] , points[0][2] );
    prev[2] = max ( points[0][0] , points[0][1] );
    prev[3] = max ( points[0][0] , max ( points[0][1] , points[0][2] ) );

    for( int day=1 ; day<n ; day++ ){
        vector<int> temp(4,0);
        for(int last = 0 ; last<4 ; last++){
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi , point);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }

    return prev[3];

}
