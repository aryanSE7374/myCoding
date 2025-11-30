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

#define of(i,a,b) for(int i=a ; i>=b ; i--)

void SOLVE(){


int n,k; cin>>n>>k;
    vi arr(n);
    f(i,0,n) cin>>arr[i];
    vi brr(n); f(i,0,n) cin>>brr[i];
    if((k&1)==0){
        int maxx=INT_MIN;
        int count=INT_MIN;
        f(i,0,n){
            if(count<0){
                count=arr[i];
            }
            else count+=arr[i];
            maxx=max(maxx,count);
        }
        // maxx=max(maxx,count);
        cout<<maxx<<endl;
        return;
    }
    vi pre(n,arr[0]);
    f(i,1,n){
        pre[i]=max(arr[i],arr[i]+pre[i-1]);
    }
    vi suf(n,arr[n-1]);
    of(i,n-2,0){
        suf[i]=max(arr[i],arr[i]+suf[i+1]);
    }
    int ans=INT_MIN;
    f(i,0,n){
        ans=max(ans,pre[i]+suf[i]-arr[i]+brr[i]);
    }
    cout<<ans<<endl;
    return;



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

