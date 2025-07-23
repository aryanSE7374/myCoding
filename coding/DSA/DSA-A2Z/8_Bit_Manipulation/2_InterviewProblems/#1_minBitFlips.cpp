#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSet(int N){
        int cnt = 0;
        while(N>0){
            N = N & (N-1);
            cnt++;
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        return countSet(start^goal);
    }
};