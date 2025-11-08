#include<bits/stdc++.h>
using namespace std;


// GFG : https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

// my brute solution : accepted
// TC : O( N^2 * log(N) )
// SC : O( N^2 )

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        
        int n = arr.size();
        int m = n*(n+1)/2;
        vector<int> vec(m);

        int p = 0;
        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){
                vec[p] = sum + arr[j] ;
                sum = vec[p];
                p++;
            }
        }

        sort(vec.begin(),vec.end());

        return vec[m-k];

    }
};


// ------------------------------------------------------------ //


// my optimal try : accepted
// TC : O( N^2 * log(k) )
// SC : O( k )

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        
        int n = arr.size();

        priority_queue<int , vector<int> , greater<int> > pq;

        for(int i=0 ; i<n ; i++){
            int sum = 0;
            for(int j=i ; j<n ; j++){

                sum += arr[j];
                pq.push(sum);
                if(pq.size()>k){
                    pq.pop();
                }

            }
        }

        return pq.top();

    }
};






