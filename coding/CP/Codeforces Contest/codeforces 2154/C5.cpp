// GPT

#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    while(b != 0){
        int t = b;
        b = a % b; 
        a = t;
    }
    return a;
}

void SOLVE(vector<int>& a , vector<int>& b ,  int n){
    int minOps = 2;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(gcd(a[i], a[j]) > 1){
                cout << 0 << "\n";
                return;
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(gcd(a[i]+1, a[j]) > 1 || gcd(a[i], a[j]+1) > 1){
                cout << 1 << "\n";
                return;
            }
        }
    }

    cout << 2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        for(int i=0 ; i<n ; i++) cin >> b[i];
        SOLVE(a,b,n);
    }

    return 0;
}