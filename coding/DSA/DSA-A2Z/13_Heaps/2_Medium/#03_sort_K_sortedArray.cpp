#include<bits/stdc++.h>
using namespace std;


// optimal solution

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue< int , vector<int> , greater<int> > minHeap;
        for(int i=0 ; i<=k ; i++){
            minHeap.push(arr[i]);
        }

        
        // arr[0] = minHeap.top();
        // minHeap.pop();
        // minHeap.push(arr[k]);
        
        int l=0 , r=k+1 ;

        while(r<n){
            arr[l] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[r]);
            l++;
            r++;
        }

        while(!minHeap.empty()){
            arr[l] = minHeap.top();
            minHeap.pop();
            l++;
        }
        
    }
};