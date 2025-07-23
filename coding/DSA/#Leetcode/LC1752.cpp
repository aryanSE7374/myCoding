#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        int rot_idx=0;
        while (i<nums.size()-1)
        {
            if(nums[i]>nums[i+1]){
                // return false;
                rot_idx = i+1;
                break;
            }
            i++;
        }
        if(rot_idx==0){return true;}
        while(rot_idx<nums.size()-1){
            if((nums[rot_idx]>nums[rot_idx+1])||(nums[rot_idx]>nums[0])){
                return false;
            }
            rot_idx++;
        }
        if(nums[rot_idx]>nums[0]){return false;}
        return true;
    }
};


class Solution {
  public:
    
};


