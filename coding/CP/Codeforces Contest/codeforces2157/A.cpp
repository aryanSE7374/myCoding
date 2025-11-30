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

    vi vec(n);

    unordered_map<int , int> freq;
    f(i,0,n){
        cin >> vec[i];
        freq[vec[i]]++;
    }

    int ans = 0;

    for(int i = 0 ; i <= n ; i++ ){

        if(freq[i] > i){
            ans += (freq[i] - i);
        }
        else if(freq[i] < i){
            ans += freq[i];
        }

    }


    cout<<ans;

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