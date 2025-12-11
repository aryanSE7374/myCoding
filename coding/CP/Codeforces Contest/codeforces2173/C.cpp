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

    f(i,0,n){
        cin >> a[i];
    }

    sort(a.begin() , a.end());


    // bool flag = true;
    // f(i,0,n-1){
    //     if(a[i] != a[i+1]){
    //         flag = false;
    //         break;
    //     }
    // }

    // if(flag){
    //     cout << "1" << "\n" << "1" << "\n";
    //     return;
    // } 


    // vi spf(k+1 , 0);

    // for(int i = 2; i <= k; i++){
    //     if(spf[i] == 0){
    //         spf[i] = i;
    //         if( (ll)i * i <= k){
    //             for( ll j = 1LL * i * i; j <= k; j += i){
    //                 if(spf[j] == 0) spf[j] = i;
    //             }
    //         }
    //     }
    // }

    // unordered_set<int> B;

    // unordered_map<int , int> A;
    // f(i,0,n){
    //     A[a[i]]++;
    // }

    // f(i,0,n){
    //     B.insert(spf[i]);
    // }

    // for(int it : B){
    //     int x = it;
    //     while(x <= k){
    //         if(A.find(x) == A.end()){
    //             cout << -1 <<"\n";
    //             return;
    //         }
    //         x += it;
    //     }
    // }

    // cout << B.size() << "\n";

    // for(int x : B){
    //     cout << x << " ";
    // }


    map<ll, ll> idx;
    
    f(i,0,n){
        idx[a[i]] = i;
    }

    vector<bool> A(n , false); // a[i] -> included in set B 
    vll B;

    f(i, 0, n){
        if(A[i]) continue;

        ll x = a[i];
        
        if(k/x > n){
            cout << -1;
            co_endl;
            return;
        }

        for(ll j = x ; j <= k ; j += x){

            if(idx.find(j) == idx.end()){

                cout << -1;
                co_endl;
                return;

            }
            
            A[idx[j]] = true;
        }
        
        B.push_back(x);
        
    }

    cout << B.size() << "\n";

    for(int x : B){
        cout << x << " ";
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