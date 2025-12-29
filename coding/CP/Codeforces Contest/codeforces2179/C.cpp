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


// rec

ll fun( vll &a , int n , ll X , int i , int j ){

    if ( j==n ) return X;

    // if ( j == n-1) return X + max( a[i] , -1LL*a[j] );

    return max ( fun( a , n , X+a[i] , j , j+1  ) , fun( a , n , X-a[j] , i , j+1  ) ) ;

}

// memo

ll fun1( vector< vll > &memo , vll &a , int n , int i , int j ){

    if ( j==n ) return 0;

    if( memo[i][j] != LLONG_MIN ) return memo[i][j] ;

    // if ( j == n-1) return X + max( a[i] , -1LL*a[j] );

    return memo[i][j] = max ( a[i] + fun1( memo , a , n , j , j+1  ) , -1LL*a[j] + fun1( memo , a , n , i , j+1  ) ) ;

}

// tabulate

ll solve1( vector<ll>& a , int n ) {

    vector< vll > dp( n+1 , vll(n+1 , 0));

    for(int j = n - 1 ; j >= 1 ; j--){
        for(int i = j - 1 ; i >= 0 ; i--){
            dp[i][j] = max( a[i] + dp[j][j + 1] , -1LL*a[j] + dp[i][j + 1] );
        }
    }

    return dp[0][1];

}

// space optimize

ll solve2( vector<ll>& a , int n ) {

    // vector< vll > dp( n+1 , vll(n+1 , 0));

    vll temp( n+1 , 0);
    vll curr( n+1 , 0);

    for(int j = n - 1 ; j >= 1 ; j--){
        for(int i = j - 1 ; i >= 0 ; i--){
            curr[i] = max ( a[i] + temp[j] , -1LL*a[j] + temp[i] ) ;
        }
        temp = curr;
    }

    return temp[0];

}

void SOLVE(){


    int n;
    cin >> n;

    vll a(n);

    f(i,0,n){
        cin >> a[i];
    }

    // vector< vll > memo( n+1 , vll(n+1,LLONG_MIN) ) ;

    cout << solve2(a,n);

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