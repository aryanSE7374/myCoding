/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define f(i,a,n) for(int i=a ; i<n ; i++)


void SOLVE(){

    ll n , h , k ;

    cin >> n >> h >> k ;

    vll a(n);

    ll sum = 0;
    ll maxi = -1e9;

    f(i,0,n) {
        cin >> a[i];
        sum += a[i];
        maxi = max ( maxi , a[i] );
    }

    if ( h%sum == 0 ) {
        cout << (h/sum) * (k+n) - k  << "\n"; // no reload time
        return;
    }

    ll ans = (h/sum) * (k+n) ;

    h %= sum;

    /*
    the task boils down to finding the minimum number of elements that sum upto h, 
    given that atmost one swap is allowed

    brute : try all n^2 swaps - TLE

    --------------------------------

    better idea : greedy thought

    prefix sum karo... find index where prefix_sum >= h , partition blocks : B1 = [1...(idx-1)] , B2 rest
    in tht block , find the mini el index in B1 and maxi element index in B2
    swap maxi with mini

    now recalculate prefix sum ( running prefix O(1) space ) and count the index where pref >= h , 
    add idx+1 to the ans

    */
   
   // --------------------------------

    // if ( a[0] >= h ) {
    //     cout << ans+1 << "\n";
    //     return;
    // }
    
    // ll pref = a[0];

    // int j = 0;

    // ll mini1 = LLONG_MAX;
    // int minidx = 0;
    // ll maxi2 = LLONG_MIN;
    // int maxidx = n-1;

    // f(i,1,n){
    //     pref += a[i];
    //     if ( mini1 > a[i] ) {
    //         mini1 = a[i];
    //         minidx = i;
    //     }
    //     // mini1 = min ( mini1 , a[i] );
    //     if ( pref >= h ) {
    //         j=i;
    //         break;
    //     }
    // }

    // f(i,j,n){
    //     if ( maxi2 < a[i] ) {
    //         maxi2 = a[i];
    //         maxidx = i;
    //     }
    // }

    // a[minidx] = maxi2;
    // a[maxidx] = mini1;

    // pref = 0; // reset
    // ll time = 0;

    // f(i,1,n){

    //     pref += a[i];
    //     if ( pref >= h ) {
    //         time = i+1;
    //         break;
    //     }

    // }

    // cout << ans + time ;
    
    
    // --------------------------------

    /*

    greedy failed

    optimal idea : 

    prefix sum table , maximum after i in the block [i+1 , n-1]

    2 case : ya to swap karo , ya fir mat karo -> dono case me se minimal index that reaches prefsum >= h store krlo time me

    time - min ( time , min ( case1 , case2) )

    */ 

    // if ( a[0] >= h ) {
    //     cout << ans+1 << "\n";
    //     return;
    // }
    
    // ll pref = a[0];

    // int j = 0;

    // ll mini1 = LLONG_MAX;
    // int minidx = 0;
    // ll maxi2 = LLONG_MIN;
    // int maxidx = n-1;

    // f(i,1,n){
    //     pref += a[i];
    //     if ( mini1 > a[i] ) {
    //         mini1 = a[i];
    //         minidx = i;
    //     }
    //     // mini1 = min ( mini1 , a[i] );
    //     if ( pref >= h ) {
    //         j=i;
    //         break;
    //     }
    // }

    // f(i,j,n){
    //     if ( maxi2 < a[i] ) {
    //         maxi2 = a[i];
    //         maxidx = i;
    //     }
    // }

    // a[minidx] = maxi2;
    // a[maxidx] = mini1;

    // pref = 0; // reset
    // ll time = 0;

    // f(i,1,n){

    //     pref += a[i];
    //     if ( pref >= h ) {
    //         time = i+1;
    //         break;
    //     }

    // }

    // cout << ans + time ;

    vll pref(n);

    pref[0] = a[0];

    f(i,1,n) {
        pref[i] = a[i] + pref[i-1] ;
    }

    ll time = LLONG_MAX;

    f(i,0,n){
        if ( pref[i] >= h ) {
            time = i+1;
            break;
        }
    }

    vll maxii(n); // maximum element after i
    maxii[n-1] = a[n-1];

    for ( int i=n-2 ; i>=0 ; i-- ) {
        maxii[i] = max ( maxii[i+1] , a[i]);
    }

    int j = 0;
    f(i,0,n-1) {

        ll diff = 0;

        if ( maxii[i+1] > a[i] ) diff = maxii[i+1] - a[i];

        if ( (pref[i] + diff) >= h ){
            time = min ( time , (ll)(i+1) );
            continue;
        }

        if ( j < i ) j = i;

        while ( (j+1) < n && (pref[j] < h - diff) ) {
            j++;
        }

        if ( (pref[j] + diff ) >= h ) {
            time = min ( time , 1LL*(j+1) );
        }
    }

    cout << ans + time ;

    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}