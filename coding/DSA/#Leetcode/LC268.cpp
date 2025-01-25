#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
    }
};

int missingNumber(int* nums, int numsSize) 
{
	int arrSum=0;
	int sum = numsSize*(numsSize+1)/2;
	for (int i = 0; i < numsSize; i++)
	{
		arrSum+=nums[i];
	}
	return sum - arrSum;
}