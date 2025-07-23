#include<bits/stdc++.h>
using namespace std;


// sol 1 :  Frequency Map (Brute Force) – O(N) time, O(N) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> frequency;
        for(int num : nums){
            frequency[num]++;
        }
        for(auto it : frequency){
            if(it.second == 1){
                return it.first;
            }
        }
        // dummy
        return 0;
    }
};

// sol 2  : Bit Count (Bitwise Optimal) – O(32·N) time, O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            int bitCount = 0;
            for(int num : nums) {
                if(num & (1 << i)) bitCount++;
            }
            if(bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};

// sol3 : Sort + Step Check – O(N log N) time, O(1) space (excluding sort)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i += 3) {
            if(nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }
        // Last element is the single one
        return nums[n - 1];
    }
};

// sol 4 : Bitmasking Trick (Two-Bucket States) – O(N) time, O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};