#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size() ;

        int mini = prices[0] ;
        int profit = 0;

        for ( int i=1 ; i<n ; i++ ) {
            if ( prices[i] < mini ) mini = prices[i];
            else profit = max ( profit , prices[i] - mini ) ;
        }

        return profit ;

    }
};