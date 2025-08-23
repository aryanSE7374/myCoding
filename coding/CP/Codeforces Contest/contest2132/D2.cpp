#include<bits/stdc++.h>
using namespace std;
 
long long sumOfDigitsInSequence(long long k){
    long long sum = 0;
    long long num = 1;

    if(k<=9){
        return k*(k+1)/2;
    }
    else{
        sum=45;
        k-=9;
        num=10;
    }

    while (k>0)
    {
        int digits = (int)log10(num) + 1;
        long long dummyNum = num;
        if(digits>k){
            long long dummyNum = num / pow(10 , digits-k);
        }
        while(dummyNum>0){
            sum += (dummyNum%10);
            dummyNum/=10;
        }
        k-=digits;
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