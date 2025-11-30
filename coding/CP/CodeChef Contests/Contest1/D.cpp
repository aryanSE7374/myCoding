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

    vi A(n);
    vi B(n);

    f(i,0,n){
        cin >> A[i];
    }

    f(i,0,n){
        cin >> B[i];
    }

    // A[n-1] = B[n-1];

    bool ans = true;

    // for(int i=n-1 ; i>=0 ; i--){


    //     if(A[i] > B[i]){ // dec

    //         if ( B[i] <= A[i+1] && A[i+1] <= A[i] ){
    //             ans = false;
    //             break;
    //         }

    //         else{
    //             A[i] = B[i];
    //         }

    //     }

    //     else if(A[i] < B[i]){ // inc

    //         if ( A[i] <= A[i+1] && A[i+1] <= B[i] ){
    //             ans = false;
    //             break;
    //         }

    //         else{
    //             A[i] = B[i];
    //         }

    //     }
    // }

    f(i,0,n-1){


        if ( (A[i] < A[i+1]) && B[i] >= B[i+1] ){
            ans = false;
            break;
        }
        else if ( (A[i] > A[i+1]) && B[i] < B[i+1] ){
            ans = false;
            break;
        }

    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";

    // co_endl;
    
}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        SOLVE();

    }

    return 0;
}