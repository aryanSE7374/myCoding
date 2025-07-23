
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkPrime(int n){
        if(n==1){return false;}
        if(n==2 || n==3){return true;}
        if(n%2==0 || n%3==0){return true;}
        for(int i=5 ; i*i <= n ; i+=6){
            if(n%i == 0 || n%(i+2)==0){return false;}
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long s1 = 0; // Primes
        long long s2 = nums[0]; // non Primes
        for(int i=1 ; i<n ; i++){
            if(checkPrime(i)){s1+=nums[i];}
            else{
                s2+=nums[i];
            }
                
        }

        return labs(s1-s2);
    }
};

// 2

class Solution {
public:
    bool checkPrime(int n){
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5; i * i <= n; i += 6){
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long s1 = 0; // sum of prime indices
        long long s2 = 0; // sum of non-prime indices

        for(int i = 0; i < n; i++){
            if(checkPrime(i)) s1 += nums[i];
            else s2 += nums[i];
        }

        return abs(s1 - s2);
    }
};