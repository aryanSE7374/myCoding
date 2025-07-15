#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // quickSort(arr, 0, arr.size() - 1);
        if(low<high){
            int pIdx = partition(arr , low , high);
            quickSort(arr , low , pIdx-1);
            quickSort(arr , pIdx+1 , high);
        }
        
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low ; int j = high;
        while(i<j){
            while((arr[i]<=pivot)&&(i<=high-1)){
                i++;
            }
            while((arr[j]>pivot)&&(j>=low+1)){
                j--;
            }
            if(i<j){
                swap( arr[i], arr[j]);
            }
        }
        swap(arr[low] , arr[j]);
        return j;
    }

    // selecting the last lement as pivot
    /*
    int partition(vector<int>& arr, int low, int high) {



        int pivot = arr[high]; // Set the pivot as the last element
        int i = low;           // Pointer for left side
        int j = high - 1;      // Pointer for right side (before the pivot)

        while (i <= j) {       // Continue until pointers cross
            while ((arr[i] <= pivot) && (i <= high - 1)) { 
                i++;           // Move `i` right while elements are smaller than or equal to pivot
            }
            while ((arr[j] > pivot) && (j >= low)) {
                j--;           // Move `j` left while elements are greater than pivot
            }
            if (i < j) {       // Swap out-of-place elements
                swap(arr[i], arr[j]);
            }
        }
        // Place the pivot at its correct position
        swap(arr[i], arr[high]);
        return i;             // Return the partition index
    }
    */
};



// best sorting solution
vector<int> sortArray(vector<int>& nums) {
    if (nums.empty()) return nums;
    
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    
    vector<int> count(max - min + 1, 0);
    for (int num : nums) {
        count[num - min]++;
    }
    
    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i]-- > 0) {
            nums[index++] = i + min;
        }
    }
    
    return nums;
}



