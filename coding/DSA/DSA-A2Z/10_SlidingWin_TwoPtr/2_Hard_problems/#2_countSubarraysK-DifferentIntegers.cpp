#include<bits/stdc++.h>
using namespace std;

// brute solution
// produces TLE

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // unordered_map<int , int> freq;
        int n = nums.size();
        int count = 0;

        for(int i=0 ; i<n ; i++){
            unordered_map<int , int> subArrFreq;
            for(int j=i ; j<n ; j++){
                subArrFreq[nums[j]]++;
                if(subArrFreq.size()==k){
                    count++;
                }
            }
        }
        return count;
    }
};


// my optimal sol try : using sliding-window / two-pointers


// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         unordered_map<int , int> freq;
//         int n = nums.size();
//         int l=0 , r=0 ,count = 0;

//         while(r<n){
//             freq[nums[r]]++;
//             while (freq.size()>k)
//             {
//                 freq[nums[l]]--;
//                 if(freq[nums[l]]==0){freq.erase(nums[l]);}
//                 l++;
//             }
//             count += (r-l+1);
//             r++;
//         }
//         return count;
//     }
// };

// TC : O(2N)
// SC : O(N) 

class Solution {
public:
    int atMostK(vector<int>& nums, int k){
        if(k==0){return 0;}
        unordered_map<int , int> freq;
        int n = nums.size();
        int l=0 , r=0 ,count = 0;

        while(r<n){
            freq[nums[r]]++;
            while (freq.size()>k)
            {
                freq[nums[l]]--;
                if(freq[nums[l]]==0){freq.erase(nums[l]);}
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums , k) - atMostK(nums , k-1);
    }
};
