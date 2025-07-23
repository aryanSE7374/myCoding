#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int low=0; int high = nums.size()-1; int mid = 0;
            int mini = INT_MAX;
            while(low<=high){
                mid = (low+high)/2;
                if(nums[low]<=nums[high]){//if sorted part from low to high i.e. both left and right part sorted
                    return min(mini,nums[low]); // min should be called here as well to handle edge case
                }
                else if(nums[mid]<=nums[high]){ // right sorted
                    mini = min(mini,nums[mid]);
                    //search in left
                    high = mid-1;
                }
                else{// left sorted
                    mini = min(mini,nums[low]);
                    // search in right
                    low = mid+1;
                }
            }
            return mini;
        }
    };





// int findMinIndex(vector<int>& nums,int n) {
//     int low=0; int high = n-1; int mid = 0;
//     int mini = INT_MAX;
//     int ans = n;
//     while(low<=high){
//         mid = (low+high)/2;
//         if(nums[low]<=nums[high] && (nums[low]<=mini)){//if sorted part from low to high i.e. both left and right part sorted
//                 ans=low;
//         }
//         else if(nums[mid]<=nums[high]){ // right sorted
//             mini = min(mini,nums[mid]);
//             if(nums[mid]<mini){ans=mid;}
//             //search in left
//             high = mid-1;
//         }
//         else{// left sorted
//             mini = min(mini,nums[low]);
//             if(nums[low]<mini){ans=mid;}
//             // search in right
//             low = mid+1;
//         }
//     }
//     return ans;
// }