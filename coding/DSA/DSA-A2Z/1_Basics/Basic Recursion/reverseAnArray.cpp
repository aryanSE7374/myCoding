#include <bits/stdc++.h>
using namespace std;



// to reverse an array we have like 4 solutions


class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n/2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }        
    }
};



class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        func(arr , 0);
    }
    void func(vector<int> &arr , int n){
        if(n>=(arr.size()/2)){
            // int temp = arr[0];
            // arr[0] = arr[arr.size()-1];
            // arr[arr.size()-1] = temp;
            return;
        }
        else{
            int temp = arr[n];
            arr[n] = arr[arr.size()-n-1];
            arr[arr.size()-n-1] = temp;
            func(arr,n+1);
        }
    }
};



//editorial solution

// function to reverse an array
void reverseArray(vector<int> &arr) {
  
    // Initialize left to the beginning and right to the end
    int left = 0, right = arr.size() - 1;
  
    // Iterate till left is less than right
    while(left < right) {
      
        // Swap the elements at left and right position
        swap(arr[left], arr[right]);
      
        // Increment the left pointer
        left++;
      
        // Decrement the right pointer
        right--;
    }
}


//Function to reverse array using recursion
void reverseArray(vector<int> &arr, int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}