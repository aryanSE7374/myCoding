#include <bits/stdc++.h>
using namespace std;

// sol#1

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            int ans = nums.size();
            while (left <= right) {
                int mid = left + (right - left) / 2; // Avoid potential overflow
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else { // nums[mid] > target
                    ans = mid;
                    right = mid - 1;
                }
            }
            
            // If target is not found, `left` is the insertion point
            return ans;
        }
    };


// sol#2
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            // ans variable not needed
            while (left <= right) {
                int mid = left + (right - left) / 2; // Avoid potential overflow
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            // If target is not found, `left` is the insertion point
            return left;
        }
    };