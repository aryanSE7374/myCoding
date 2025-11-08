#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        string s , t1;
        cin>>n;
        cin>>s;
        cin>>t1;
        sort(s.begin() , s.end());
        sort(t1.begin() , t1.end());

        bool ans = (s == t1);
        if(ans) cout<<"YES";
        else cout<<"NO";
        cout<<endl;

    }

    return 0;
}