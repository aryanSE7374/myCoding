#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        bool ans = ( (a==b) && (b==c) && (c==d) );
        if(ans) cout<<"YES";
        else cout<<"NO";
        cout<<endl;

    }

    return 0;
}