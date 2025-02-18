
#include <bits/stdc++.h>
using namespace std;


// brute force solution

/*
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            set<vector<int>> st;
            for(int i=0 ; i<nums.size() ; i++){
                for(int j=i+1 ; j<nums.size(); j++){
                    for(int k=j+1 ; k<nums.size() ; k++){
                        if(nums[i]+nums[j]+nums[k]==0){
                            vector<int> temp = {nums[i],nums[j],nums[k]};
                            sort(temp.begin() , temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
            for(auto it : st){
                res.push_back(it);
            }
            return res;
        }
    };
*/


// better

/*

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> st;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                set<int> hashset;
                for (int j = i + 1; j < n; j++) {
                    //Calculate the 3rd element:
                    int third = -(nums[i] + nums[j]);

                    //Find the element in the set:
                    if (hashset.find(third) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[j]);
                }
            }

            //store the set in the answer:
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };

*/

// optimal

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            //remove duplicates:
            if (i != 0 && nums[i] == nums[i - 1]) continue;
    
            //moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //skip the duplicates:
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
        }
    };

    //Time Complexity: O(NlogN)+O(N2), where N = size of the array.