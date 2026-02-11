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


    int n , s , x ;
    cin >> n >> s >> x ;

    vi a(n);
    int sum = 0;
    f(i,0,n) {
        cin >> a[i];
        sum += a[i];
    }

    int k = (s-sum);

    if ( k>=0 && k%x == 0 ) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    co_endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){

        SOLVE();

    }

    return 0;
}