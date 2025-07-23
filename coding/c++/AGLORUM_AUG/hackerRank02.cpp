#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reversedDigits(int num){
    long int rev = 0;
    // to reverse the digits of a negative number
    // -2147483648 corner case: 
    if (num==INT_MIN)
    {
        return 0;
    }
    if(num<0){
        num *= (-1);
        while (num>0)
        {
            rev = (rev*10)+(num%10);
            num/=10;
        }
        rev *= (-1);
        if((rev<INT_MIN)||(rev>INT_MAX))
        {
            return 0;
        }
        else{
            return rev;
        }
    }
    while (num>0)
    {
        rev = (rev*10)+(num%10);
        num/=10;
    }
    if((rev<INT_MIN)||(rev>INT_MAX))
    {
        return 0;
    }
    else{
        return (int)rev;
    }
}

int main() {
// 2147483647
    int t;
    cin>>t;
    while(t-->0){
        int x;
        cin>>x;
        int res = reversedDigits(x);
        cout<<res<<endl;
    }
    return 0;
}
