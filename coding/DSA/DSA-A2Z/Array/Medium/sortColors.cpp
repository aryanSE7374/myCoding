
#include<bits/stdc++.h>
using namespace std;

// my 2 pointer solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        int i=-1, j= -1;
        for (int k = 0; k < nums.size(); k++)
        {
            if(!nums[k]){//==0
                nums[k] = nums[j+1];
                nums[++i] = 0;
                j++;
                if(i<j){
                    nums[j]=1;
                }
            }
            else if(nums[k]==1){ //==1
                nums[k] = nums[j+1];
                nums[++j] = 1;
            }
        }
        
    }
};


// another O(2N) solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0 , c1 = 0 , c2 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(!nums[i]){c0++;}
            else if(nums[i]==1){c1++;}
            else{c2++;}
        }
        for (int i = 0; i < c0; i++)
        {
            nums[i]=0;
        }
        for (int i = c0; i < c0+c1; i++)
        {
            nums[i]=1;
        }
        for (int i = c0+c1; i < nums.size(); i++)
        {
            nums[i]=2;
        }
        
    }
};


// Dutch National flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , mid = 0 , high = n-1;

        while (mid<=high)
        {
            if(!nums[mid]){//==0
                swap(nums[low] , nums[mid]);
                low++;mid++;
            }
            else if(nums[mid]==1){ //==1
                mid++;
            }
            else{ //==2
                swap(nums[mid] , nums[high]);
                high--;
            }
        }   
    }
};