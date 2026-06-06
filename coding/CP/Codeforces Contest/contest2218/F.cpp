/*
code by - Aryan Shrivastav
*/

/*
observations : 

root has (x+y) subtrees

if ( ((x+y) % 2) == 0 && (x==0) ) return false;
else if ( ((x+y) % 2) == 1 && (y==0) ) return false;

if ( ((x+y) % 2) == 0 ) x--;
else y--;


add odd nodes to the root first
then check even nodes

if ( x > y ) return false;

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

    int x, y;
    cin >> x >> y;

    if ( ((x+y) % 2) == 0 && (x==0) ) {
        // cout << "x: " << x << " , y: " << y << endl;
        cout << "NO\n";
        // cout << "here... 1\n";
        return;
    }

    if ( ((x+y) % 2) == 1 && (y==0) ) {
        // cout << "x: " << x << " , y: " << y << endl;
        cout << "NO\n";
        // cout << "here... 2\n";
        return;
    }

    if ( ((x+y) % 2) == 0 ) {
        x--;
    }
    else {
        y--;
    }

    if ( x > y ) {
        // cout << "x: " << x << " , y: " << y << endl;
        cout << "NO\n";
        // cout << "here... 3\n";
        return;
    }

    int u = 1;
    vector<pair<int, int>> edges;

    for ( int v=0; v<y; v++ ) {
        edges.push_back({1,v+2});
    }

    for ( int v=0; v<x; v++ ) {
        edges.push_back({v+2, y+2+v});
    }

    cout << "YES\n";

    for ( auto& e : edges ) {
        cout << e.first << " " << e.second << "\n";
    }

    // cout<<'\n';
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