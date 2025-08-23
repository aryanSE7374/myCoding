#include<bits/stdc++.h>
using namespace std;

long long cunningSeller1(long long n) {
    long long res = 0;
    long long currPower3=1;
    while(n>0){
        int digit = n%3;
        if(digit==2) {
            res += currPower3; 
            n += 3;          
        }
        else if (digit == 1) {
            res += currPower3;
        }
        n/=3;
        currPower3*=3;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        long long n;
        cin>>n;
        cout<<cunningSeller1(n)<<endl;
    }
    return 0;
}
