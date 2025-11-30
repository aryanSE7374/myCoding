#include <bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(){

    ll a , b , n;
    cin >> a >> b >> n;

    // ll d = 1LL*a/b*1LL ;
    ll d = a/b ;
    if(a <= b) cout << 1;
    else if(n <= d) cout << 1;
    else{
        cout << 2;
    }

    // else{
    //     // cout << "\n------ : " << max(1LL , (n-d+1)) ;
    //     cout << max(1LL , (n-d+1)) ;

    // }


    cout << "\n";

}



int main(){

    int t;
    cin>>t;
    while(t-->0){
        SOLVE();
    }

    return 0;

}