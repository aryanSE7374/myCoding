#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int gcd(int a , int b){
        if(b==0){return a;}
        return gcd(b,a%b);
    }
    vector<int> lcmAndGcd(int a, int b) {
        vector<int> vec;
        int GCD = gcd(a,b);
        vec.push_back(a*b/GCD); //LCM * GCD = a*b
        vec.push_back(GCD);
        return vec;
    }
};