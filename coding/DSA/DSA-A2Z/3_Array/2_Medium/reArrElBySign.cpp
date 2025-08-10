#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        

        //optimal
        //-----------------------------------------

        int n = nums.size();
        vector<int> vec(n , 0);
        int pos = 0; int neg = 1;
        for(int i=0 ; i<n ; i++){
            if(nums[i]>0){
                vec[pos]=nums[i];
                pos+=2;
            }
            else{
                vec[neg]=nums[i];
                neg+=2;
            }
        }
        return vec;

        // another way o trversing is from 0 ton n/2 and using 2*i : pos ,  and 2*i + 1 : neg



        //-----------------------------------------

        //wrong approach
        // int l = 0 , r = 0;
        // int n = nums.size();
        // while(l<n && r<n){
        //     r++;
        //     if(nums[l]*nums[r]<0){
        //         swap(nums[l+1],nums[r]);
        //         l+=2;
        //         r=l;
        //     }
        // }
        // if((nums[0]>0)){
        //     return nums;
        // }
        // else{
        //     reverse(nums.begin() , nums.end());
        //     return nums;
        // }
    }
};

// another way o trversing is from 0 ton n/2 and using 2*i : pos ,  and 2*i + 1 : neg

vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}