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

    vll vec(n);

    ll sum = 0;
    ll size = 0; // no. of non zeroes

    f(i,0,n){
        cin >> vec[i];
        if(vec[i]>0){size++;}
        sum += vec[i];
    }

    ll kmax = sum - n + 1; 

    ll ans = min(kmax , size);

    cout << ans;
    
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