/*
code by - Aryan Shrivastav
*/

/*
observations : 

*/

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define vi vector<int>
// #define vll vector<long long>
// #define co_endl cout<<'\n'
// #define f(i,a,n) for(int i=a ; i<n ; i++)

// void SOLVE(){

//     int N , M ;
//     cin >> N >> M ;

//     vector < vi > A( N , vi(M) );
//     vector < vi > B( N , vi(M) );

//     f(i,0,N){f(j,0,M){cin >> A[i][j] ;}}
//     f(i,0,N){f(j,0,M){cin >> B[i][j] ;}}

// /*

//     vi RR_A(N,0);
//     vi RR_B(N,0);
//     vi CR_A(M,0); 
//     vi CR_B(M,0);

//     f(i,0,N){
//         // int xra = 0 , xrb = 0 ;
//         f(j,0,M){
//             RR_A[i] ^= A[i][j];
//             RR_B[i] ^= B[i][j];
//         }
//     }

//     f(j,0,M){
//         // int xra = 0 , xrb = 0 ;
//         f(i,0,N){
//             CR_A[j] ^= A[i][j];
//             CR_B[j] ^= B[i][j];
//         }
//     }

//     // bool ans = true;

//     f(i,0,N){
//         if ( RR_A[i] != RR_B[i] ){
//             cout << "NO\n";
//             return;
//         }
//     }

//     f(j,0,M){
//         if ( CR_A[j] != CR_B[j] ){
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n" ;
//     return;


// */

// /*

//     // vi RR(N);
//     // vi CR(M);

//     f(i,0,N){
//         int xr = 0;
//         f(j,0,M){
//             xr ^= A[i][j];
//         }
//         RR[i] = xr ;
//     }

//     f(j,0,M){
//         int xr = 0;
//         f(i,0,N){    
//             xr ^= A[i][j];
//         }
//         CR[j] = xr ;
//     }

//     bool operated = true;

//     while( operated == true ){

//         operated = false;

//         f(i,0,N){
//             f(j,0,M){

//                 if( A[i][j] != B[i][j] ) {

//                     int a = A[i][j] ;

//                     if ( RR[i] == B[i][j] ){
//                         A[i][j] = B[i][j];
//                         RR[i] = RR[i] ^ B[i][j] ^ a ;
//                         CR[j] = CR[j] ^ B[i][j] ^ a ;
//                         operated = true;
//                     }

//                     else if ( CR[j] == B[i][j] ){
//                         A[i][j] = B[i][j];
//                         CR[j] = CR[j] ^ B[i][j] ^ a ;
//                         RR[i] = RR[i] ^ B[i][j] ^ a ;
//                         operated = true;
//                     }

//                 }
//             }
//         }

//     }

//     bool ans = true;

//     f(i,0,N){
//         f(j,0,M){
            
//             if( A[i][j] != B[i][j] ) {
//                 ans = false;
//                 break;
//             }
//         }
//     }

//     if ( ans ) { cout << "YES\n" ; }
//     else cout << "NO\n" ;
// */
//     // co_endl;

// }

// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin>>t;
//     while(t-->0){

//         SOLVE();

//     }

//     return 0;
// }



/*
code by - Aryan Shrivastav
*/

/*
observations : 
1. The operation A[i][j] = RowXor replaces the cell with the row's XOR sum.
   This effectively swaps the value of the cell with the 'potential' of the row.
2. The state space is connected based on the total parity of 1s, with specific "island" states.
3. Isolated States (Locks):
   - All Zeros: Can never change (RowXor=0, ColXor=0 everywhere).
   - All Ones (ONLY if N and M are both Odd): Can never change (RowXor=1, ColXor=1).
4. If A is locked and A != B, impossible.
5. If B is locked and A != B, impossible (operations are reversible).
6. Otherwise, YES if TotalParity(A) == TotalParity(B).
*/


// // GEMINI
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define vi vector<int>
// #define vll vector<long long>
// #define co_endl cout<<'\n'
// #define f(i,a,n) for(int i=a ; i<n ; i++)

