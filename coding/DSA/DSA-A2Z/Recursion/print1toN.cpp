#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Complete this function
    void printNos(int n) {
        if(n==1){cout<<"1 ";return;}
        printNos(n-1);
        cout<<n<<" ";
    }
};