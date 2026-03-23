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

    int r, g, b;

    cin >> r >> g >> b;

    int n = r+g+b;

    string s(n, '$');

    int i=0;

    while( i<n && r>0 ) {
        if (
            s[i] =='$' &&
            ( i>1 && s[i-1] != 'R' ) &&
            ( i>3 && s[i-3] != 'R' ) &&
            ( i<n-1 && s[i+1] != 'R' ) &&
            ( i<n-3 && s[i+3] != 'R' ) 

        ) {
            s[i] = 'R';
            r--;
        }
        i++;
    }

    cout << s;

    cout<<'\n';
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