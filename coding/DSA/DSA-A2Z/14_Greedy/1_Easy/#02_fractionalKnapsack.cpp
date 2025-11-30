#include<bits/stdc++.h>
using namespace std;

// GFG version

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<tuple<double , int , int>> valByWt(n);
        
        for(int i=0 ; i<n ; i++){
            valByWt[i] = {1.0*val[i]/wt[i] , wt[i] , val[i]};
        }
        
        sort(valByWt.rbegin() , valByWt.rend());
        // reverse(valByWt.begin() , valByWt.end());
        
        double ans = 0.0;
        
        int i=0;
        while(i<n){
            auto& [ratio, wtt , val] = valByWt[i];
            if(capacity>=wtt){
                ans += 1.0*val;
                capacity -= wtt;
            }
            else{
                ans += 1.0*capacity*ratio;
                break;
            }
            i++;
        }
        
        return ans;
    }
};
