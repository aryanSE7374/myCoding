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



void SOLVE(){

    ll n;
    cin >> n;

    vll a(n);

    f(i,0,n) cin >> a[i];

    if ( is_sorted(a.begin() , a.end() ) ) {
        cout << -1;
        co_endl;
        return;
    }
    
    // Copy vector a in cp
    vll cp(n);
    // cp=a;
    f(i,0,n) cp[i]=a[i];
    
    sort( cp.begin() , cp.end() );

    // Keeping track of start and end index of correct place of num
    unordered_map< ll , ll > start , end ;

    start[cp[0]] = 0;

    for(int i=0 ; i<n-1 ; i++){
        if ( cp[i] != cp[i+1] ) {
            end[cp[i]] = i;
            start[cp[i+1]] = i+1;
        }
    }

    end[cp[n-1]] = n-1;

    // Hash set
    unordered_set<ll> visited;

    ll ans = 0;

    f(i,0,n-1){
        if ( visited.find(a[i]) == visited.end() && 
            ( i < start[a[i]] || end[a[i]] < i )
        ) {

            visited.insert(a[i]);

            ll maxi=0;
            f(j,start[a[i]],end[a[i]]+1){
                if ( a[j] != a[i] ) {
                    maxi = max ( maxi , llabs(a[j] - a[i]) );
                }
            }

            ans = max ( ans , maxi ) ;

        }

    }

    // if ( ans == 0 ) cout << -1;
    // cout << ans;

    ll maxdiff = INT_MAX ;
    f(i,0,n){
        if ( a[i] != cp[i] ) {
            ll mini = abs ( a[i] - cp[0] );
            ll maxi = abs ( a[i] - cp[n-1] );
            // maxdiff = max ( maxdiff , abs( a[i] - a[i+1] ) ) ;
            maxdiff = min ( maxdiff , max ( maxi , mini ) ) ;

        }
    }

    if ( maxdiff == INT_MAX ) cout << ans;
    else cout << max ( maxdiff , ans ) ;

    co_endl;
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