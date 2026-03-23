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

    int n, m, k; cin >> n >> m >> k;

    // if(k >= m)  cout <<"NO";
    // else    cout <<"YES";

    int mx = ceil(1.0*n/1.0*m);
    // cout << mx << "\n";
    if ( m==1 || m==k ) {
        cout << "NO";
    }
    else if( k >= (n-mx) )  cout <<"NO";
    else cout <<"YES";
    

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