// // Function to check if a grid is All Zeros
// bool isAllZeros(int N, int M, const vector<vi>& G) {
//     f(i,0,N) {
//         f(j,0,M) {
//             if(G[i][j] == 1) return false;
//         }
//     }
//     return true;
// }

// // Function to check if a grid is All Ones
// bool isAllOnes(int N, int M, const vector<vi>& G) {
//     f(i,0,N) {
//         f(j,0,M) {
//             if(G[i][j] == 0) return false;
//         }
//     }
//     return true;
// }

// void SOLVE(){
//     int N , M ;
//     cin >> N >> M ;

//     vector < vi > A( N , vi(M) );
//     vector < vi > B( N , vi(M) );

//     ll countA = 0;
//     ll countB = 0;
//     bool identical = true;

//     f(i,0,N){
//         f(j,0,M){
//             cin >> A[i][j];
//             if(A[i][j]) countA++;
//         }
//     }
//     f(i,0,N){
//         f(j,0,M){
//             cin >> B[i][j];
//             if(B[i][j]) countB++;
//             if(A[i][j] != B[i][j]) identical = false;
//         }
//     }

//     // 1. If grids are already identical, YES.
//     if(identical) {
//         cout << "YES\n";
//         return;
//     }

//     // 2. Check "Locked" states for A
//     // Lock 1: All Zeros (Always locked)
//     if (isAllZeros(N, M, A)) {
//         cout << "NO\n"; // B is not all zeros (checked by identical)
//         return;
//     }
//     // Lock 2: All Ones (Locked only if N and M are both Odd)
//     if (N % 2 != 0 && M % 2 != 0 && isAllOnes(N, M, A)) {
//         cout << "NO\n";
//         return;
//     }

//     // 3. Check "Locked" states for B (Symmetry)
//     // If B is a locked state, and we know A != B, we can never reach B.
//     if (isAllZeros(N, M, B)) {
//         cout << "NO\n";
//         return;
//     }
//     if (N % 2 != 0 && M % 2 != 0 && isAllOnes(N, M, B)) {
//         cout << "NO\n";
//         return;
//     }

//     // 4. Parity Check
//     // For most cases, we can transform A to B iff parities match.
//     if (countA % 2 != countB % 2) {
//         cout << "NO\n";
//     } else {
//         cout << "YES\n";
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin>>t;
//     while(t-->0){
//         SOLVE();
//     }

//     return 0;
// }


// gemini 2

/*
code by - Aryan Shrivastav
*/

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define vi vector<int>
// #define co_endl cout<<'\n'
// #define f(i,a,n) for(int i=a ; i<n ; i++)

// // Helper to check if grid is All Zeros
// bool isAllZeros(int N, int M, const vector<vi>& G) {
//     f(i,0,N) {
//         f(j,0,M) {
//             if(G[i][j] == 1) return false;
//         }
//     }
//     return true;
// }

// // Helper to check if grid is All Ones
// bool isAllOnes(int N, int M, const vector<vi>& G) {
//     f(i,0,N) {
//         f(j,0,M) {
//             if(G[i][j] == 0) return false;
//         }
//     }
//     return true;
// }

// void SOLVE(){
//     int N , M ;
//     cin >> N >> M ;

//     vector < vi > A( N , vi(M) );
//     vector < vi > B( N , vi(M) );

//     bool identical = true;

//     // Input A
//     f(i,0,N){
//         f(j,0,M){
//             cin >> A[i][j];
//         }
//     }

//     // Input B and check identity
//     f(i,0,N){
//         f(j,0,M){
//             cin >> B[i][j];
//             if(A[i][j] != B[i][j]) identical = false;
//         }
//     }

//     // 
    
//     // 1. If grids are identical, we are already there.
//     if(identical) {
//         cout << "YES\n";
//         return;
//     }

//     // 2. Identify Locked States
//     // A state is locked if no operation can change it.
//     // Case 1: All Zeros is ALWAYS locked.
//     // Case 2: All Ones is locked ONLY IF both N and M are Odd.
    
