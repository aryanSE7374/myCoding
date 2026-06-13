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

    vi vis(n+1, 0);

    f(j,0,n) {
        cin >> a[j];
        vis[a[j]] = 1;
    }

    int maxi = 0;

    int i=1;
    int len = 0;

    while (i < n+1) {
        while( (i < n+1) && vis[i]) {
            len++;
            i++;
        }
        maxi = max (maxi, len/2);
        len = 0;
        i++;
    }

    cout << maxi;

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