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

    int n, k, p, m;

    cin >> n >> k >> p >> m;

    // debug(n,k,p,m);

    vi a(n);

    int mini = 1e9;

    f(i,0,n) {
        cin >> a[i];
        if ( i < k ) {
            mini = min ( mini, a[i] );
        }
    }

    // debug(a);
    // debug(mini);

    vi cost(n-k+1);
    cost[0] = mini;
    int sz = n-k+1;
    vi pref(sz+1);
    pref[0] = 0;
    pref[1] = mini;

    // cout << pref[0] << " " << pref[1] << " ";

    f(i,2,sz+1) {
        pref[i] = pref[i-1] + a[k+i-2];
        // cout << pref[i] << " ";
    }

    // debug(pref);

    // int costWC = (p>k) ? pref[p-k+1] : pref[1];
    // int costWC = (p<=k) ? a[p-1] : pref[p-k+1];

    int costWC = a[p-1];

    if ( p > k ) {
        vi temp;

        f(i,0,p-1) {
            temp.push_back(a[i]);
        }

        sort(temp.begin(), temp.end());

        f(i,0,p-k) {
            costWC += temp[i];
        }
    }

    // int cycleCost = pref[sz];
    int cycleCost = a[p-1];

    if ( n > k ) {
        vi temp;

        f(i,0,n) {
            if ( i != p-1 ) {
                temp.push_back(a[i]);
            }
        }

        sort(temp.begin(), temp.end());

        f(i,0,n-k) {
            cycleCost += temp[i];
        }
    }

    // debug(costWC, cycleCost);

    int cnt = 0;
    if ( m >= costWC ) {
        cnt = 1;
        m -= costWC;
        cnt += m/cycleCost;

    }

    // int cnt = m/cycleCost;
    // int rem = m % cycleCost;

    // // debug(cnt, rem);

    // if ( rem >= costWC ) cnt++;

    // // debug(cnt);

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