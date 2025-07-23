#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){return 1.0;}
        if(x==0){return 0.0;}
        if(n==1){return x;}
        if (x==-1 && n%2==0){return 1.0;}
        if (x==-1 && n%2!=0){return -1.0;}
        

        long BF = n;
        if(BF<0){
            //negative powers
            x=(1/x);
            BF=-BF;
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

