#include<bits/stdc++.h>
using namespace std;

// optimal sol : order of answer matters

// TC : O(sqrt(N))
// SC : O(sqrt(N))

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i = 1 ; i*i <= n ; i++){
            if(n%i == 0){
                cout<<i<<" ";
                if(i!=n/i){ans.push_back(n/i);}
            }
        }
        reverse(ans.begin() , ans.end());
        for(int div : ans){
            cout<<div<<" ";
        }
    }
};


// optimal sol : order of answer doesn't matters
// TC : O(sqrt(N))
// SC : O(1) : no storage