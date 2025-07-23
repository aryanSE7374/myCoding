#include<bits/stdc++.h>
using namespace std;

// leetcode 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/description/

//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

/*
Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= x^n <= 10^4
*/


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1.0;}
        if(x==0){return 0.0;}
        if(n==1){return x;}
        if (x==-1 && n%2==0){return 1.0;}
        if (x==-1 && n%2!=0){return -1.0;}
        

        long BF = n; // binary form
        if(BF<0){
            //negative powers 
            x=(1/x);
            BF=-BF; // making positive expo for negative powers
        }
        double res = 1;
        while (BF>0)
        {
            if (BF%2==1)
            {
                res*=x;
            }
            x*=x;
            BF/=2;
        }
        return res;
    }
};

