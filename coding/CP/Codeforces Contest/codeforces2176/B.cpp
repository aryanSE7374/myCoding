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

    string s;
    cin >> s;

    vi maxi(n,0);

    int frst = n-1;
    f(i,0,n){
        if(s[i] == '1') {
            frst = i;
            break;
        }
    }


    int curr = frst+1;

    for(int i = n-1 ; i>=0 ; i--){
        if(s[i] == '0'){
            maxi[i] = curr;
            curr++;
        }
        else{
            curr = 1;
        }
    }


    int ans = 0;
    f(i,0,n){
        ans = max(ans , maxi[i]);
    }

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