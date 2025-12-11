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

    int n,c;

    cin >> n >> c;

    vi A(n);
    string S;

    f(i,0,n){
        cin >> A[i];
    }

    cin >> S;

    int S0 = 0;
    int S1 = 0;

    // int min1 = INT_MAX;

    f(i,0,n){
        if(S[i] == '0') S0 += A[i];
        else{
            // min1 = min(min1 , A[i]);
            S1 += A[i];

        }
    }


    // if()

    // int ans = max ( S0 , max(S1-c , S0 + S1 - c) );
    // cout << ans;

    int ans = S0;

    if ( S0 < c ) {
        cout << S0;
    }
    else if ( S1-c > 0 ){
        cout << ( S0 + S1 - c );
    }
    else cout << S0;

    // if ( (S0 < c) || (S1 <= c) ) cout << max(S0 , S0+S1-c);
    // else cout << (S0 + S1 - c);


    co_endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}