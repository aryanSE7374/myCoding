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

    string s;
    cin>>s;

    int ans = 0;

    int j = INT_MIN;

    f(i,0,n){
        if ( s[i] == '1' ){
            j = max(j , i+k);
        }
        else{
            if(i > j){
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return;

    // int j = INT_MIN; 

    // f(i,0,n){
    //     if(i <= j){
    //         if (s[j] == '1') j = max(j , i+k);
    //     }
    //     else {
    //         if(s[i] == '1'){
    //             j = i+k;
    //         }
    //         else ans++;
    //     }
    // }

    // f(i,0,n){
    //     if(s[i] == '0') ans++;
    //     else{
    //         i = i+k;
    //     }
    // }

    // f(i,0,n){
    //     if(s[i] == '0') ans++;
    //     else{
    //         for(int j=i+k ; j>i ; j--){
    //             if (s[j] == '1') i = j+k;
    //             else i = i+k;
    //         }
    //     }
    // }

    // f(i,0,n){
    //     if(s[i] == '0') ans++;
    //     else{
    //         int i2 = i+k;
    //         int j = i+1;
    //         while(j<n && j <= i2){
    //             if (s[j] == '1') i2 = max(i2 , j+k);
    //             j++;
    //         }
    //         i = i2-1;
    //         // for(int j=i+1 ; j<n && j<=i2  ; j++){
    //         //     // if (s[j] == '1') i = j+k;
    //         //     if (s[j] == '1') i2 = max(i2 , j+k);
    //         //     // else i = i+k;
    //         // }
    //         // i = i2-1;
    //     }
    // }

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