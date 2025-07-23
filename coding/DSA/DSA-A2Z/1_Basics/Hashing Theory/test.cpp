#include<bits/stdc++.h>
using namespace std;



// prob # 1838. Frequency of the Most Frequent Element



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int l = 0, res = 1;
        
        for (int r = 1; r < nums.size(); ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            
            while (total > k) {
                total -= nums[r] - nums[l];
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};



// brute force 

/*
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxFreq = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int operations = k;
            int currentFreq = 1;
            for (int j = i - 1; j >= 0; --j) {
                int diff = nums[i] - nums[j];
                if (operations >= diff) {
                    operations -= diff;
                    currentFreq++;
                } else {
                    break;
                }
            }
            maxFreq = max(maxFreq, currentFreq);
        }
        return maxFreq;
    }
};
*/


int main() {
    vector<int> nums1 = {1, 2, 4};
    int k1 = 5;
    Solution sol;
    cout << "Example 1: " << sol.maxFrequency(nums1, k1) << endl;

    vector<int> nums2 = {1, 4, 8, 13};
    int k2 = 5;
    cout << "Example 2: " << sol.maxFrequency(nums2, k2) << endl;

    vector<int> nums3 = {3, 9, 6};
    int k3 = 2;
    cout << "Example 3: " << sol.maxFrequency(nums3, k3) << endl;

    return 0;
}
