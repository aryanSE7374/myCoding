#include<bits/stdc++.h>
using namespace std;

long long sumOfDigitsInSequence(long long k) {
    long long sum = 0;
    long long digits = 1;
    long long count = 9;
    long long start = 1;

    while (k > count * digits) {
        if (digits == 1) {
            sum += 45;
        } else {
            long long p = 1;
            for(int i = 0; i < digits - 2; ++i) {
                p *= 10;
            }
            sum += (9LL * digits + 1) * 45LL * p;
        }
        k -= count * digits;
        digits++;
        count *= 10;
        start *= 10;
    }

    long long num_count = (k - 1) / digits;
    long long target_num = start + num_count;

    for (long long i = start; i < target_num; ++i) {
        long long temp = i;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
    }
    
    long long remaining_digits = (k - 1) % digits + 1;
    long long divisor = 1;
    for (int i = 0; i < digits - remaining_digits; ++i) {
        divisor *= 10;
    }
    long long prefix_num = target_num / divisor;

    while (prefix_num > 0) {
        sum += prefix_num % 10;
        prefix_num /= 10;
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