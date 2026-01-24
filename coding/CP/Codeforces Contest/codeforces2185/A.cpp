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
#define nl cout << '\n'
#define f(i,a,n) for(int i=a ; i<n ; i++)


vector<int> a(21);


void SOLVE(){

    int n ;

    cin >> n ;

    f(i,0,n){
        cout << a[i] << " ";
    }

    nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    f(i,0,21){
        a[i] = ( (i+1) * (i+1) );
    }
    
    while(t--){

        SOLVE();

    }

    return 0;
}