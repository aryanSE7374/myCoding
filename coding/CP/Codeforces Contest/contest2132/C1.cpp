#include<bits/stdc++.h>
using namespace std;
 
long long cunningSeller1(long long n){
    // if(){}
    int logbase3n = (int)(log(n) / log(3));
    long long rem = n - pow(3,logbase3n);

}
 
int main() {
    int t;
    cin >> t;
    while (t-->0) {
        long long n; 
        cin >> n;
        cout<<cunningSeller1(n)<< endl;
    }
    return 0;
}