//     bool A_is_Locked = false;
//     if (isAllZeros(N, M, A)) A_is_Locked = true;
//     else if (N % 2 != 0 && M % 2 != 0 && isAllOnes(N, M, A)) A_is_Locked = true;

//     bool B_is_Locked = false;
//     if (isAllZeros(N, M, B)) B_is_Locked = true;
//     else if (N % 2 != 0 && M % 2 != 0 && isAllOnes(N, M, B)) B_is_Locked = true;

//     // 3. Decision
//     // If we are stuck in A, we can't move.
//     if (A_is_Locked) {
//         cout << "NO\n";
//         return;
//     }
//     // If B is an isolated locked state, we can't enter it from outside.
//     if (B_is_Locked) {
//         cout << "NO\n";
//         return;
//     }

//     // Otherwise, the component is connected.
//     cout << "YES\n";
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin>>t;
//     while(t-->0){
//         SOLVE();
//     }

//     return 0;
// }


/*

*/

/*
code by - Aryan Shrivastav
*/


// hacker rank editorial


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define vi vector<int>
// #define f(i,a,n) for(int i=a ; i<n ; i++)

// void SOLVE(){

//     int N, M;
//     cin >> N >> M;

//     vector<vi> A(N, vi(M));
//     vector<vi> B(N, vi(M));

//     bool all0_A = true , all1_A = true , all0_B = true , all1_B = true;

//     bool identical = true;

//     f(i,0,N){
//         f(j,0,M){
//             cin >> A[i][j];
//             if (A[i][j] == 0) all1_A = false;
//             else all0_A = false;
//         }
//     }

//     f(i,0,N){
//         f(j,0,M){
//             cin >> B[i][j];
//             if (B[i][j] != A[i][j]) identical = false;
//             if (B[i][j] == 0) all1_B = false;
//             else all0_B = false;
//         }
//     }

//     // check both all 1
//     bool both1  = all1_A && all1_B ;
//     if ( both1 ) {
//         cout << "YES\n";
//         return;
//     }

//     // A == B
//     if (identical) {
//         cout << "YES\n";
//         return;
//     }

//     // all zeroes - always true
//     if ( all0_A || all0_B ) {
//         cout << ((all0_A && all0_B) ? "YES\n" : "NO\n");
//         return;
//     }

//     // only 1 row
//     if (N == 1) {

//         int xorA = 0 , xorB = 0 , cnt1_A = 0 , cnt1_B = 0;

//         f(j,0,M){
//             xorA ^= A[0][j];
//             xorB ^= B[0][j];
//             if (A[0][j] == 1) cnt1_A++;
//             if (B[0][j] == 1) cnt1_B++;
//         }

//         if (xorA == 0 ){
//             if ( ( xorB != 0 || cnt1_B > cnt1_A ) ) cout << "NO\n";
//         } 

//         else cout << "YES\n";

//         return;

//     }

//     // only 1 col
//     if (M == 1) {

//         int xorA = 0, xorB = 0;
//         int cnt1_A = 0, cnt1_B = 0;

//         f(i,0,N){
//             xorA ^= A[i][0];
//             xorB ^= B[i][0];
//             if (A[i][0] == 1) cnt1_A++;
//             if (B[i][0] == 1) cnt1_B++;
//         }

//         if (xorA == 0 ){
//             if ( ( xorB != 0 || cnt1_B > cnt1_A ) ) cout << "NO\n";
//         }

//         else
//             cout << "YES\n";

//         return;
//     }

//     // Case 5: Both dimensions odd and one grid all ones
//     // odd dimensioins < = > all ones in A or B
//     if ( N%2 == 1 && M%2 == 1 ){
//         if ( all1_A || all1_B ){
//             if ( both1 ) cout << "YES\n" ;
//             else cout << "NO\n";
//         }
//         return;
//     }

//     cout << "YES";
//     co_endl ;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     SOLVE();
//     return 0;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while(t--){
//         SOLVE();
//     }
//     return 0;
// }

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