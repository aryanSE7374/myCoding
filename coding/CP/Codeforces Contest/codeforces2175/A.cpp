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

    cin >> n;

    vi a(n);
    unordered_map<int,int> freq;

    f(i,0,n){
        cin >> a[i];
        freq[a[i]]++;
    }

    int dist = freq.size();

    sort(a.begin() , a.end());

    int ans = dist;

    f(i,0,n){
        if(a[i]>=dist){
            ans = a[i];
            break;
        }
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