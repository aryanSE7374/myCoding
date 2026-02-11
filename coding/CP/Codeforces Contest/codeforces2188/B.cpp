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


    // if both side 1

    // sz of block  =   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
    // min addition =   0   0   0   1   1   1   2   2   2   3   3   3   4   4   4   5

    int n;
    cin >> n;
    string s;
    
    cin >> s;

    // vector<int> st =  { 0 , 0  , 0  , 1 , 1 , 2  , 2  , 2  , 2 , 3 , 3  , 3  , 4 , 4  , 4 , 5 };
    vector<int> st =  { 0 , 0  , 0  , 1 , 1 , 1  , 2  , 2  , 2 , 3 , 3  , 3  , 4 , 4  , 4 , 5 };
    // vector<int> st2 = { 0 , 1  , 1  , 2 , 1 , 2  , 2  , 2  , 2 , 3 , 3  , 3  , 4 , 4  , 4 , 5 };

    // int j=-1;
    // int ans = 0;

    // f(i,0,n) {
    //     if ( s[i] == '1' ) ans++;
    // }

    // if ( ans == 0 ) {
    //     // if ( n < 16 ) {
    //     //     ans += st2[n];
    //     //     // ans += 2;
    //     // }
    //     // else{
    //     //     ans += (n/3) ;
    //     //     // ans += 2;
    //     // }

    //     if ( n < 3 ) {
    //         cout << 1 << "\n";
    //         return;
    //     }

    //     int sz=n-2;
    //     ans++; // at 2nd pos
    //     if ( sz < 16 ) {
    //         if ( sz == 2 ) {
    //             ans += 1;
    //         }
    //         else {
    //             ans += st[sz];
    //         }
    //     }
    //     else{
    //         ans += (sz/3) ;
    //     }

    //     cout << ans << endl;
    //     return;

    // }

    // f(i,0,n){
    //     if ( s[i] == '1' ) {
    //         // ans++;
    //         int sz = i-j-1;
    //         if ( sz < 16 ) {
    //             ans += st[sz];
    //         }
    //         else{
    //             ans += (sz/3) ;
    //         }
    //         j=i;
    //     }
    //     if ( i==n-1 && s[i]=='0' ) {
    //         int sz = n-j-1;
    //         // if ( sz<=4 ) ans += 1;
    //         if ( sz < 16 ) {
    //             if ( sz == 2 ) {
    //                 ans += 1;
    //             }
    //             else {
    //                 ans += st[sz];
    //             }
    //         }
    //         else{
    //             ans += (sz/3) ;
    //         }
    //     }
    // }

    // if ( j == -1 ) {

    //     int sz = n;

    //     if ( n <= 4 ) ans = 1;
    //     else if ( sz < 16 ) {
    //         ans += st[sz];
    //         // ans += 2;
    //     }
    //     else{
    //         ans += (sz/3) ;
    //         // ans += 2;
    //     }
    // }

    //


    // CHANGE 1: Removed 'st' vector. Using formulas instead.
    // Middle Gap Formula: sz / 3
    // Edge Gap Formula:   sz / 3 + (sz % 3 == 2 ? 1 : 0)

    int j = -1;
    int ans = 0;

    int cnt = 0;
    f(i,0,n) {
        if ( s[i] == '1' ) cnt++;
    }

    if ( cnt == 0 ) {
        
        if ( n < 3 ) {
            cout << 1 << "\n";
            return;
        }

        int sz=n+2;
        // ans++; // at 2nd pos
        if ( sz < 16 ) {
            // if ( sz == 2 ) {
            //     ans += 1;
            // }
            // else {
            //     ans += st[sz];
            // }
            ans = st[sz];
        }
        else{
            ans = (sz/3) ;
        }

        cout << ans << endl;
        return;

    }

    f(i,0,n){
        
        if ( s[i] == '1' ) {
            // ans++;
            int sz = i-j-1;
            
            // j=i;

            if ( j == -1 ) {

                if ( sz < 16 ) {
                    ans += st[sz];
                }
                else{
                    ans += (sz/3) ;
                }

                if ( sz % 3 == 2 ) ans++;

            } 
            else {
                ans += (sz/3) ;
            }

            j = i;
        }
        // if ( i==n-1 && s[i]=='0' ) {
        //     int sz = n-j-1;
        //     // if ( sz<=4 ) ans += 1;
        //     if ( sz < 16 ) {
        //         if ( sz == 2 ) {
        //             ans += 1;
        //         }
        //         else {
        //             ans += st[sz];
        //         }
        //     }
        //     else{
        //         ans += (sz/3) ;
        //     }
        // }

    }

    // last block
    int sz = n-1-j;
    ans += (sz/3) ;
    if ( sz%3 == 2 ) ans++;

    cout << ans + cnt;

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}