#include<bits/stdc++.h>
using namespace std;
 


long long sumOfDigitsInSequence(long long k) {
    long long sum = 0;
    long long num = 1;

    if (k <= 9) {
        return k * (k + 1) / 2;  // sum of 1..k
    } else {
        sum = 45;  // sum of 1..9
        k -= 9;
        num = 10;
    }

    while (k > 0) {
        int digits = (int)log10(num) + 1;
        long long dummyNum;

        if (digits > k) {
            // take only the first k digits of num
            long long div = 1;
            for (int i = 0; i < digits - k; i++) div *= 10;  // avoid pow()
            dummyNum = num / div;
        } else {
            dummyNum = num;
        }

        while (dummyNum > 0 && k > 0) {
            sum += (dummyNum % 10);
            dummyNum /= 10;
            k--;
        }

        if (digits <= k) {
            k -= digits;  // already consumed full number
        }

        num++;
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