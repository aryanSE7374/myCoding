#include<bits/stdc++.h>
using namespace std;

//Sort the array
//Merge Sort

class Solution {
public:

    void merge(vector<int>& arr, int l, int mid , int r){
        vector<int> temp;
        int left = l;
        int right = mid+1;
        while ((left<=mid)&&(right<=r))
        {
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right<=r)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = l ; i <= r ; i++){
            arr[i] = temp[i-l];
        }
    }

    void MS(vector<int>& arr, int l, int r){
        if(l>=r){return;}
        int mid = (l+r)/2;
        MS(arr , l , mid);
        MS(arr , mid+1 , r);
        merge(arr , l , mid ,r);
    }


    vector<int> sortArray(vector<int>& nums) {
        MS(nums,0,nums.size()-1);
        return nums;
    }
};