#include<bits/stdc++.h>
using namespace std;


// same as N meetings prob on GFG

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<pair<int,int>> vec(n); // end , start
        
        for(int i=0 ; i<n ; i++){
            vec[i] = {intervals[i][1] , intervals[i][0]};
        }
        
        sort(vec.begin() , vec.end());
        
        int meetings = 0;
        
        int last_meet = INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            if(vec[i].second >= last_meet){
                meetings++;
                last_meet = vec[i].first;
            }
        }
        
        return n-meetings;
        
    }
};


// sol2 - better and different approach

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){
                 return a[1] < b[1];
             });

        int removed = 0;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < lastEnd){
                removed++;            // overlapping → remove this interval
            } else {
                lastEnd = intervals[i][1];   // non-overlapping → keep it
            }
        }
 
        return removed;
    }
};
