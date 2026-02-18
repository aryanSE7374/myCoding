/*
code by - Aryan
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

    vi p(n);
    vi a(n);

    vi idx(n+1); // 0 based index for nums from 1 to n

    f(i,0,n){
        cin >> p[i];
        idx[p[i]] = i;
    }

    f(i,0,n){
        cin >> a[i];
    }

    // check for alternating case
    f(i,0,n-1){
        if( (p[i] == a[i+1]) && (p[i+1] == a[i]) ) {
            cout << "NO\n";
            return;
        }
    }

    bool flag = true;

    int j = 0;

    f(i,0,n){
        if(j<n){
            if ( p[i] == a[j] ) {
                while(j<n){
                    if (a[j]==p[i]) j++;
                    else break;
                }
            }
        }
    }
    
    if ( j<n ) flag = false;
    if (flag) cout <<"YES";
    else cout << "NO";

    cout << '\n';

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