#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1


// better and only optimal possible
// TC : O(N*logN)
// SC : O(N)

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        long long ans = 0;
        priority_queue<int , vector<int> , greater<int> > pq(arr.begin() , arr.end()); 
        while(pq.size()>1){
            int r1 = pq.top();
            pq.pop();
            int r2 = pq.top();
            pq.pop();
            int sum = r1 + r2;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};








