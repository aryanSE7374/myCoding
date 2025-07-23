#include<bits/stdc++.h>
using namespace std;



// majority element  (>n/2 times)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(count==0){
                count++;
                el=nums[i];
            }
            else if(nums[i]==el){
                count++;
            }
            else{
                count--;
            }
        }
        // int c=0;
        // for(int i=0 ; i<nums.size() ; i++){
        //     if(nums[i]==el){c++;}
        // }
        // return (c>(nums.size()/2))?el:-1;
        return el;
    }
};


// cstyle solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algo
        int n = nums.size();
        int res = 0; int count = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i]==nums[res])
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count == 0 )
            {
                count=1;
                res=i;
            }
            
        }
        return nums[res];
    }
};