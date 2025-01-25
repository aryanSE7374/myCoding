#include<bits/stdc++.h>
using namespace std;


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


void mergeSort(vector<int>& arr, int l, int r) {
    MS(arr,0,arr.size()-1);
}

// leetcode merge sort

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

int main(){
    return 0;
}

/*
// Function to merge two sorted subarrays into a single sorted subarray
// Parameters:
// - arr: The input array
// - l: The starting index of the first subarray
// - mid: The ending index of the first subarray
// - r: The ending index of the second subarray
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp; // Temporary vector to store merged elements
    int left = l;     // Pointer to the start of the first subarray
    int right = mid + 1; // Pointer to the start of the second subarray

    // Merge elements from both subarrays into temp in sorted order
    while ((left <= mid) && (right <= r)) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]); // Take element from the left subarray
            left++;
        } else {
            temp.push_back(arr[right]); // Take element from the right subarray
            right++;
        }
    }

    // Add any remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Add any remaining elements from the right subarray
    while (right <= r) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements from temp back to the original array
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l]; // Adjust index to match the original array
    }
}

// Recursive function to divide the array into subarrays and sort them
// Parameters:
// - arr: The input array
// - l: The starting index of the current subarray
// - r: The ending index of the current subarray
void MS(vector<int>& arr, int l, int r) {
    if (l >= r) return; // Base case: A single element or an empty subarray is already sorted

    int mid = (l + r) / 2; // Calculate the middle index to divide the array

    // Recursively sort the left subarray
    MS(arr, l, mid);

    // Recursively sort the right subarray
    MS(arr, mid + 1, r);

    // Merge the two sorted subarrays
    merge(arr, l, mid, r);
}

// Wrapper function to initiate merge sort on the entire array
// Parameters:
// - arr: The input array
// - l, r: These parameters are not used; they can be ignored
void mergeSort(vector<int>& arr, int l, int r) {
    MS(arr, 0, arr.size() - 1); // Start the recursive sorting process on the entire array
}

*/