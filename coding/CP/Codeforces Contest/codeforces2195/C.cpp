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

    f(i,0,n) {
        cin >> a[i];
    }

    int cnt = 0;
    f(i,1,n){
        if ( (a[i-1] == a[i]) || (a[i] == 7-a[i-1]) ) {
            cnt++;
            f(j,1,6){
                if ( (j==a[i]) || (j==a[i-1]) || (j==a[i+1]) || (j==(7-a[i+1]))) continue;
                else {
                    a[i] = j;
                    break;
                }
            }
        }
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