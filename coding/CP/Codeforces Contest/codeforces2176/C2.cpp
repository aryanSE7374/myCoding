/*
code by - Aryan Shrivastav
*/

/*
observations :

if odd count == 0 return ans(n,0);

reverse sort
Create:
    prefix sum - evens
    prefix sum - odds
    curr max odd[k]

for k {1,n}:
    ans = (pref_ev[k]) + currmax_odd[k];


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

    vll a(n);
    f(i,0,n){
        cin >> a[i] ;
    }

    vll ans(n,0);

    bool flag = false;
    f(i,0,n){
        if(a[i]%2 == 1){
            flag = true;
            break;
        }
    }

    if(flag == false){
        f(i,0,n){
            cout << ans[i] << " ";
        }
        co_endl;
        return;
    }

    sort(a.rbegin() , a.rend()) ;

    vll pref_ev(n+1 , 0); 
    vll pref_odd(n+1 , 0);
    ll max_odd = -1;

    f(i,1,n+1){
        pref_ev[i] = pref_ev[i-1];
        pref_odd[i] = pref_odd[i-1];

        if(a[i-1] % 2 == 0){
            pref_ev[i] += a[i-1];
        }
        else {
            pref_odd[i] += a[i-1];
            if(max_odd == -1) max_odd = a[i-1];
        }
    }

    f(k,1,n+1){

        if(pref_odd[k] == 0){  
            ans[k-1] = 0;
            continue;
        }

        ans[k-1] = pref_ev[k] + max_odd;

    }

    f(i,0,n){
        cout << ans[i] << " ";
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