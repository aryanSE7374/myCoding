/*
code by - Aryan Shrivastav
*/

/*
observations : 
Prefix AND keeps bits alive as long as possible.
Odd numbers preserve LSB, evens kill it.
Build layer by layer.
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

    // base case for n = 1
    vll ans;
    ans.push_back(1);
    ans.push_back(0);

    // build for k = 2 ... n
    f(k,2,n+1){

        vll ans1;

        // left half : odd numbers (2*x + 1)
        for(auto x : ans){
            ans1.push_back( (x<<1) | 1 );
        }

        // right half : all evens in increasing order
        f(i,0,(1<<(k-1))){
            ans1.push_back( i<<1 );
        }

        ans = ans1;
    }

    f(i,0,ans.size()){
        cout << ans[i] << " ";
    }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t-->0){
        SOLVE();
    }

    return 0;
}