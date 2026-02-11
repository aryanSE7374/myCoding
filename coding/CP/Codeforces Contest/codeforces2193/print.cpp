/*
code by - Aryan Shrivastav
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define co_endl cout<<'\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)

// ---------- INTERACTIVE UTILITIES ----------

// print and flush (for queries)
void ask(ll x) {
    cout << x << '\n';
    cout.flush();
}

// print final answer and terminate
void answer(ll x) {
    cout << "! " << x << '\n';
    cout.flush();
    exit(0);
}

// read response safely
string get_response() {
    string s;
    cin >> s;
    return s;
}

// ---------- SOLUTION ----------

void SOLVE() {

    // code here - example of interactive problems

    ll l = 1, r = 1000000;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        ask(mid);               // query
        string res = get_response();
        if (res == "<") r = mid - 1;
        else l = mid;
    }
    answer(l);                  // final guess
}

// ---------- MAIN ----------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // NOTE:
    // Interactive problems are usually SINGLE TEST CASE.
    // Only add multiple testcases if problem explicitly says so.

    SOLVE();

    return 0;
}