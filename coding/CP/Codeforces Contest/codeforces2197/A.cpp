/*
code by - Aryan
*/

/*
observations : 
// Brute Force
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


int sumOfDigs( int N ){
    int sum = 0;
    while (N>0) {
        sum += (N%10);
        N/=10;
    }
    return sum;
}

void SOLVE(){

    ll x;
    cin >> x;
    
    // int div = x/9;
    
    // if ( (x%9 == 0) ) {
    //     if ( (div - 10)%11 == 0 ) cout << 0;
    //     else cout << 10;
    // }
    // else cout << 0;


    int y = x;
    int cnt = 0;
    int dy = sumOfDigs(y);
    while ( (y - dy) <= x ) {
        // cerr << "dy : " << dy << "\n";
        if ( (y - dy) == x ) {
            cnt++;
        }
        y++;
        dy = sumOfDigs(y);
    }
    cout << cnt;

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