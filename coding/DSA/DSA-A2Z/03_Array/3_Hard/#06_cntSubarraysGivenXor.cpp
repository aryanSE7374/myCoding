// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include<bits/stdc++.h>
using namespace std;


// my optimal solution

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int XOR = 0;
        
        unordered_map<int, int> prefXorCnt;
        int cnt = 0;
        
        for ( int i=0; i<n; i++ ) {
            XOR ^= arr[i];
            if ( XOR == k ) cnt++;
            if (prefXorCnt.find(XOR^k) != prefXorCnt.end()) {
                cnt += prefXorCnt[XOR^k];
            }
            prefXorCnt[XOR]++;
        }
        
        return cnt;
        
    }
};


// my sol 2 : better

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int XOR = 0;
        
        unordered_map<int, int> prefXorCnt;
        prefXorCnt[XOR]++;
        int cnt = 0;
        
        for ( int i=0; i<n; i++ ) {
            XOR ^= arr[i];
            if (prefXorCnt.find(XOR^k) != prefXorCnt.end()) {
                cnt += prefXorCnt[XOR^k];
            }
            prefXorCnt[XOR]++;
        }
        
        return cnt;
        
    }
};