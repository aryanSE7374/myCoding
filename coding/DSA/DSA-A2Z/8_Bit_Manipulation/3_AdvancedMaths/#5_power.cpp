#include<bits/stdc++.h>
using namespace std;

// TC : O(log N)


// recursive sol
class Solution {
public:
    // helper recursive function
    double pow(double x , long BF){
        if(BF==0){return 1;}
        if(BF%2==1){return x*pow(x,BF-1);}
        return pow(x*x , BF/2);
    }

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
        
        return pow(x , BF);
    }
};

// iteratve sol 1 : GPT

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0.0;
        if (n == 0) return 1.0;
        if (x == -1) return (n % 2 == 0) ? 1.0 : -1.0;

        long BF = n;
        if (BF < 0) {
            x = 1 / x;
            BF = -BF;
        }

        double result = 1.0;
        while (BF > 0) {
            if (BF % 2 == 1) {
                result *= x;
            }
            x *= x;
            BF /= 2;
        }
        return result;
    }
};

// iterative sol2 : striver

class Solution {
public:
    double myPow(double x, int n) {
        int original_n = n;
        long N = n;

        double ans = 1.0;

        if (n < 0) {
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 1) {
                ans = ans * x;
                N = N - 1;
            } else {
                x = x * x;
                N = N / 2;
            }
        }

        if (original_n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }
};
