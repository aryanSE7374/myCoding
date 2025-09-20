#include<bits/stdc++.h>
using namespace std;


void SOLVE(vector<int> vec , int n){
    vector<int> pref(n,0);
    pref[0] = vec[0];
    for(int i=0 ; i<n-1 ; i++){
        pref[i+1] = pref[i]+vec[i+1];
    }

    int ans1 = 0;
    int ans2 = 0;

    for(int l=0 ; l<n-2 ; l++){
        for(int r = l+1 ; r<n-1 ; r++){
            int s1=pref[l]%3;
            int s2=(pref[r]-pref[l])%3;
            int s3=(pref[n-1]-pref[r])%3;
            if((s1+s2+s3)%3==0){
                ans1 = l+1;
                ans2 = r+1;
                break;
            }
        }
    }

    cout<<ans1<<" "<<ans2;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> vec(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        SOLVE(vec , n);

        cout<<endl;

    }
    return 0;
}