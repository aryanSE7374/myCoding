#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define f(i,a,b) for(int i=a;i<b;i++)


int power(int bs,int exp,int mod) {
    int res = 1;
    bs %= mod;
    while (exp>0) {
        if(exp%2==1)res=(res*bs)%mod;
        bs=(bs*bs)%mod;
        exp/=2;
    }
    return res;
}
 
 
void SOLVE_BLOCK(){
    int n,k;cin>>n>>k;
    vi arr(n);f(i,0,n) cin>>arr[i];
    //
    int p=2;
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    f(i,0,primes.size()){
        if (k%primes[i]!=0) {
            p=primes[i];
            break;
        }
    }
    //
    int ki=power(k,p-2,p);
    f(i,0,n){
        int ni=(p-(arr[i]%p))%p;
        int ga=(ni*ki)%p;
        int pt=arr[i]+ga*k;
        cout<<pt<<" ";
    }
    cout<<endl;
    
}