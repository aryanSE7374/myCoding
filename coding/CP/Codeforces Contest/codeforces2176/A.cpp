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

    vi a(n);
    f(i,0,n){
        cin >> a[i];
    }

    int ans = 0;

    while(true){
        bool flag = false;
        for(int i=0 ; i<a.size() ; i++){
            for(int j=i+1 ; j<a.size() ; j++){
                if(a[i]>a[j]){
                    a.erase(a.begin() + j);
                    ans ++;
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false) break;
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