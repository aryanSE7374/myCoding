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

    int n,l,r;

    cin >> n >> l >> r;

    l--;
    r--;

    vi a(n);

    int large1 = 1000000000; // 10^9
    int large2 = large1-1; // 10^9 - 1


    if((l-r+1)%2 == 0){
        int mid = (r-l)/2 + (l);
        // f(i,l,mid+1){
        //     a[i] = large1;
        // }
        // f(i,mid+1,r+1){
        //     a[i] = large2;
        // }
        f(i,l,r+1){
            a[i] = large1;
        }
    }
    else{ // l-r+1 >= 3
        f(i,0,3){
            a[l+i] = i+1;
        }
        int mid = (r-l+3)/2 + (l+3);
        // f(i,l+3,mid+1){
        //     a[i] = large1;
        // }
        // f(i,mid+1,r+1){
        //     a[i] = large2;
        // }
        f(i,l+3,r+1){
            a[i] = large1;
        }
    }

    int k=1004;

    for(int i=0 ; i<l ; i++){
        a[i] = k;
        k++;
        if(k%4 == 3) k++;
    }

    for(int i=r+1 ; i<n ; i++){
        a[i] = k;
        k++;
        if(k%4 == 3) k++;
    }

    f(i,0,n){
        cout << a[i] << " ";
    }


    // cout << "\n-----\n";

    // int temp = 0;
    // f(i,l,r+1){
    //     temp ^= a[i];
    // }
    // cout << "lxorr = " << temp <<"\n";



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