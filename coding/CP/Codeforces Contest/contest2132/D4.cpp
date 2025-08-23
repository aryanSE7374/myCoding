#include<bits/stdc++.h>
using namespace std;

long long sumOfDigitsInSequence(long long k) {
    long long digits = 1;
    long long count = 9;
    long long sum = 0;
    long long start = 1;
    while(k > count*digits) {

        if(digits == 1) {
            sum += 45;
        } 

        else {

            long long mulFactor=1;
            for(int i = 0; i < digits-2 ; i++) {
                mulFactor *= 10;
            }
            sum += (9LL*digits + 1) * 45LL * mulFactor;
        }
        k = k - (count * digits);
        digits++;
        count *= 10;
        start *= 10;

    }

    long long numCnt = (k-1)/digits;
    long long target = start + numCnt;

    for (long long i = start; i<target; i++) {
        long long temp = i;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
    }
    
    long long remDigs = (k - 1) % digits + 1;
    string s = to_string(target);
    for (int i = 0; i < remDigs; i++) {
        sum += s[i]-'0';
    }

    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        long long k; 
        cin >> k;
        cout<<sumOfDigitsInSequence(k)<< endl;
    }
    return 0;
}