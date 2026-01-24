/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

void SOLVE(){

    int N, M;
    cin >> N >> M;

    vector<vi> A(N, vi(M));
    vector<vi> B(N, vi(M));

    bool all0_A = true , all1_A = true , all0_B = true , all1_B = true;

    bool identical = true;

    f(i,0,N){
        f(j,0,M){
            cin >> A[i][j];
            if (A[i][j] == 0) all1_A = false;
            else all0_A = false;
        }
    }

    f(i,0,N){
        f(j,0,M){
            cin >> B[i][j];
            if (B[i][j] != A[i][j]) identical = false;
            if (B[i][j] == 0) all1_B = false;
            else all0_B = false;
        }
    }

    // check both all 1
    bool both1  = all1_A && all1_B ;
    // if ( both1 ) {
    //     cout << "YES\n";
    //     return;
    // }

    // A == B
    if (identical) {
        cout << "YES\n";
        return;
    }

    // only 1 row
    if (N == 1) {

        int xorA = 0 , xorB = 0 , cnt1_A = 0 , cnt1_B = 0;

        f(j,0,M){
            xorA ^= A[0][j];
            xorB ^= B[0][j];
            if (A[0][j] == 1) cnt1_A++;
            if (B[0][j] == 1) cnt1_B++;
        }

        if (xorA == 0 ){
            if ( ( xorB != 0 || cnt1_B > cnt1_A ) ) cout << "NO\n";
        } 

        else cout << "YES\n";

        return;

    }

    // only 1 col
    if (M == 1) {

        int xorA = 0, xorB = 0;
        int cnt1_A = 0, cnt1_B = 0;

        f(i,0,N){
            xorA ^= A[i][0];
            xorB ^= B[i][0];
            if (A[i][0] == 1) cnt1_A++;
            if (B[i][0] == 1) cnt1_B++;
        }

        if (xorA == 0 ){
            if ( ( xorB != 0 || cnt1_B > cnt1_A ) ) cout << "NO\n";
        }

        else
            cout << "YES\n";

        return;
    }

    // all zeroes - always true
    if ( all0_A || all0_B ) {
        cout << ( (all0_A && all0_B) ? "YES\n" : "NO\n");
        return;
    }

    // Case 5: Both dimensions odd and one grid all ones
    // odd dimensioins < = > all ones in A or B
    if ( N%2 == 1 && M%2 == 1 ){
        if ( all1_A || all1_B ){
            if ( both1 ) cout << "YES\n" ;
            else cout << "NO\n";
        }
        return;
    }

    cout << "YES";
    co_endl ;
}

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     SOLVE();

//     return 0;
// }

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