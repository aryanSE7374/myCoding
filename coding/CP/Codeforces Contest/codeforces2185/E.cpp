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
#define nl cout << '\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

#define INF 1e9 + 7

void SOLVE(){

    ll n , m , k ;

    cin >> n >> m >> k ;

    vll a(n) , b(m) , inst(k) , delta(k+1) ;
    string instStr;

    f ( i , 0 , n ) {
        cin >> a [i] ;
    }

    f ( i , 0 , m ) {
        cin >> b [i] ;
    }

    cin >> instStr ;

    f ( i , 0 , k ) {
        inst[i] = ( instStr[i] == 'L' ) ? -1 : 1 ;
    }

    
    // -------------------------------------------------------------------- // 

    sort(b.begin(), b.end());


    unordered_map< ll , ll > mpp ; // stores frst pos of delta acheived in inst
    
    // unordered_map< ll , ll > ans ; // stores the num of robos killed at idx i : { idx -> freq of kills }

    delta[0] = 0 ;
    f ( i , 1 , k+1 ) {
        
        delta[i] = delta[i-1] + inst[i-1] ;
        
        // if ( mpp.find ( delta[i] ) == mpp.end() ) {
        //     mpp[delta[i]] = i; // 0-based index
        // }
        
    }

    f ( i , 0 , k+1 ) {
        if ( mpp.find(delta[i]) == mpp.end() ) {
            mpp[delta[i]] = i; // 0-based index
        }
    }

    // -------------------------------------------------------------------- //
    
    vll left( n , -1 ) ; // 1st idx on left side of robo at a[i] that has a spike 
    vll right( n , INF ) ; // 1st idx on right side of robo at a[i] that has a spike 

    // find lower bound of x for all x in a[i] ( less than x )


    // find upper bound of x for all x in a[i] ( greater than x )


    vll leftdel (n); // a[i] - left[i]
    vll rightdel (n); // a[i] - right[i]

    vll minidel(n,0); // minidel[i] = min ( leftdel , rightdel )

    // -------------------------------------------------------------------- //

    vll printCnt(k+2,0);

    f ( i , 0 , n ) {

        ll pos = a[i];

        auto it = lower_bound( b.begin() , b.end() , pos ) ;

        ll minid = INF;

        // right side

        if ( it != b.end() ) {

            ll del = (*it) - pos;

            if ( mpp.find(del) != mpp.end() ) {
                minid = min ( minid , mpp[del] ) ;
            }

        }

        // left side

        if ( it != b.begin() ) {
            ll del = (*prev(it)) - pos;
            if ( mpp.find(del) != mpp.end() ) {
                minid = min ( minid , mpp[del] ) ;
            }
        }

        if ( minid <= k ) {
            printCnt[minid]++;
        }

    }

    // -------------------------------------------------------------------- //

    ll curr = n;
    
    f ( i , 1 , k+1 ) {
        curr -= printCnt[i];
        cout << curr << " ";
    }


    // -------------------------------------------------------------------- // 
    
    // unordered_map< ll , ll > mpp ; // stores frst pos of delta acheived in inst
    
    // // unordered_map< ll , ll > ans ; // stores the num of robos killed at idx i : { idx -> freq of kills }
    // map< ll , ll > ans ; // stores the num of robos killed at idx i : { idx -> freq of kills }
    
    // delta[0] = inst[0] ;
    // mpp[delta[0]] = 0 ; // 0-based index
    
    // f ( i , 1 , k ) {
        
    //     delta[i] = delta[i-1] + inst[i] ;
        
    //     if ( mpp.find ( delta[i] ) == mpp.end() ) {
    //         mpp[delta[i]] = i; // 0-based index
    //     }
        
    // }
    
    
    // // -------------------------------------------------------------------- // 


    // f(i,0,n){
    //     ans [ mpp[ minidel[i] ] ]++ ;
    // }

    // // -------------------------------------------------------------------- // 


    // vll printCnt ( k , -1 );
    // int curr = n ;
    // int last = 0 ;

    // for ( auto &[ idx , cnt ] : mpp ) {
    //     printCnt[ idx ] = curr-cnt ;
    //     curr = printCnt [ idx ] ;
    //     last = idx ;
    // }

    // // test
    // f(i,0,k) {
    //     if ( printCnt[i] == -1 ) {
    //         if ( i==0 ) printCnt[i] = n ;
    //         else printCnt[i] = printCnt[i-1];
    //     }
    //     cout << printCnt [i] << " " ;
    // }

    nl;


    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}