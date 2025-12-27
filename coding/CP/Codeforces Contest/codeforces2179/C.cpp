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

    int n;
    cin >> n;
    vll a(n);

    ll mini = INT_MAX;
    f(i,0,n){
        cin >> a[i];
        mini = min ( mini , a[i]); 
    }

    // ll ans1 = mini;

    ll ans = INT_MAX;

    f(i,0,n){
        if ( a[i] - mini > 0 ){
            ans = min ( ans , a[i]-mini );
        }
    }

    if (ans != INT_MAX ) {
        cout << max( ans , mini);
    }
    else{
        cout << mini;
    }

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