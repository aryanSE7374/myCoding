#include<bits/stdc++.h>
using namespace std;


// my greedy try 1 : accepted

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;

        int n = intervals.size();

        // if (n==0) return {newInterval};

        sort(intervals.begin() , intervals.end());

        int i=0;
        while(i<n){

            vector<int> temp = {intervals[i][0] , intervals[i][1]};
            i++;

            while( i<n && intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1] , intervals[i][1]);
                i++;
            }

            ans.push_back(temp);

        }

        return ans;

    }
};