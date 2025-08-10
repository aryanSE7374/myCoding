#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0;
        int rSum = 0;
        for(int i=0 ; i<k ; i++){
            lSum += cardPoints[i];
        }
        int maxSum = lSum;
        for(int i=1 ; i<=k ; i++){
            lSum-=cardPoints[k-i];
            rSum+=cardPoints[n-i];
            maxSum = max(maxSum , lSum+rSum);
        }
        return maxSum;

    }
};