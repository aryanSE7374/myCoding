#include<bits/stdc++.h>
using namespace std;


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> vec;
        int maxi = INT_MIN;
        for (int i = n-1; i >= 0; i--)
        {
            if (arr[i]>maxi)
            {
                vec.push_back(arr[i]);
            }
            maxi = max(maxi , arr[i]);
            
        }
        reverse(vec.begin() , vec.end());
        return vec;
    }
};