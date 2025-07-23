#include<bits/stdc++.h>
using namespace std;



// the sum method

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrSum = 0;
        int n = nums.size();
        int sum = n * (n + 1) / 2; // Calculate the sum of the first n natural numbers
        for (int i = 0; i < n; i++) {
            arrSum += nums[i]; // Sum of elements in the array
        }
        return sum - arrSum; // Return the missing number
    }
};




// the xor method (better)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0 , xor2 = 0;
        for(int i=0 ; i<nums.size() ; i++){
            xor2^=nums[i];
            xor1^=i+1;
        }
        return xor1^xor2;
    }
};