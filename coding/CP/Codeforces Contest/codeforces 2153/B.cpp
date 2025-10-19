#include<bits/stdc++.h>
using namespace std;


void SOLVE(int x , int y , int z){

    int a = 0 , b = 0 , c = 0;

    // 1
    a = x;
    b = x;

    // 2
    b = b | y ;
    c = y;

    // 3
    c = c | z ;
    a = a | z ;

    // 4

    if( ((a&b) == x) && ((b&c) == y) && ((a&c) == z) ) {
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x;
        cin>>y;
        cin>>z;

        SOLVE(x,y,z);
        cout<<endl;

    }

    return 0;
}