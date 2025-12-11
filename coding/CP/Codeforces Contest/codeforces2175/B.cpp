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

    int k = 1;
    f(i,l,r+1){
        a[i] = k;
    }
    k++;

    for(int i=0 ; i<l ; i++){
        a[i] = k;
        k++;
    }

    for(int i=r+1 ; i<n ; i++){
        a[i] = k;
        k++;
    }

    f(i,0,n){
        cout << a[i] << " ";
    }


    cout << "\n-----\n";

    int temp = 0;
    f(i,l,r+1){
        temp ^= a[i];
    }
    cout << "lxorr = " << temp <<"\n";



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