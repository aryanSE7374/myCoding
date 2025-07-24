#include<bits/stdc++.h>
using namespace std;


// leetcode variation
// https://leetcode.com/problems/next-greater-element-i/


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> nge(n1);
//         for(int i=0 ; i< n1 ; i++){
//             for(int j=i+1 ; j<n2 ; j++){
//                 if(nums1[i]<nums2[j]){nge[i] = nums2[j];break;}
//             }
//             nge[i]=-1;
//         }
//         return nge;
//     }
// };


// brute

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;

        for (int num : nums1) {
            // Find the index of num in nums2
            int index = -1;
            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == num) {
                    index = i;
                    break;
                }
            }

            // Search to the right of that index
            int nextGreater = -1;
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > num) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            nge.push_back(nextGreater);
        }

        return nge;
    }
};



// optimal
// Optimal Approach (Stack + Hash Map):
// 1.	Use a monotonic decreasing stack on nums2 to precompute next greater elements.
// 2.	Store the results in a hashmap: {value → nextGreater}
// 3.	For each num in nums1, return the mapped value (or -1 if not present).


// Time: O(n + m) → n = size of nums2, m = size of nums1
// Space: O(n) for map + stack




class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; // value → next greater element
        stack<int> st;

        // Build the map for nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                ngeMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Build the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap.count(num) ? ngeMap[num] : -1);
        }
        return result;
    }
};