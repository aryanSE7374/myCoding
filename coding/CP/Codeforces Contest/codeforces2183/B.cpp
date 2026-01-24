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

    int n , k;
    cin >> n >> k ;

    vi a(n);
    vi b(n);
    f(i,0,n){
        cin >> a[i];
    }

    b = a;

    sort(a.begin() , a.end());

    int mex = 0;
    f(i,0,n){
        if(a[i] == mex){
            mex++;
        }
    }

    cout << min ( mex , k-1 );

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