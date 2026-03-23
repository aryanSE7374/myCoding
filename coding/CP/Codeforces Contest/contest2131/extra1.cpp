#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for ( int i=a ; i<b ; i++ ) 

void SOLVE_BLOCK(){
    int n; cin>>n;
    string s; cin>>s;
    int count=0;
    int ans=0;
    f(i,0,n){
        if(s[i]=='(')count++;
        else count--;
        ans=min(ans,count);
    }
    cout<<-1*ans<<endl;
}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        SOLVE_BLOCK();
    }

    return 0;
}