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

    vll odds , evens;

    f(i,0,n){
        if(a[i] % 2 == 1) odds.push_back(a[i]);
        else evens.push_back(a[i]);
    }

    // sort(a.rbegin() , a.rend()) ;

    sort(odds.rbegin() , odds.rend());
    sort(evens.rbegin() , evens.rend());

    int e_cnt = evens.size();
    int o_cnt = odds.size();

    // vll pref_ev(n+1 , 0); 
    vll pref_odd(n+1 , 0);
    vll pref_ev( e_cnt+1 , 0);

    f(i,0,e_cnt){
        pref_ev[i+1] = pref_ev[i] + evens[i];
    }

    f(k,1,n+1){

        if(o_cnt == 0){
            ans[k-1] = 0;
            continue;
        }

        int ev = min(k-1 , e_cnt);
        int od  = k - ev;

        if(od%2 == 0){
            ev--; od++;
        }

        if(ev < 0 || od > o_cnt){
            ans[k-1] = 0;
        }
        else{
            ans[k-1] = pref_ev[ev] + odds[0] ;
        }
    }

    // vll maxOdd(n+1 , -1);
    // ll currMax = -1;

    // f(i,1,n+1){

    //     pref_ev[i] = pref_ev[i-1];
    //     pref_odd[i] = pref_odd[i-1];

    //     if( (a[i-1]%2) == 0){
    //         pref_ev[i] += a[i-1];
    //     }
    //     else{
    //         pref_odd[i] += a[i-1];
    //         if(currMax == -1) currMax = a[i-1];
    //     }

    //     maxOdd[i] = currMax;

    // }

    // f(k,1,n+1){

    //     if( maxOdd[k] == -1 ){  
    //         ans[k-1] = 0;
    //         continue;
    //     }

    //     ans[k-1] = pref_ev[k] + maxOdd[k];
    // }

    f(i,0,n){
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