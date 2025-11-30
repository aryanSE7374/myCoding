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

    ll n;
    cin>>n;

    ll N = 2LL*n;
    vll a(N);

    unordered_map<ll , ll> freq;

    f(i,0,N){
        cin >> a[i];
        freq[a[i]]++;
    }


    ll p = 0 , q = 0;

    ll fp = 0 , fq = 0;

    ll evcount = 0;

    for(auto &[num,currfreq] : freq){
        // ll currfq = it.second;
        
        if(currfreq%2 == 0){ // even

            if(p == n){
                q += currfreq;
                continue;
            }
            else if(q == n){
                p += currfreq;
                continue;
            }

            int k=1;
            while(  k<=currfreq &&  !( (p+k <= n) && (q+currfreq-k <= n) ) ){
                k+=2;
            }

            if(p+k <= n && q+currfreq-k <= n){
                p += k;
                q += (currfreq-k);
                fp++;
                fq++;
            }
            else{
                evcount += currfreq;
                p += (currfreq/2);
                q += (currfreq/2);
                // if( p+2 <= n && q+currfreq-2 <= n){
                //     p+=2;
                //     q+=(currfreq-2);
                // }
            }
                
        }

        else{ // odd

            if(p+currfreq > n){
                q += currfreq;
                fq++;
            }
            else if(q + currfreq > n){
                p += currfreq;
                fp++;
            }
            else{
                p += currfreq;
                fp++;
            }

        }


    }

    cout << (fp + fq);

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