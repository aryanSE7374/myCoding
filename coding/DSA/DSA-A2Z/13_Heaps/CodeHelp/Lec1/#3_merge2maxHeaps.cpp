#include<bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// User function Template for C++


class Solution {
  public:
  
      void heapify(vector<int> &arr, int n, int i) {
          
        int largest = i;           // Initialize largest as root
        int left = 2 * i + 1;      // Left child index
        int right = 2 * i + 2;     // Right child index
    
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;
    
        // If right child is larger than the current largest
        if (right < n && arr[right] > arr[largest])
            largest = right;
    
        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
        
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here

        /* // better practice

        vector<int> c;
        c.reserve(m + n);
        c.insert(c.end(), a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());

        */

        vector<int> c(m+n,0);
        for(int i = 0 ; i<n ; i++ ){
            c[i] = a[i];
        }
        for(int i = 0 ; i<m ; i++ ){
            c[n+i] = b[i];
        }
        for (int i = (m+n) / 2 - 1; i >= 0; i--) {
            heapify(c , (m+n) , i);
        }
        return c;
        
    }
};