#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

/*

// recursive

int f( int R , int C , vector<vector<int>> &G , int i , int ja , int jb ){

    // boundary base cases
    if( ja < 0 || jb < 0 || ja >= C || jb >= C ) return -INF;

    // destination edge case
    if ( i == R-1 ) {
        return ( ja == jb ) ? G[i][ja] : ( G[i][ja] + G[i][jb] ) ;
    }

    int ans = -INF;

    for ( int dja = -1 ; dja <= 1 ; dja++ ) {
        for ( int djb = -1 ; djb <= 1 ; djb++ ) {
            ans = max ( ans , ( ( ja==jb ) ? G[i][ja] : (G[i][ja] + G[i][jb]) ) + f( R , C , G , i+1 , ja + dja , jb + djb) ) ;
        }
    }

    return ans;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(r,c,grid,0,0,c-1);
}

// ------------------------------------------------------------------------------------------------------------------ // 

// memo

int f( int R , int C , vector<vector<int>> &G , int i , int ja , int jb , vector<vector<vector<int>>>& memo){

    // boundary base cases
    if( ja < 0 || jb < 0 || ja >= C || jb >= C ) return -INF;

    // destination edge case
    if ( i == R-1 ) {
        return ( ja == jb ) ? G[i][ja] : ( G[i][ja] + G[i][jb] ) ;
    }

    // memo check
    if ( memo[i][ja][jb] != -INF ) return memo[i][ja][jb];

    int ans = -INF;

    for ( int dja = -1 ; dja <= 1 ; dja++ ) {
        for ( int djb = -1 ; djb <= 1 ; djb++ ) {
            ans = max ( ans , ( ( ja==jb ) ? G[i][ja] : (G[i][ja] + G[i][jb]) ) + f( R , C , G , i+1 , ja + dja , jb + djb , memo) ) ;
        }
    }

    return memo[i][ja][jb] = ans;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> memo( r+1 , vector<vector<int>>( c+1 , vector<int>(c+1,-INF) ) );
    return f(r,c,grid,0,0,c-1,memo);
}

// ------------------------------------------------------------------------------------------------------------------ // 

// tabulation - my try (submitted)

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> dp( r+1 , vector<vector<int>>( c+1 , vector<int>(c+1,-INF) ) );

    // Base case: last row
    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // Fill DP bottom-up
    for (int i = r - 2; i >= 0; i--) {                 
        for (int ja = 0; ja < c; ja++) {
            for (int jb = 0; jb < c; jb++) {

                int val = -1e9; // reset for each state

                // 3*3 iterations for each state
                for (int dja = -1; dja <= 1; dja++) {
                    for (int djb = -1; djb <= 1; djb++) {

                        int nja = ja + dja;
                        int njb = jb + djb;

                        if (nja >= 0 && nja < c && njb >= 0 && njb < c) {
                            val = max( val , dp[i+1][nja][njb] );
                        }
                    }
                }

                int curr = (ja == jb) ? grid[i][ja] : grid[i][ja] + grid[i][jb];
                dp[i][ja][jb] = curr + val;

            }
        }
    }

    return dp[0][0][c-1];

}

*/


// space optimization 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> dp( r+1 , vector<vector<int>>( c+1 , vector<int>(c+1,-INF) ) );

    // dp[i+1] = front
    //dp[i] = curr

    vector<vector<int>> front(c,vector<int>(c,-1));
    vector<vector<int>> curr(c,vector<int>(c,-1));

    // Base case: last row
    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2) front[j1][j2] = grid[r-1][j1];
            else front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // Fill DP bottom-up
    for (int i = r - 2; i >= 0; i--) {                 
        for (int ja = 0; ja < c; ja++) {
            for (int jb = 0; jb < c; jb++) {

                int val = -1e9; // reset for each state

                // 3*3 iterations for each state
                for (int dja = -1; dja <= 1; dja++) {
                    for (int djb = -1; djb <= 1; djb++) {

                        int nja = ja + dja;
                        int njb = jb + djb;

                        if (nja >= 0 && nja < c && njb >= 0 && njb < c) {
                            val = max( val , front[nja][njb] );
                        }
                    }
                }

                int temp = (ja == jb) ? grid[i][ja] : grid[i][ja] + grid[i][jb];
                curr[ja][jb] = temp + val;

            }
        }
        front = curr;
    }

    return front[0][c-1];

}

int main(){

    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        vector<vector<int>> grid(r,vector<int>(c));
        for(int i = 0; i < r ; i++){
            for ( int j = 0 ; j<c ; j++){
                cin >> grid[i][j];
            }
        }
        cout << maximumChocolates(r,c,grid)<<endl;
    }

    return 0;
}