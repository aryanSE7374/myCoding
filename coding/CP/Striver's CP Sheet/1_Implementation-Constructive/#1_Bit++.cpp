#include<bits/stdc++.h>
using namespace std;

int bitOps(string s){
    if(s[1]=='+'){return 1;}
    else{return -1;}
    // if(s=="X++" || s=="++X"){
    //     return 1;
    // }
    // else{
    //     return -1;
    // }
}

int main()
{
    int n;
    cin>>n;
    int ans = 0;
    while (n-->0)
    {
        string s;
        cin>>s;
        ans += bitOps(s);
    }
    cout<<ans;
    return 0;
}
