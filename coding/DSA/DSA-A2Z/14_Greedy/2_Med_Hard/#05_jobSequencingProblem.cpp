#include<bits/stdc++.h>
using namespace std;


// GFG : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// brute try - TLE
// TC : O(n^2)
// SC : O(n)

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        // return num of jobs assigned and max profit 

        int n = deadline.size();
        vector<pair<int , int>> vec(n);

        for(int i=0 ; i<n ; i++){
            vec[i] = {profit[i],deadline[i]};
        }

        sort(vec.rbegin() , vec.rend());

        int maxProfit = 0;
        int assigned = 0;

        // unordered_map<int , int> assignments;
        vector<int> assignments(n+1,0);
        assignments[0]=1;
        // deadline -> profit

        for(int i=0 ; i<n ; i++){

            int pr = vec[i].first;
            int dl = vec[i].second;

            while(assignments[dl]!=0){
                dl--;
            }

            // if(dl>=0){
            if(dl>0 && assignments[dl]==0){
                assignments[dl] = 1;
                assigned++;
                maxProfit += pr;
            }
            
        }

        return {assigned , maxProfit};

    }
};


// the brute solution can be optimized using DSU or even priority_queue as well