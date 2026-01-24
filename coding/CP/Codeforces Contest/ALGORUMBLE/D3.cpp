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

int N = 5000000;

vector<bool> isPrime( N+1 , true );
vector<int> sieve( N+1 , 0 );
vector<int> countPrimes( N+1 , 0 );

void preCompute(){

    for( int i=2 ; i*i <= N ; i++ ){
        if( isPrime[i] ){
            for( int j=i*i ; j <= N ; j+=i ){
                isPrime[j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i=2 ; i<=N ; i++ ){
        if(isPrime[i]) cnt++;
        countPrimes[i] = cnt ;
    }
}

void SOLVE(){

    int n;
    cin >> n;

    if ( n<3 ) {
        cout << 0 << "\n";
        return ;
    }

    cout << countPrimes[n-1] ;

    // vector<bool> isPrime( n+1 , true );
    // vector<int> sieve( n+1 , 0 );

    // for( int i=2 ; i*i <= n ; i++ ){
    //     if( isPrime[i] ){
    //         for( int j=i*i ; j <= n ; j+=i ){
    //             isPrime[j] = false;
    //         }
    //     }
    // }

    // int count = 0;

    // f(i,2,n){
    //     if(isPrime[i]) count++;
    // }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    preCompute();

    while(t-->0){

        SOLVE();

    }

    return 0;
}

