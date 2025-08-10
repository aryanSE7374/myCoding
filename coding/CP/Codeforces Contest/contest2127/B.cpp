// Problem: Hamiiid, Haaamid... Hamid?
// Contest Platform: Codeforces
// Author: Aryan Shrivastav (Boilerplate Only)
// Compiler: GNU G++ 20
// Time Limit: 1 second
// Memory Limit: 256 MB

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// function to solve
int findMinDays(string& s , int n , int x ){
    // implementation
    x = x-1; // 0 based indexing

    // find nearest walls
    int ldist = INT_MIN;
    int rdist = INT_MIN;

    // traversing left from x-1 to 0
    for(int i=x-1 ; i>=0 ; i--){
        if(s[i]=='#'){
            ldist = x-i;
            break;
        }
    }

    // Traversing right from x+1 to n-1
    for(int i=x+1 ; i<=n-1 ; i++){
        if(s[i]=='#'){
            rdist = i-x;
            break;
        }
    }

    if(ldist==INT_MIN || rdist==INT_MIN){return 1;}

    // decide direction based on closer wall
    bool moveLeft = (ldist <= rdist);

    int count = 0;
    if(moveLeft){
        for(int i = x - 1 ; i >= 0 ; i--){
            if(s[i] == '.') count++;
        }
    } else {
        for(int i = x + 1 ; i < n ; i++){
            if(s[i] == '.') count++;
        }
    }

    // Hamid needs to move through all empty cells in chosen direction and amni will block 1 empty cell
    // so total days = count + 1
    return count + 1;

}


// Function to process each test case
void solve() {
    int n, x;
    cin >> n >> x;

    string s;
    cin >> s;

    // Placeholder output
    cout << findMinDays(s,n,x) << endl;
}

int32_t main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


/*

int findMinDays(string& s , int n , int x ){
    x = x-1; // 0-based indexing

    int left_empty = 0;
    for(int i = x - 1 ; i >= 0 ; i--){
        if(s[i] == '.') left_empty++;
    }

    int right_empty = 0;
    for(int i = x + 1 ; i < n ; i++){
        if(s[i] == '.') right_empty++;
    }

    // If any side has no walls (i.e., it's all empty), Hamid escapes in 1 day
    if(left_empty == 0 || right_empty == 0) return 1;

    // Else, go towards the side with fewer empty cells
    return min(left_empty, right_empty) + 1;
}
*/