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

    ll x ;
    cin >> x;

    ll sum = 0;
    ll num = x;
    
    vll digs;
    vll freq(10,0); // 0 to 9

    while ( num > 0 ) {
        ll rem = num%10;
        digs.push_back(rem);
        freq[rem]++;
        sum += rem;
        num /= 10;
    }

    if ( sum < 10 ) {
        cout << 0 << "\n";
        return;
    }

    int n = digs.size();
    ll first = digs[n-1];

    sort ( digs.rbegin() , digs.rend() ) ;

    ll digit = 9;
    ll ops = 0;

    while ( (sum > 9) && ( digit>0 ) ) {

        if ( freq[digit] > 0 ) {
            if ( digit == first && freq[digit] == 1 ) {
                sum -= (digit-1);
                ops++;
                freq[digit]--;
            }
            else {
                sum -= digit;
                ops++;
                freq[digit]--;
            }
        }
        else {
            digit--;
        }
    }

    cout << ops;

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