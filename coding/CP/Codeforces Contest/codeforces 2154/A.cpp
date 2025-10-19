#include<bits/stdc++.h>
using namespace std;

bool prev_k_cnt(string& s , int k , int i){

    int st = max(0,i-k+1);

    // if(i<k-1){
    //     return true;
    // }

    for(int j=st ; j<i ; j++){
        if(s[j]=='1') return false;
    }

    return true;
}

void SOLVE(string& s , int n , int k ){

    int cnt = 0;

    vector<int> protect(n,0);

    for(int i=0 ; i<n ; i++){
        if(s[i]=='1' && protect[i]==0 && prev_k_cnt(s,k,i) ) {
            protect[i]=1;
            cnt++;
        }
    }

    cout<<cnt;

}

int main(){

    int t;
    cin>>t;
    while(t-->0){

        int n,k;
        cin>>n;
        cin>>k;

        string s;
        cin>>s;

        SOLVE( s , n , k);
        cout<<endl;

    }

    return 0;
}