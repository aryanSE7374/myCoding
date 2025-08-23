#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int sumOfSeries(int n) {
        if(n==1){return 1;}
        return n*n*n + sumOfSeries(n-1);
    }
};