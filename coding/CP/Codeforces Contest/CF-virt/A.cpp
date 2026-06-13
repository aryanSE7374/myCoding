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
    vi freq(201, 0);

    bool flag = true;
    
    f(i,0,n) {
        cin >> a[i];
        freq[a[i]]++;
        if ( freq[a[i]]>1 ) {
            flag = false;
        }
    }

    if ( !flag ) {
        cout << -1 << endl;
        return;
    }

    sort(a.rbegin(), a.rend());

    f(i,0,n){
        cout << a[i] << " ";
    }

    cout<<'\n';


    // for ( int i=1; i<n; i++ ) {
    //     for ( int j=0; j<i; j++ ) {
    //         int summ = 0;
    //         for ( int k=j; k<i; k++ ) {
    //             summ += a[k];
    //             if ( summ == a[i] ) {
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }

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