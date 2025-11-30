/*
code by - Aryan Shrivastav
*/

/*
observations : 
  int diff = vec[n-1] - vec[0] ;
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

    vi vec(n);
    vi ans(n);
    
    f(i,0,n){
        cin>>vec[i];
    }
    
    ans = vec;

    if(ans[n-1] == -1 && ans[0] == -1){
        // cout<<0<<"\n";
        // f(i,0,n){
        //     if(vec[i]==-1){
        //         cout << "0 ";
        //     }
        //     else{
        //         cout << vec[i] << " ";
        //     }
        // }
        // co_endl;
        // return;
        ans[0] = ans[n-1] = 0;
    }

    else if( ans[0] == -1 ){
        ans[0] = ans[n-1];
    }
    else if( ans[n-1] == -1 ){
        ans[n-1] = ans[0];
    }

    cout<<abs(ans[n-1] - ans[0])<<"\n";

    f(i,0,n){
        if(ans[i]==-1){
            cout << "0 ";
        }
        else{
            cout << ans[i] << " ";
        }
        // cout << ans[i] << " ";
    }

    co_endl;

    // else{

    //     if(vec[n-1] == -1 && vec[0] == -1){
    //         ans[0] = 0;
    //         ans[n-1] = 0;
    //         cout<<0<<"\n";
    //         f(i,0,n){
    //             if(vec[i]==-1){
    //                 cout << "0 ";
    //             }
    //             else{
    //                 cout << ans[i] << " ";
    //             }
    //             // cout << ans[i] << " ";
    //         }
    //         co_endl;
    //         return;
    //     }

    //     else if(vec[n-1] == -1 ){
    //         ans[n-1] = ans[0];
    //     }
    //     else if(vec[0] == -1){
    //         ans[0] = ans[n-1];
    //     }

    //     // int diff = vec[n-1] - vec[0] ;

    // }

    // cout<<abs(ans[n-1] - ans[0])<<"\n";
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}