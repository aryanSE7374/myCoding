#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k=1;
        long long target = num1-num2; // k=1
        while(target>0){
            if(__builtin_popcountll(target)<=k && target>=k){
                return k;
            }
            k++;
            target = num1-1LL*k*num2;
        }
        return -1;
    }
};

/*
The three conditions to check for each k:

target >= 0

k >= __builtin_popcountll(target)

target >= k
*/