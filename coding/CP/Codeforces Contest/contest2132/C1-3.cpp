#include <bits/stdc++.h>
using namespace std;

long long cunningSeller(long long n) {
    long long res = 1;
    while (res < n) {
        res *= 3;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << cunningSeller(n) << endl;
    }
    return 0;
}