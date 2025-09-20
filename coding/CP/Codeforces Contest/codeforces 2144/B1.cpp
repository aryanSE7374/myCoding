#include<bits/stdc++.h>
using namespace std;

pair<int , int> checkSorted(vector<int> &p , int n , int start , int end){
    // returns unsorted range
    // int l=0 , r=n-1;
    int l=start , r=end;
    while(l<=r){
        bool flag = false;
        if(p[l]==l+1){l++;flag=true;}
        if(p[r]==r+1){r--;flag=true;}
        if(!flag){return {l,r};}
    }
    return {-1,-1};

}
void SOLVE(vector<int> &p , int n){

    int res1 = 0;
    int res2 = 0;

    int l=-1,r=-1;
    bool zeroFlag = false;
    int count = 0;

    for(int i=0 ; i<n ; i++){
        if(!zeroFlag && p[i]==0 ){
            l=i;
            r=i;
            count++;
            zeroFlag = true;
        }
        else if(p[i]==0){
            r=i;
            count++;
        }
    }
    if(!zeroFlag){
        auto [low , high] = checkSorted(p,n,0,n-1);
        if(low == -1) cout << 0; // already sorted
        else cout << high - low + 1;
        return;
    }

    cout<<r-l+1;

    // if(l==0 && r==n-1){
    //     cout << n; // all zero elements
    //     return;
    // }

    // res1=l;
    // res2=r;

    // auto [l1 , r1] = checkSorted(p,n,0,l-1);
    // auto [l2 , r2] = checkSorted(p,n,l,r);
    // auto [l3 , r3] = checkSorted(p,n,r,n-1);

    // if(l1!=-1 && r2!=-1){
    //     res1=l1;
    // }
    // if(l3!=-1 && r3!=-1){
    //     res2=r3;
    // }

    // cout<<r-l+1;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> p(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>p[i];
        }

        SOLVE(p , n);

        cout<<endl;

    }
    return 0;
}
