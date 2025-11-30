#include<bits/stdc++.h>
using namespace std;


// my greedy try 1 - same as striver's editorial
// GFG : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    
    int maxMeetings(vector<int>& start, vector<int>& end) {

        int n = start.size();
        
        vector<pair<int,int>> vec(n); // end , start
        
        for(int i=0 ; i<n ; i++){
            vec[i] = {end[i] , start[i]};
        }
        
        sort(vec.begin() , vec.end());
        
        int meetings = 0;
        
        int last_meet = -1;
        
        for(int i=0 ; i<n ; i++){
            if(vec[i].second > last_meet){
                meetings++;
                last_meet = vec[i].first;
            }
        }
        
        return meetings;
        
    }
};


