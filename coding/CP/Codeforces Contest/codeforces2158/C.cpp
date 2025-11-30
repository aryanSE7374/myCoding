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

    int n,k;
    cin>>n>>k;

    vll a(n);
    vll b(n);

    f(i,0,n){
        cin>>a[i];
    }
    f(i,0,n){
        cin>>b[i];
    }

    ll sum=LLONG_MIN;
    ll curr = 0;

    // ll ans = 0;

    // kadanes

    f(i,0,n){
        curr = max(a[i] , curr + a[i]);
        sum = max(sum , curr);
    }

    if(k%2 == 0){
        cout << sum << "\n";;
        return;
    }

    // else{
        
    //     f(i,0,n){
    //         ans = max(ans , b[i]);
    //     }
    //     ans = ans + sum;
    // }

    ll ans = sum;

    f(i,0,n){
        ll prev = a[i];
        a[i] = a[i] + b[i];

        ll currAns = LLONG_MIN; 
        ll currSum = 0;

        f(j,0,n){
            currSum = max(a[j] , currSum + a[j]);
            currAns = max(currAns , currSum);
        }

        ans = max(ans, currAns);

        a[i] = prev;

    }

    cout << ans ;

    // cout << ans;

    // return sum;

    // f(i,0,k){
    //     if()
    // }



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