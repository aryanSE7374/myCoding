#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if(!n){return 0;}
        // sort(nums.begin() , nums.end());
        // int max_len = 1;
        // int len = 1;
        // for (int i = 0; i <= n-2; i++)
        // {
        //     if (nums[i+1]-nums[i]<=1)
        //     {
        //         len++;
        //         max_len = max(max_len , len);
        //     }
        //     else{
        //         len = 1;
        //     }
        // }
        // return max_len;


        int n = nums.size();
        if(!n){return 0;}
        sort(nums.begin() , nums.end());
        int count = 0 ; // count of elements in the curr seq
        int longest = 1; int last_smaller = INT_MIN; 
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == last_smaller+1){
                count++;
                last_smaller = nums[i];
            }
            else if(nums[i] != last_smaller){
                last_smaller = nums[i];
                count = 1;
            }
            longest = max(longest , count);
            // else{  } // nums[i] == last_smaller : ignore
        }
        return longest;


    }
};


// optimal solution without modifying the original array

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;

        // Insert all elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        // Check for the longest consecutive sequence
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) { // Starting point of a sequence
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};