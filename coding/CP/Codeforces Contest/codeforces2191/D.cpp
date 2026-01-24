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

    int n;
    cin >> n;

    string S;
    cin >> S;

    int idx = -1;

    f(i,0,n){
        if(S[i] == ')'){
            idx = i+1;
            break;
        }
    }

    if ( idx >= n/2 ) {
        cout << -1;
    }
    else {
        cout << n-2;
    }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}