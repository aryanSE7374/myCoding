#include <bits/stdc++.h>
using namespace std;


// floor in a sorted array
class Solution {
    public:

        int findFloor(vector<int>& arr, int k) {
            int n = arr.size();
            if(k<arr[0]){return -1;}
            else if(arr[n-1]<=k){return n-1;}
            int low=0;
            int high=n-1;
            int ans = (low+high)/2;
            int mid=(low+high)/2;
            while(low<=high){
                mid=(low+high)/2;
                if(arr[mid]<=k){
                    low=mid+1;
                    ans=mid;
                }
                else{ // arr[mid]>k
                    high=mid-1;
                }
            }
            return ans;
        }
};

