#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            // brute
            for(int i=0 ; i<nums.size() ; i++){
                if(nums[i]==target){return true;}
            }
            return false;
        }
    };
*/


class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int low=0, high=n-1;
            int mid = (low+high)/2;
            while(low<=high){
                mid = (low+high)/2;
                if(nums[mid]==target){return true;}
                else if((nums[low]==nums[mid])&&(nums[mid]==nums[high])){
                    for(int i=0 ; i<nums.size() ; i++){
                        if(nums[i]==target){return true;}
                    }
                    return false;
                }
                else if(nums[mid]<=nums[high]){// right part sorted
                    if(nums[mid]<=target && target<=nums[high]){ //target lies between the sorted part
                        low=mid+1; // search the right to mid (i.e. the right part)
                    }
                    else{high=mid-1;}// else search the other/non-sorted part
                }
                else{ // nums[mid]>nums[high] => left part sorted
                    if(nums[low]<=target && target<=nums[mid]){ //target lies between the sorted part
                        high=mid-1; // search the left to mid (i.e. the left part)
                    }
                    else{low=mid+1;} //else search the other/non-sorted part
                }
            }
            return false;
        }
    };

    