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

    int n ;
    cin >> n;

    vi a(n);

    unordered_map<int,int> mpp;

    bool ans = true;

    int bit = 0; // R

    f(i,0,n) {
        cin >> a[i];
        mpp[a[i]] = bit;
        bit = !bit ;
    }

    if (n==1) {
        cout <<"YES\n";
        return;
    }

    int curr = mpp[1];

    f(i,2,n+1){
        if ( mpp[i] == curr ) {
            ans = false;
            break;
        }
        curr = mpp[i] ;
    }

    if (ans) {
        cout << "YES";
    }
    else {cout << "NO";}

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