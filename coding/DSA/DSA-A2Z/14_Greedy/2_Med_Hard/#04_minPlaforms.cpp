#include<bits/stdc++.h>
using namespace std;


// my greedy try 1 : failed (wrong approach)

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        int ans = 1;
        vector<vector<int>> intervals(n,vector<int>(2));

        for(int i=0 ; i<n ; i++){
            intervals[i][0] = arr[i];
            intervals[i][1] = dep[i];
        }

        sort(intervals.begin() , intervals.end());

        int i=0;
        while(i<n){

            vector<int> temp = {intervals[i][0] , intervals[i][1]};
            i++;
            int platforms = 1;

            while( i<n && intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1] , intervals[i][1]);
                i++;
                platforms++;
            }

            ans = max(ans , platforms);

        }

        return ans;
        
    }
};

// -------------------------------------------------------------------------------- //

// brute solution : TLE

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        int ans = 1;
        
        for(int i=0 ; i<n ; i++){
            int maxPlats = 1;
            for(int j=0 ; j<n ; j++ ){
                // if(intersecting()){}
                if(i==j) continue;
                
                if(
                // ( arr[j]<=arr[i] && arr[i]<=dep[j] && dep[j]<=dep[i] ) ||
                // ( arr[j]<=arr[i] && dep[i]<=dep[j] ) ||
                // ( arr[i]<=arr[j] && arr[j]<=dep[i] && dep[j]<=dep[i] && arr[i]<=dep[j]) ||
                // ( arr[i]<=arr[j] && arr[j]<=dep[i] && dep[i]<=dep[j] ) 

                (  arr[j]<=arr[i] && arr[i]<=dep[j] )
                
                ){
                  maxPlats++;
                }
            }
            ans = max(ans , maxPlats);
        }

        return ans;
        
    }
};

// -------------------------------------------------------------------------------- //


// optimal 2 pointer solution
// TC : O (n)
// SC : O(1)

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        int ans = 1;

        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());

        int i=0 , j=0;

        int cnt = 0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else if(arr[i]>dep[j]){
                cnt--;
                j++;
            }
            ans = max(ans , cnt);

        }

        return ans;

    }
};

// -------------------------------------------------------------------------------- //

// one more method to solve : using minHeap

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], dep[i]};
        }

        // sort by arrival time
        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;

        for (int i = 0; i < n; i++) {
        
            // free platforms for trains that have departed
            while (!pq.empty() && pq.top() < v[i].first) {
                pq.pop();
            }

            // add current train's departure
            pq.push(v[i].second);

            // track maximum platforms used
            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};



// -------------------------------------------------------------------------------- //

// one more method to solve : using Sweep line algorithm
// The Sweep Line Algorithm is an efficient technique for solving interval-based problems.



class Solution {
  public:
    int minPlatform(vector<int> &arr, vector<int>& dep) {

        int n = arr.size();
        int res = 0;

        // Find the max Departure time 
        int maxDep = dep[0];
        for (int i = 1; i < n; i++) {
            maxDep = max(maxDep, dep[i]);
        }
        vector<int> v(maxDep + 2, 0);
        
        // Increment the count at the arrival time and decrement
        // at the departure time
        for (int i = 0; i < n; i++) {
            v[arr[i]]++;
            v[dep[i] + 1]--;
        }
        
        int count = 0;
        
        // Iterate over the vector and keep track of the maximum
        // sum seen so far
        for (int i = 0; i <= maxDep + 1; i++) {
            count += v[i];
            res = max(res, count);
        }
        
        return res;

    }
};


