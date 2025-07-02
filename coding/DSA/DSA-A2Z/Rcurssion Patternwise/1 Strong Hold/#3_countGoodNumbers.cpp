#include<bits/stdc++.h>
using namespace std;


// brute iterative try 1

class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1000000007;
        long long res = 1;

        for(int i=0 ; i<n-1 ; i+=2){
            res = (res*5)%mod;
            res = (res*4)%mod;
        }

        if(n&1==1){
            res = (res*5)%mod;
        }
        
        return (int)res;

        /*
        long long nby2 = n/2;
        if(n%2==0){
            // return (int)((pow(5 , nby2)*pow(4 , nby2))%mod);
            long long pow5 = (pow(5 , nby2));
            long long pow4 = (pow(4 , nby2));
            cout<<"pow5: "<<pow5<<endl<<"pow4: "<<pow4<<endl;
            int res = (int)pow5*(int)pow4;
            // long long res =  ((pow(5 , nby2)%mod)*(pow(4 , nby2)%mod))%mod;
            // int res = ((long long)pow(5 , nby2)*(long long)pow(4 , nby2))%mod;
            return res;
        }
        else {
            long long pow5 = (pow(5 , nby2+1));
            long long pow4 = (pow(4 , nby2));
            cout<<"pow5: "<<pow5<<endl<<"pow4: "<<pow4<<endl;
            int res = (int)pow5*(int)pow4;
            // return (int)((pow(5 , nby2+1)*pow(4 , nby2))%mod);
            // int res = ((long long)pow(5 , nby2+1)*(long long)pow(4 , nby2))%mod;
            // long long res =  ((pow(5 , nby2+1)%mod)*(pow(4 , nby2)%mod))%mod;
            return res;
        }
        */
    }
};



// try 2


const int mod = 1000000007;

class Solution {
public:
    long long myPow(long long x, long long n) {
        if(n==0){return 1.0;}
        if(x==0){return 0.0;}
        if(n==1){return x;}
        if (x==-1 && n%2==0){return 1.0;}
        if (x==-1 && n%2!=0){return -1.0;}
        
        long long res = 1;
        
        while (n>0)
        {
            if (n%2==1)
            {
                res = (res*x)%mod;
            }
            x = (x*x)%mod;
            n/=2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        // long long res = myPow(4,n/2)*myPow(5, n-(n/2));
        // res%=mod;
        // return res;
        // OR
        long long pow4 = myPow(4,n/2);
        long long pow5 = myPow(5, n-(n/2));

        return (pow5 * pow4) % mod;

    }
};