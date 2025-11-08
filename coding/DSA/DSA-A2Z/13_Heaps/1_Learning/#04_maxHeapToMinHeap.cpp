#include<bits/stdc++.h>
using namespace std;


// try : failed
class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        priority_queue< int  > pq(arr.begin() , arr.end());
        int i=0;
        while(!pq.empty()){
            arr[i] = pq.top();
            pq.pop();
            i++;
        }
    }
};
