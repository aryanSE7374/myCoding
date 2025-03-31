#include<bits/stdc++.h>
using namespace std;


// Naive Soln 1 : fails on inputs where answer is beyond range (mini , maxi) , eg : nums=[21212,10101,12121] , thresh=1000000

class Solution {
    public:
        bool isLessThanThresold(vector<int>& nums , int divisor , int threshold){
            int n = nums.size();
            int sum = 0;
            for(int i=0 ; i<n ; i++){
                sum = sum + ceil((double)nums[i]/(double)divisor);
            }
            return sum<=threshold;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int mini = *min_element(nums.begin(), nums.end());
            int maxi = *max_element(nums.begin(), nums.end());
            for (int divisor = mini ; divisor <= maxi ; divisor++) {
                if(isLessThanThresold(nums , divisor , threshold)){
                    return divisor;
                }
            }
            return -1;
        }
    };


// Naive Soln 2 : passes the edge cases but Prodcues TLE

class Solution {
    public:
        bool isLessThanThresold(vector<int>& nums , int divisor , int threshold){
            int n = nums.size();
            int sum = 0;
            for(int i=0 ; i<n ; i++){
                sum = sum + ceil((double)nums[i]/(double)divisor);
            }
            return sum<=threshold;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int mini = *min_element(nums.begin(), nums.end());
            int maxi = *max_element(nums.begin(), nums.end());
            for (int divisor = 1 ; divisor <= maxi ; divisor++) {
                if(isLessThanThresold(nums , divisor , threshold)){
                    return divisor;
                }
            }
            return -1; // to check cases where we've got a wrong answer
        }
    };



// Optimal Soln

class Solution {
    public:
        bool isLessThanThresold(vector<int>& nums , int divisor , int threshold){
            int n = nums.size();
            int sum = 0;
            for(int i=0 ; i<n ; i++){
                sum = sum + ceil((double)nums[i]/(double)divisor);
            }
            return sum<=threshold;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            // int mini = *min_element(nums.begin(), nums.end());
            /*
            // optimization if there might be no such divisor exists : 
            if(nums.size()>threshold){return -1;} // indicating no solution
            */
            int maxi = *max_element(nums.begin(), nums.end());
            int low = 1 , high = maxi ;
            while(low <= high){
                int mid = (low + high)/2;
                if(isLessThanThresold(nums , mid , threshold)){high = mid-1;}
                else{low = mid + 1;}
            }
            return low;
            // for (int divisor = 1 ; divisor <= maxi ; divisor++) {
            //     if(isLessThanThresold(nums , divisor , threshold)){
            //         return divisor;
            //     }
            // }
            // return -1;
        }
    };


