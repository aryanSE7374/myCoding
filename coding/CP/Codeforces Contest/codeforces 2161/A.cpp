#include<bits/stdc++.h>
using namespace std;
#define ll long long

void SOLVE(ll Ro , ll X , ll D , ll  n , string s ){

    bool flag = false; // is rated div 2
    ll ans = 0;
    ll R = Ro; // curr rating

    for(char c : s){
        if( flag || c == '1'){
            ans ++;
            if(R>=X){
                R -= D;
            }
        }  
        else if(c == '2' && R < X){
            ans++;
            flag = true;
        }

    }

    cout<<ans;


}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        ll Ro , X , D , n;
        cin>>Ro>>X>>D>>n;
        string s;
        cin>>s;

        SOLVE( Ro , X , D , n , s);
        cout<<endl;

    }

    return 0;
}