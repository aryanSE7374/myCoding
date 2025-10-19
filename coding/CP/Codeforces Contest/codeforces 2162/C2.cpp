#include<bits/stdc++.h>
using namespace std;


vector<int> helper(int n){
    vector<int> result;
    int pow = 1;

    while(n > 0){
        if(n & 1) result.push_back(pow);
        n >>= 1;
        pow <<= 1;
    }

    return result;

}

void SOLVE(int a , int b){

    // if(a<b){
    //     cout << -1 ;
    //     return;
    // }
    
    if (a==b){
        cout << 0;
        return;
    }
    else{

        int k = a^b;

        vector<int> res = helper(k);

        if(res.back() > a){
            cout << -1 ;
            return;
        }

        cout << res.size() << endl;

        for(int num : res){
            cout << num << " " ;
        }

    }

}

int main(){

    int t;
    cin>>t;
    while(t--){

        int a , b;
        cin>>a;
        cin>>b;

        SOLVE(a , b);
        cout<<endl;

    }

    return 0;
}