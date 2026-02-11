/*
code by - Aryan Shrivastav
*/

/*
observations : minimax -> mani blocks one side, hamid escapes the other
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

    int n , x;
    cin >> n >> x;
    string S;
    cin >> S;

    x--;   // 0-index

    int L = -1 , R = n;

    // nearest wall on left
    for ( int i=x-1 ; i>=0 ; i-- ) {
        if ( S[i] == '#' ) {
            L=i;
            break;
        }
    }

    // nearest wall on right
    for ( int i=x+1 ; i<n ; i++ ) {
        if ( S[i] == '#' ) {
            R=i;
            break;
        }
    }

    auto calc = [&](int leftWall , int rightWall){

        if (leftWall == -1 || rightWall == n)
            return 1LL;

        int leftDist  = leftWall + 2;     // distance to left border
        int rightDist = n - rightWall + 1; // distance to right border

        return (ll)min(leftDist , rightDist);
    };

    ll ans = 0;

    // Mani blocks left
    ans = max(ans , calc(x-1 , R));

    // Mani blocks right
    ans = max(ans , calc(L , x+1));

    cout<<ans<<'\n';
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

// void SOLVE(){

//     int n , x;
//     cin >> n >> x;
//     string S;
//     cin >> S;

//     x--;


//     // finding nearest wall
//     int l = -1 , r = n;

//     for ( int i=x-1 ; i>=0 ; i-- ) {
//         if ( S[i] == '#' ) {
//             l=i;
//             break;
//         }
//     }

//     for ( int i=x+1 ; i<n ; i++ ) {
//         if ( S[i] == '#' ) {
//             r=i;
//             break;
//         }
//     }

//     // check for no wall edge case
//     if ( l < 0 && r >= n ) {
//         cout << 1 << "\n";
//         return;
//     }

//     // mani's play

//     if ( l<0 ) {
//         S[x-1] = '#';
//         l = x-1;
//     }
//     else if ( r>=n ) {
//         S[x+1] = '#';
//         r = x+1;
//     }
//     else {

//         int left = l+1 , right = n-r;

//         if ( left < right ) {
//             for ( int i=x-1 ; i>=0 ; i-- ) {
//                 if ( S[i] == '.' ) {
//                     S[i] = '#';
//                     l=i;
//                     break;
//                 }
//             }
//         }

//         else if ( right < left ) {
//             for ( int i=x+1 ; i<n ; i++ ) {
//                 if ( S[i] == '.' ) {
//                     S[i] = '#';
//                     r=i;
//                     break;
//                 }
//             }
//         }

//     } 


//     // hamid's play

//     if ( l<0 || r>=n ) {
//         cout << 1;
//     }
//     else {
//         int left = l+1 , right = n-r;
    
//         if ( left < right ) {
//             cout << left+1 ;
//         }
//         else {
//             cout << right+1;
//         }
//     }


//     cout<<'\n';
// }

// void SOLVE(){

//     int n , x;
//     cin >> n >> x;
//     string S;
//     cin >> S;


//     // finding nearest wall
//     int l = -1 , r = n;

//     for ( int i=x-1 ; i>=0 ; i-- ) {
//         if ( S[i] == '#' ) {
//             l=i;
//             break;
//         }
//     }

//     for ( int i=x+1 ; i<n ; i++ ) {
//         if ( S[i] == '#' ) {
//             r=i;
//             break;
//         }
//     }

//     // check for no wall edge case
//     if ( l < 0 && r >= n ) {
//         cout << 1 << "\n";
//         return;
//     }

//     // mani's play

//     if ( l<0 ) {
//         S[x-1] = '#';
//         l = x-1;
//     }
//     else if ( r>n ) {
//         S[x+1] = '#';
//         r = x+1;
//     }
//     else {

//         int left = l+1 , right = n-r;

//         if ( left < right ) {
//             for ( int i=x-1 ; i>=0 ; i-- ) {
//                 if ( S[i] == '.' ) {
//                     S[i] = '#';
//                     l=i;
//                     break;
//                 }
//             }
//         }

//         else if ( right > left ) {
//             for ( int i=x+1 ; i<n ; i++ ) {
//                 if ( S[i] == '.' ) {
//                     S[i] = '#';
//                     r=i;
//                     break;
//                 }
//             }
//         }

//     } 


//     // hamid's play

//     if ( l<0 || r>=n ) {
//         cout << 1;
//     }
//     else {
//         int left = l+1 , right = n-r;
    
//         if ( left < right ) {
//             cout << left+1 ;
//         }
//         else {
//             cout << right+1;
//         }
//     }


//     cout<<'\n';
// }

// ------------------------------------------ //

// //  DEBUG MACRO
// #define debug(x) cerr << #x << " = " << x << '\n';