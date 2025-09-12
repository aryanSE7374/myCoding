#include<bits/stdc++.h>
using namespace std;

bool check(int x , int k){

    long long y = k*x;
    int d = 1 + (int)log10(y) ;

    return ( ( (long long)(1LL*x*pow(10,d)) - 1LL*k*(x+y) ) % 1LL*(x+y) == 0) ;
}

long long SOLVE(long long x){
    int k=+2;
    while(true){
        if( check(x,k) ){return x*k;}
        k++;
        if(k>2) break;
    }
    return 1LL*2*x;
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long x;
        cin>>x;

        cout<<SOLVE(x);

        cout<<endl;


    }
    return 0;
}