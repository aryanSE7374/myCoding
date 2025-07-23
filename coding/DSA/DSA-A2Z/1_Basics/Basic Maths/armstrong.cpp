#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool armstrongNumber(int n) {
        int k = 0 , num = n , sum=0; // k = no. of digits
        while (num!=0)
        {
            k++;
            num/=10;
        }
        num = n;
        while (num!=0)
        {
            int ld = num%10;
            sum+=(pow(ld,k));
            num/=10;
        }
        return sum==n?true:false;
    }
};


// int main(){
//     int ld = 2;
//     int k = 9;
//     cout<<pow(ld,k);
// }