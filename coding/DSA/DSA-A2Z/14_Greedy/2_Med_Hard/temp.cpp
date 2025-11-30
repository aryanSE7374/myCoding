#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int i=0;
        vector<int> vec;

        while(i<n-1){

            int count = 1;

            while(i<n-1 && nums[i]==nums[i+1]){

                count++;
                i++;

            }

            vec.push_back(count);

            i++;

        }

        // if(nums[n-2]==nums[n-1]) vec.back()++;

        // else vec.push_back(1);

        if(nums[n-2] != nums[n-1]) vec.push_back(1);

        int ans = 0;

        int m = vec.size();

        if(m == 1) return 0;

        for(int i=0 ; i<m-1 ; i++){
            ans = max( ans , 2 * min( vec[i] , vec[i+1] ) );
        }

        return ans;


    }
};


// ---------------------------------------------------------------------------------------- //

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0) nums[i] = -1;
        }

        int sum = 0;
        int ans = 0;

        int l=0 , r=0 ; 

        while (r<n) {

            sum += nums[r];

            if(sum < 0){
                r++;
            }
            else if(sum > 0){
                l++;
            }
            else{
                ans = max(ans , r-l+1);
            }

            r++;
        }

        return ans;

    }
};