#include<bits/stdc++.h>
using namespace std;


// my try 1 : idea refined by chatGPT

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        if (n == 0) return {newInterval};

        vector<vector<int>> ans;

        if(intervals[0][0]>=newInterval[0] && intervals[n-1][1]<=newInterval[1] ){
            ans.push_back({newInterval[0] , newInterval[1]});
            return ans;
        }

        int start_idx = -1;
        int end_idx = -1;

        // for(int i=0 ; i<n ; i++){
        //     if( start_idx==-1 && intervals[i][0]<=newInterval[0] && newInterval[0]<=intervals[i][1]){
        //         start_idx = i;
        //         end_idx = i;
        //         if(intervals[i][0]<=newInterval[1] && newInterval[1]<=intervals[i][1]){
        //             end_idx = i;
        //             break;
        //         }
        //     }
        //     if(end_idx==start_idx && intervals[i][0]<=newInterval[1] && newInterval[1]<=intervals[i][1]){
        //         end_idx = i;
        //         break;
        //     }
        // }

        for(int i=0 ; i<n ; i++){

            // If NOT (interval.end < new.start OR interval.start > new.end)
            if(!(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])){

                // First overlapping interval
                if (start_idx == -1)
                    start_idx = i;

                // Last overlapping interval
                end_idx = i;
            }
        }

        if(start_idx == -1 || end_idx == -1) { 
            ans = intervals;
            ans.push_back(newInterval);
            sort(ans.begin() , ans.end());
            return ans;
        }

        for(int i=0 ; i<start_idx ; i++){
            ans.push_back(intervals[i]);
        }

        ans.push_back({min(intervals[start_idx][0] , newInterval[0]) ,max(intervals[end_idx][1] , newInterval[1])} );

        for(int i=end_idx+1 ; i<n ; i++){
            ans.push_back(intervals[i]);
        }

        return ans;

    }
};

// ------------------------------------------------------------------------------------------------------------------------------ //

// striver's solution : same as GPT

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;

        int n = intervals.size();

        if (n==0) return {newInterval};

        int i=0;
        while (i<n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;

    }
};



// ------------------------------------------------------------------------------------------------------------------------------ //


// GPT solution 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


        int n = intervals.size();

        if (n==0) return {newInterval};

        vector<vector<int>> ans;

        int i = 0;

        // add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // add the rest
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;

    }
};


// ------------------------------------------------------------------------------------------------------------------------------ //