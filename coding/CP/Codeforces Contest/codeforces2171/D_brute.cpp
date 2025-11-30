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

    vi a(n); // permutation

    f(i,0,n){
        cin >> a[i];
    } 

    // logic here

    vi idx(n+1);

    f(i,0,n){
        idx[a[i]] = i;
    }

    bool ans = true;

    int mini = idx[1];

    f(k,2,n+1){
        if(mini > idx[k]){
            ans = false;
            break;
        }
        mini = min(mini , idx[k]);
    }



    // bool ans;

    if(ans) cout<<"YES";
    else cout<<"NO";

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