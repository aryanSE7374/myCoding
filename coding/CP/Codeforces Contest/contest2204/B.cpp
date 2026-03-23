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

    // vector< pair<int, int> > idx(n);
    // unordered_map<int, vector<int> > indices;
    unordered_map<int, set<int> > indicess;


    f(i,0,n){
        cin >> a[i];
        // idx[i] = {a[i],i};
        // indices[a[i]].push_back(i);
        indicess[a[i]].insert(i);
    }

    // sort(idx.begin(), idx.end());
    sort(a.rbegin(), a.rend());

    int cnt = 0;
    int lastIdx = n;

    for ( auto& num : a ) {
        for ( auto it = indicess[num].end(); it != indicess[num].begin() ; it-- )  {
            it--;
            if ( *it < lastIdx ) {
                cnt++;
                lastIdx = *it;
            }
            if ( lastIdx == 0 ) {
                cout << cnt << "\n";
                return;
            }
            if ( it == indicess[num].begin() ) {
                if ( *it < lastIdx ) {
                    cnt++;
                    lastIdx = *it;
                }
                if ( lastIdx == 0 ) {
                    cout << cnt << "\n";
                    return;
                }
            }
        }
        // int j = indices[num].size()-1;
        // while( j >= 0 ) {
        //     if ( indices[num][j] < lastIdx ) {
        //         cnt++;
        //         lastIdx = indices[num][j];
        //     }
        //     if ( lastIdx == 0 ) {
        //         cout << cnt << "\n";
        //         return;
        //     }
        //     j--;
        // }
    }




    // int cnt = 1;
    // for ( int i=n-1; i>0 ; i-- ) {
    //     if ( a[i-1] <= a[i] ) cnt++;
    // }

    // cout << cnt;

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