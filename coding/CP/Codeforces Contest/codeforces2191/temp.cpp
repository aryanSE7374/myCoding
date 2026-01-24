/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)


class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int maxSqSide = min ( m,n ) ;
        // int maxi = 1;

        for ( int k = maxSqSide ; k > 1 ; k-- ) {
            for ( int r=0 ; r <= m-k ; r++ ) {

                for ( int c=0 ; c <= n-k ; c++ ) {
                    // sq starting from (r,c) of side len = k

                    vector<int> rowSums( k,0 ) ;
                    vector<int> colSums( k,0 ) ;

                    int dgSum1 = 0 , dgSum2 = 0 ;

                    for ( int i=0 ; i<k ; i++ ) {
                        for ( int j=0 ; j<k ; j++ ) {

                            rowSums[i] += grid[i+r][j+c] ;
                            colSums[j] += grid[i+r][j+c] ;

                            if ( i == j ) {
                                dgSum1 += grid[i+r][j+c] ;
                            }

                            if ( i == k-j-1 ) {
                                dgSum2 += grid[i+r][j+c] ;
                            }

                        }
                    }

                    bool flag = true;

                    if ( dgSum1 != dgSum2 ) {
                        flag = false ;
                        // break;
                    } 

                    // if ( !flag ) break;
                    if (!flag) continue;

                    for ( int i=1 ; i<k ; i++ ) {
                        if ( rowSums[i-1] != rowSums[i] ) {
                            flag = false;
                            // break;
                        }
                    }

                    // if ( !flag ) break;
                    if (!flag) continue;

                    for ( int j=1 ; j<k ; j++ ) {
                        if ( colSums[j-1] != colSums[j] ) {
                            flag = false;
                            // break;
                        }
                    }

                    if ( flag && (rowSums[0] == colSums[0]) && (rowSums[0] == dgSum1 ) ) {
                        return k ;
                    }

                }
            }
        }

        return 1;

    }
};

void SOLVE(){


    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}