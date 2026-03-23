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
    int p, q;
    cin >> p ;
    unordered_set<int> ps;
    f(i,0,p) {
        int num;
        cin >> num;
        ps.insert(num);
    }
    cin >> q;
    f(i,0,q){
        int num;
        cin >> num;
        ps.insert(num);
    }

    if ( ps.size() == n ) {
        cout << "I become the guy.";
    }
    else {
        cout << "Oh, my keyboard!";
    }


    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        SOLVE();
    }
    return 0;
}