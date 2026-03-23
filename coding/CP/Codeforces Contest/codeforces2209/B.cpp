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

    vi a(n);
    // vi b(n);

    f(i,0,n){
        cin >> a[i];
        // b[i] = a[i];
    }

    // sort ( b.begin(), b.end() );

    vi ans(n);

    f(i,0,n){
        int cnt1 = 0, cnt2=0;
        f(j,i+1,n){
            if ( a[i] < a[j] ) cnt1++;
            if ( a[i] > a[j] ) cnt2++;
        }
        ans[i] = max(cnt1, cnt2);
    }

    f(i,0,n) {
        cout << ans[i] << " ";
    }

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