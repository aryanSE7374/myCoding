#include<bits/stdc++.h>
using namespace std;

vector<long long> secretNumber(long long n){
    int digits = (int)log10(n) + 1;
    vector<long long> res;

    // n / (1 + 10^k) - k : 1 to digits-1
    long long power_10_k = 10;
    int count = 0;
    for(int k=1 ; k<digits ; k++){
        if(n%(power_10_k+1) == 0){
            count++;
            res.push_back(n/(power_10_k+1));
        }
        power_10_k*=10;
    }

    cout<<count<<endl;
    return res;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; 
        cin >> n;
        vector<long long> res = secretNumber(n);
        sort(res.begin() , res.end());
        for(long long x : res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}