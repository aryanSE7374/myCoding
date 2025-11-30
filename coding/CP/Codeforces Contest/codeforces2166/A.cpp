#include<bits/stdc++.h>
using namespace std;


void SOLVE(){


    int n;
    cin>>n;
    string s;
    cin>>s;

    unordered_map<char , int> freq;
    // int maxf = INT_MIN;
    for(int i=0 ; i<n ; i++){
        freq[s[i]]++;
        // maxf = max(maxf , freq[s[i]]);
    }

    cout << n-freq[s[n-1]];

    cout << "\n";



}

int main(){

    int t;
    cin>>t;
    while(t-->0){
        SOLVE();
    }

    return 0;
}