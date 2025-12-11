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
    vi b(n);

    string ans;

    int total_a = 0;
    int total_b = 0;

    f(i,0,n){
        cin>>a[i];
        total_a^=a[i];
    }

    f(i,0,n){
        cin>>b[i];
        total_b^=b[i];
    }

    f(i,0,n){
        if(i%2 == 0){ // ajisai turn

            if( (total_a ^ a[i] ^ b[i]) > (total_b ^ b[i] ^ a[i]) ){

                total_a = (total_a ^ a[i] ^ b[i]);
                total_b = (total_b ^ b[i] ^ a[i]);

                // swap
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;

            }

        }
        else{ // mai turn
            if( (total_a ^ a[i] ^ b[i]) < (total_b ^ b[i] ^ a[i]) ){

                total_a = (total_a ^ a[i] ^ b[i]);
                total_b = (total_b ^ b[i] ^ a[i]);

                // swap
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;

            }
        }
    }


    int ans_a = total_a;
    int ans_b = total_b;

    if(ans_a > ans_b){
        ans = "Ajisai";
    }
    else if(ans_a < ans_b){
        ans = "Mai";
    }
    else{
        ans = "Tie";
    }

    cout<<ans;

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