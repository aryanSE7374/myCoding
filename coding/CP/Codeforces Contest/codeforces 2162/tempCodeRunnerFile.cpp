#include<bits/stdc++.h>
using namespace std;



void SOLVE(int a , int b){

    if(a<b){
        cout << -1 ;
        return;
    }
    else if (a==b){
        cout << 0;
        return;
    }
    else{ // a > b
        cout << 2 <<endl;
        cout << a << " " << b << " ";
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int a , b;
        cin>>a;
        cin>>b;

        SOLVE(a , b);
        cout<<endl;

    }

    return 0;
}