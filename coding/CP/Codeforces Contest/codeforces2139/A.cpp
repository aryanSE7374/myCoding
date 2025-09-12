#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while (t-->0)
    {

        int a,b;
        cin>>a;
        cin>>b;

        if(a==b){cout<<"0 ";}
        else if(b>a){
            if(b%a==0){cout<<"1 ";}
            else {cout<<"2 ";}
        }
        else{ // b<a
            if(a%b==0){cout<<"1 ";}
            else {cout<<"2 ";}
        }

        cout<<endl;

    }

    return 0;
    
}