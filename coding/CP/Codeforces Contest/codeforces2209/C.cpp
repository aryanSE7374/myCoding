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

int ask(int i, int j){

    cout << "? " << i << " " << j << '\n';
    cout.flush();

    int res;
    if(!(cin >> res)) exit(0);
    if(res == -1) exit(0);

    return res;
}

void answer(int k){
    cout << "! " << k << '\n';
    cout.flush();
}

void SOLVE(){
    int n;
    cin >> n;

    // vector<int> a(2*n + 1, 0);

    // for(int i=2; i<=n; i++ ) {
    //     int response = ask(1, i);
    //     if ( response == 1 ) {
    //         answer(i);
    //         return;
    //     }
    // }
    // answer(n+1);
    // for ( int i=1; i < 2*n; i+=2 ) {
    //     int response = ask(1, i);
    //     if ( response == 1 ) {
    //         answer(i);
    //         return;
    //     }
    // }
    // int response = ask(2, 4);
    // if ( response == 1 ) {
    //     answer(2);
    //     return;
    // }
    // answer(1);
    // return;

    int res1 = ask(1, 2);
    if(res1 == 1){ answer(1); return; }

    int res2 = ask(2, 3);
    if(res2 == 1){ answer(2); return; }

    int res3 = ask(1, 3);
    if(res3 == 1){ answer(1); return; }

    for(int i = 4 ; i < 2*n ; i += 2 ) {

        int response = ask(i , i+1);
        if(response == 1){
            
            answer(i);
            
            return;
            
        }
    }

    answer(2*n);
    
    return;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        SOLVE();
    }
    return 0;
}
