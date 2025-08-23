#include<bits/stdc++.h>
using namespace std;

// GFG link : https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

// brute : O(N) , O(1)

// TC : O(1)
// SC : O(1)

class Solution {
  public:
    int XOR(int N){
        if(N%4==1) return 1;
        if(N%4==2) return N+1;
        if(N%4==3) return 0;
        if(N%4==0) return N;
        return 0;
    }
    int findXOR(int l, int r) {
        return XOR(l-1)^XOR(r);
    }
};