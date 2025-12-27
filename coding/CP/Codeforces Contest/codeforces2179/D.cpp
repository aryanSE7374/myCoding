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

    cin>>n;

    /*
    
    ll maxi = 0LL; // maxi value
    maxi = maxi + n + (n-1) ;

    ll d = 2;

    for(int i = n ; i>=1 ; i--){
        maxi += (d * i);
        d*=2LL;
    }

    */


    vll ans = {1,0};
    // unordered_set<ll> st;

    if ( n==1 ){
        cout << 1 << " " << 0 << endl;
        return;
    }

    f(i,2,n+1){
        vll ans1;
        // 2*x + 1
        for(int j=0 ; j<ans.size() ; j++){
            int d = ans[j]<<1;
            ans1.push_back( d | 1 );
        }


        int d1 = 1<<(i-1);
        f(j,0,d1){
            int d2 = j<<1;
            ans1.push_back( d2 );
        }

        ans = ans1;
    }

    // ll num = 1LL*(1<<n) - 1 ; // 2^n - 1

    // int d = n;

    // while(d>0){

    //     ans.push_back(num);
    //     st.erase(num);

    //     int i=0;

    //     int d1 = d;
    //     int num1 = num;
    //     while (d+i < n-i){
    //         d1 = d+i+1;
    //         num1 ^= (1<<d1);
    //         ans.push_back(num1);
    //         st.erase(num1);

    //         d1++;
    //         i++;

    //     }
        

    //     d--;
    //     num ^= (1<<d);

    // }


    f(i,0,ans.size()){
        cout << ans[i] << " " ;
    }

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