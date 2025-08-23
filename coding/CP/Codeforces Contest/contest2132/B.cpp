#include<bits/stdc++.h>
using namespace std;
 
void secretNumber(long long n){
    int digits = (int)log10(n) + 1;
 
    // n / (1 + 10^k) - k : 1 to digits-1
    long long power_10_k = 10;
    int count = 0;
    for(int k=1 ; k<digits ; k++){
        if(n%(power_10_k+1) == 0){
            cout << n/(power_10_k+1) << " ";
            count++;
        }
        power_10_k*=10;
    }
 
    if(count == 0){
        cout<<"0";
    }
 
}
 
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n; 
        cin >> n;
        secretNumber(n);
        cout<< endl;
    }
    return 0;
}