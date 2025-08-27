#include<bits/stdc++.h>
using namespace std;


bool canBeSymmetric(int n , int a , int b){
    if((n&1)==1){
        if(((a&1)==1)&&((b&1)==1)){return true;}
        if(((a&1)==0)&&((b&1)==1)&&(b>a)){return true;}
        return false;
    }
    else{
        if(((a&1)==0)&&((b&1)==0)){return true;}
        if(((a&1)==1)&&((b&1)==0)&&(b>a)){return true;}
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while (t-->0)
    {
        int n,a,b;
        cin>>n;
        cin>>a;
        cin>>b;
        if(canBeSymmetric(n,a,b)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}