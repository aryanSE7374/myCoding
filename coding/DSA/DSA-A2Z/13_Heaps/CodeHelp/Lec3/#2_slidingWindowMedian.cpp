#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        bool isEven = (k%2)==0;

        int n = nums.size();
        // vector<double> ans(n-k+1);
        vector<double> ans;

        vector<int> window(k);

        int l=0;
        // int p=0;
        for(int r=k-1 ; r<n ; r++ ){

            for(int i=0 ; i<k ; i++){
                window[i] = nums[i+l];
            }

            sort(window.begin(),window.end());

            if(isEven){
                ans.push_back(1.0*(window[(k/2) - 1]+ 1.0*window[k/2])/2);
            }
            else{
                ans.push_back(window[k/2]);
            }

            l++;

        }

        return ans;


    }
};


// -------------------------------------------------------------------------------- //

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> result;
    result.reserve(n - k + 1);
    for (int i = 0; i + k <= n; i++) {
        // 1) build window
        vector<int> window(nums.begin() + i, nums.begin() + i + k);
        // 2) sort it
        sort(window.begin(), window.end());
        // 3) compute median
        if (k % 2 == 1) {
            result.push_back((double)window[k/2]);
        } else {
            // even size, median is average of two middle values
            double median = ((double)window[k/2 - 1] + (double)window[k/2]) / 2.0;
            result.push_back(median);
        }
    }
    return result;
}


// -------------------------------------------------------------------------------- //

