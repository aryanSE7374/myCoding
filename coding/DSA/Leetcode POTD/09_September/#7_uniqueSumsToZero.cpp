#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------//

// editorial

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};

// ------------------------------------------------------------//
// my sol

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        if(n%2==0){
            for(int i=0 ; i<n-1 ; i+=2){
                res[i]=(i+1);
                res[i+1]=-1*(i+1);
            }
        }
        else{
            res[0] = 0;
            for(int i=1 ; i<n-1 ; i+=2){
                res[i]=i;
                res[i+1]=-1*i;
            }
        }
        return res;
        
    }
};
