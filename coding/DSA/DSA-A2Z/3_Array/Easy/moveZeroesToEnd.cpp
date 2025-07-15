#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0; //count of num of zeroes 
        int li = 0; //index next to the last non-zero num visited
        int n = nums.size();
        int i=0;
        //while loop optimization for some edge cases
        while((i<n)&&(nums[i]!=0)){
            i++;
        }
        li = i;
        for( ; i<n ; i++){
            if(!nums[i]){ //nums[i]==0
                count++;
            }
            else{
                nums[li++]=nums[i];
            }
        }
        for(int i = n-count ; i<n ; i++ ){
            nums[i] = 0;
        }
    }

};


// striver's solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        //place the pointer j:
        for(int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        //no non-zero elements:
        if(j == -1) return;

        //Move the pointers i and j
        //and swap accordingly:
        for(int i = j + 1; i < n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

