#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &p , int n ){

    for(int i=0 ; i<n ; i++){
        cout<<( n + 1 - p[i] ) << " ";
    }
    
}

int main(){
    int t;
    cin>>t;
    while (t-->0)
    {
        int n;
        cin>>n;

        vector<int> p(n);

        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }

        solve(p , n);

        cout<<endl;
    }   
}