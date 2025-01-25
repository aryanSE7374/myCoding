#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            while(i<n && nums[i]){
                curr++;i++;
            }
            maxi = max(curr,maxi);
        }
    }
};