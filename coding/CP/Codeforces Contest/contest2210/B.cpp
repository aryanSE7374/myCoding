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

    int n;
    cin >> n;

    vi p(n+1);
    // vi diff(n+1);
    // vi marked(n+1, 0);
    int ans = 0;
    // int mini = 1e9;
    f(i,1,n+1){
        cin >> p[i];
        // diff[i] = p[i] - i;
    }

    f(i,1,n+1){

        if ( p[i] <= i ) ans++;
        // mini = min ( mini, p[i] );
        
        // if ( mini < i ) {
        //     cout << ans << "\n";
        //     return;
        // }
        // ans++;

    }

    cout << ans;

    // if ( maxi == 0 ) cout << n;
    // else cout << maxi ;

    // int ans = 0;
    // f(i,1,n+1){
    //     if ( marked[i] ) break;
    //     if ( diff[i] >= maxi || diff[i] <= 0 &&  ) {
    //         ans ++;
    //     }
    //     else {
            

    //     }
    // }


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