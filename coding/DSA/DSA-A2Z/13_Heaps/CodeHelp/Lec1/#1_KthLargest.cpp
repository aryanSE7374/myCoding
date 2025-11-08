#include<bits/stdc++.h>
using namespace std;
// leetcode
// sol1

// TC : O(N*logN)
// SC : O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin() , nums.rend());
        return nums[k-1];
    }
};

// ------------------------------------------------------------ //

// sol 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin() , nums.end());
        for(int i=1 ; i<=k-1 ; i++){
            pq.pop();
        }
        return pq.top();
    }
};

// ------------------------------------------------------------ //

// sol3

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        priority_queue<int , vector<int> , greater<int> > pq(nums.begin() , nums.begin()+k);

        for(int i=k ; i<n ; i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();

    }
};

