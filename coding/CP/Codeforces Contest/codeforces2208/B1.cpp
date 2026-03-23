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
    // vi pref(sz+1);
    // pref[0] = 0;
    // pref[1] = mini;

    priority_queue<int, vector<int>, greater<int> > pq; // minHeap

    // int costWC = (p>k) ? pref[p-k+1] : pref[1];
    // int costWC = (p<=k) ? a[p-1] : pref[p-k+1];

    int costWC = 0;
    int costCycle = 0 ;
    int cnt = 0;


    if ( p < k ) costWC = a[p-1];
 
    if (p >= k ) {
        for ( int i=0; i<k; i++ ) {
            pq.push(a[i]);
        }
    
        costWC += pq.top();
        pq.pop();
    
        // 3 4 4 2 1 1 4 2
        for ( int i=k; i<p-1; i++ ) {
            pq.push(a[i]);
            costWC += pq.top();
            pq.pop();
        }
    
        costWC += a[p];
    
        costCycle = costWC;
    
        for ( int i=p-1; i<n; i++ ) {
            costCycle += a[i];
        }

        if ( m >= costWC ) {
            m -= costWC;
            cnt++;
        }

        cnt += (m/costCycle);

        cout << cnt << "\n";
        return;

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