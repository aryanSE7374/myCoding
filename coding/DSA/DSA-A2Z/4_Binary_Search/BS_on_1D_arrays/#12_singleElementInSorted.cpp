#include<bits/stdc++.h>
using namespace std;

//Problem Statement: Given an array of N integers. 
// Every number in the array except one appears twice. Find the single number in the array.

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            if(n==1){return nums[0];} // single element edge case
            // explicit checking for corner elements
            if(nums[0]!=nums[1]){return nums[0];}
            if(nums[n-1]!=nums[n-2]){return nums[n-1];}
            int low=1;
            int high=n-2;
            while (low<=high)
            {
                int mid = (low+high)/2;
                if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){
                    return nums[mid]; // found the single element
                }
                // method 1
                // // even, odd case -> element on right half
                // if((nums[mid]%2==1 && nums[mid]==nums[mid-1]) || ((nums[mid]%2==0 && nums[mid]==nums[mid+1]))){
                //     low = mid+1;
                // }
                // // odd, even case -> element on left half
                // else{
                //     high = mid-1;
                // }

                //method 2
                // odd, even case -> element on left half
                if((mid%2==0 && nums[mid]==nums[mid-1]) || ((mid%2==1 && nums[mid]==nums[mid+1]))){
                    high = mid-1;
                }
                // even, odd case -> element on right half
                else{
                    low = mid+1;
                }
            }
            return -1; //dummy statement to get rid of warnings
        }
    };