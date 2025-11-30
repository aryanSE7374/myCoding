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
        total_a+=a[i];
    }

    f(i,0,n){
        cin>>b[i];
        total_b+=b[i];
    }

    f(i,0,n){
        if(i%2 == 0){ // ajisai turn
            if(total_a%2 == 0){ // total_a is even 
                if(a[i]==0 && b[i]==1){ // swap
                    a[i] = 1;
                    b[i] = 0;
                    total_a++;
                    total_b--;
                }
                else if(a[i]==1 && b[i]==0){
                    a[i] = 0;
                    b[i] = 1;
                    total_a--;
                    total_b++;
                }
            }
            else{ // total_a is odd // dont swap
                // if(a[i]==1 && b[i]==0){ 
                //     a[i] = 0;
                //     b[i] = 1;
                //     total_a++;
                //     total_b--;
                // }
            }
        }
        else{ // mai turn
            if(total_b%2 == 0){ // total_b is even 
                if(a[i]==1 && b[i]==0){ // swap
                    a[i] = 0;
                    b[i] = 1;
                    total_a--;
                    total_b++;
                }
                else if(a[i]==0 && b[i]==1){
                    a[i] = 1;
                    b[i] = 0;
                    total_a++;
                    total_b--;
                }
            }
            else{
                // nothing
            }
        }
    }

    int ans_a = total_a%2;
    int ans_b = total_b%2;

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